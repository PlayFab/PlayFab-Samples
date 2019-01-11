using PlayFab.MultiplayerModels;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Client
{
    public partial class frmMain : Form
    {
        private PlayFabMultiplayerServerHelper m_PlayfabCompute = new PlayFabMultiplayerServerHelper();

        // This is used to cache the build ID when the user navigates tab, incase the user changes the selection in the gridview.
        private static string g_VMOperations_CurrentBuildID = String.Empty;
        private static string g_ServerOperations_CurrentBuildID = String.Empty;

        public frmMain()
        {
            InitializeComponent();
        }

        void LogMessage(string strMessage, params object[] stringParams)
        {
            lstConsole.Items.Insert(0, String.Format(strMessage, stringParams));
        }

        private void btnAuth_Click(object sender, EventArgs e)
        {
            LogMessage("Attempting to auth");

            PlayFab.PlayFabSettings.TitleId = txtTitleID.Text;
            PlayFab.PlayFabSettings.DeveloperSecretKey = txtSecret.Text;

            // NOTE: In the real world, don't store this on your client
            m_PlayfabCompute.GetTitleEntityToken().ContinueWith((task) =>
            {
                LogMessage("Auth {0}", task.Result ? "succeeded" : "failed");

                if (task.Result)
                {
                    // Check the title is provisioned for Compute
                    m_PlayfabCompute.IsTitleProvisioned().ContinueWith((provisioningTask) =>
                    {
                        if (provisioningTask.Result)
                        {
                            btnQueryBuilds.Enabled = task.Result;
                            btnUploadNewBuild.Enabled = task.Result;
                        }
                        else
                        {
                            LogMessage("ERROR: PlayFab Multiplayer is not enabled for this title");

                            DialogResult dResult = MessageBox.Show("PlayFab Multiplayer is not enabled for this title.\n\nWould you like to enable it now?", "PlayFay Multiplayer Disabled", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                            if (dResult == DialogResult.Yes)
                            {
                                m_PlayfabCompute.ProvisionTitle().ContinueWith((enableTask) =>
                                {
                                    MessageBox.Show("PlayFab Multiplayer is now enabled!", "PlayFay Multiplayer Enabled", MessageBoxButtons.OK, MessageBoxIcon.Information);
                                });
                            }
                        }
                    });
                }
            }, TaskScheduler.FromCurrentSynchronizationContext());
        }

        private void btnQueryBuilds_Click(object sender, EventArgs e)
        {
            gridViewSessions.Rows.Clear();

            btnAllocate.Enabled = false;
            btnRDPVM.Enabled = false;
            btnQueryServers.Enabled = false;
            btnQueryVMS.Enabled = false;
            btnConnectClient.Enabled = false;
            btnRDP.Enabled = false;

            gridViewBuilds.Enabled = false;
            gridViewSessions.Enabled = false;

            LogMessage("Querying builds");
            m_PlayfabCompute.QueryBuilds().ContinueWith((task) =>
            {
                gridViewBuilds.Enabled = true;
                gridViewSessions.Enabled = true;

                gridViewBuilds.Rows.Clear();

                List<BuildSummary> result = task.Result;

                LogMessage("Found {0} builds", result.Count);
                for (int i = 0; i < result.Count; ++i)
                {
                    var thisBuild = result[i];

                    string[] newRow = new string[]
                    {
                        thisBuild.BuildId,
                        thisBuild.BuildName
                    };
                    gridViewBuilds.Rows.Add(newRow);
                }

                btnAllocate.Enabled = true;
                btnRDPVM.Enabled = true;
                btnQueryServers.Enabled = true;
                btnQueryVMS.Enabled = true;
                btnConnectClient.Enabled = true;
                btnRDP.Enabled = true;

                gridViewBuilds.Sort(gridViewBuilds.Columns[0], ListSortDirection.Descending);

                SelectFirstRowHelper(gridViewBuilds);

            }, TaskScheduler.FromCurrentSynchronizationContext());
        }

        private void SelectFirstRowHelper(DataGridView grid)
        {
            for (int i = 0; i < grid.Rows.Count; ++i) { grid.Rows[i].Selected = (i == 0); }
        }

        private AzureRegion StringToAzureRegion(string strRegion)
        {
            return (AzureRegion)Enum.Parse(typeof(AzureRegion), strRegion);
        }

        private AzureRegion GetCurrentAzureRegion()
        {
            return StringToAzureRegion(cmbRegion.Text);
        }

        private void btnAllocate_Click(object sender, EventArgs e)
        {
            string buildID = gridViewBuilds.SelectedRows[0].Cells[0].Value.ToString();
            LogMessage("Attempting to allocate {0}", buildID);

            List<AzureRegion> regions = new List<AzureRegion>();
            foreach (var checkedItem in chkAllocationRegions.CheckedItems)
            {
                regions.Add(StringToAzureRegion(checkedItem.ToString()));
            }

            try
            {
                m_PlayfabCompute.RequestMultiplayerServer(buildID, regions, txtSessionCookie.Text, txtSessionID.Text).ContinueWith((task) =>
                {
                    RequestMultiplayerServerResponse allocRes = task.Result;

                    if (allocRes != null)
                    {
                        LogMessage("\t ");
                        foreach (var port in allocRes.Ports)
                        {
                            LogMessage("\t\t {0} - {1} - {2}", port.Name, port.Num, port.Protocol);
                        }
                        LogMessage("\tPorts:");

                        LogMessage("\tIPv4: {0}", allocRes.IPV4Address == null ? "none" : allocRes.IPV4Address);

                        LogMessage("\tRegion: {0}", allocRes.Region);
                        LogMessage("\tState: {0}", allocRes.State);
                        LogMessage("\tSessionID: {0}", allocRes.SessionId);
                        LogMessage("\tServerID: {0}", allocRes.ServerId);
                        LogMessage("\tVM ID: {0}", allocRes.VmId);


                        LogMessage("Allocation Succeeded:", task.Result);
                    }
                }, TaskScheduler.FromCurrentSynchronizationContext());
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error Occured", MessageBoxButtons.OK);
            }
        }

        private void btnQueryServers_Click(object sender, EventArgs e)
        {
            if (gridViewBuilds.SelectedRows.Count > 0)
            {
                g_ServerOperations_CurrentBuildID = gridViewBuilds.SelectedRows[0].Cells[0].Value.ToString();

                gridViewSessions.Rows.Clear();

                LogMessage("Querying sessions for {0}", gridViewBuilds.SelectedRows[0].Cells[1].Value.ToString());

                m_PlayfabCompute.QueryMultiplayerServers(g_ServerOperations_CurrentBuildID, GetCurrentAzureRegion()).ContinueWith((task) =>
                {
                    List<MultiplayerServerSummary> result = task.Result;
                    LogMessage("Found {0} sessions", result.Count);

                    for (int i = 0; i < result.Count; ++i)
                    {
                        var thisSession = result[i];

                        string[] newRow = new string[]
                        {
                            thisSession.ServerId,
                            thisSession.VmId,
                            thisSession.Region.ToString(),
                            thisSession.State.ToString(),
                        };
                        gridViewSessions.Rows.Add(newRow);
                    }

                    SelectFirstRowHelper(gridViewSessions);
                    lblSessions_Click(lblSessions, e);

                }, TaskScheduler.FromCurrentSynchronizationContext());
            }
        }

        private void btnConnectClient_Click(object sender, EventArgs e)
        {
            if (gridViewSessions.SelectedRows.Count > 0)
            {
                try
                {
                    m_PlayfabCompute.GetMultiplayerServerStatus(g_ServerOperations_CurrentBuildID, txtSessionID.Text).ContinueWith((task) =>
                    {
                        var sessionStatus = task.Result;
                        string ipv4addr = sessionStatus.IPV4Address;

                        // Look for the game port
                        int PortToUse = -1;
                        foreach (var port in sessionStatus.Ports)
                        {
                            if (port.Name.ToLower() == "game")
                            {
                                PortToUse = port.Num;
                                break;
                            }
                        }

                        if (PortToUse != -1)
                        {
                            Process clientProc = new Process();
                            clientProc.StartInfo.FileName = "SimpleServerFab_Client.exe";
                            clientProc.StartInfo.Arguments = String.Format("{0} {1}", ipv4addr, PortToUse);
                            clientProc.Start();
                        }
                        else
                        {
                            LogMessage("Port configuration is incorrect");
                        }
                    }, TaskScheduler.FromCurrentSynchronizationContext());
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Error Occured", MessageBoxButtons.OK);
                }

            }
        }

        private void RDPToVM(string buildID, string VMID)
        {
            LogMessage("Requesting RDP information");
            m_PlayfabCompute.CreateRDPCredentials(buildID, GetCurrentAzureRegion(), VMID).ContinueWith((task) =>
            {
                LogMessage("Retrieved RDP Information");
                ProcessRDPFile(task.Result);
            }, TaskScheduler.FromCurrentSynchronizationContext());
        }

        private void ProcessRDPFile(PlayFabMultiplayerServerHelper.RDPInformation rdpInfo)
        {
            string[] strFileContents = new string[]
            {
                String.Format("full address:s:{0}:{1}", rdpInfo.Address, rdpInfo.Port),
                "prompt for credentials:i:1",
                String.Format("username:s:{0}", rdpInfo.Username),
            };

            Clipboard.SetText(rdpInfo.Password);
            LogMessage("RDP password has been copied to your clipboard");

            // Delete old file if exists
            try
            {
                const string RDPFilename = "playfab.rdp";
                if (File.Exists(RDPFilename))
                {
                    File.Delete(RDPFilename);
                }
                File.WriteAllLines(RDPFilename, strFileContents);

                Process mstscProc = new Process();
                mstscProc.StartInfo.FileName = "mstsc.exe";
                mstscProc.StartInfo.Arguments = RDPFilename;
                mstscProc.Start();
            }
            catch
            {
                MessageBox.Show("Could not create RDP file. Check MSTSC is not running", "Error");
            }


        }

        private void btnGenerateSessionID_Click(object sender, EventArgs e)
        {
            txtSessionID.Text = Guid.NewGuid().ToString();
            LogMessage(String.Format("Generated new Session ID: {0}", txtSessionID.Text));
        }

        private void btnCopySessionID_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(txtSessionID.Text);
            LogMessage("Session ID has been copied to your clipboard");
        }

        private void btnUploadNewBuild_Click(object sender, EventArgs e)
        {
            frmCreateBuild formCreateBuild = new frmCreateBuild();
            formCreateBuild.Show(this);
        }

        private void btnQueryVMS_Click(object sender, EventArgs e)
        {
            if (gridViewBuilds.SelectedRows.Count > 0)
            {
                g_VMOperations_CurrentBuildID = gridViewBuilds.SelectedRows[0].Cells[0].Value.ToString();

                gridVMs.Rows.Clear();

                LogMessage("Querying VMs for {0}", gridViewBuilds.SelectedRows[0].Cells[1].Value.ToString());

                m_PlayfabCompute.QueryVMs(g_VMOperations_CurrentBuildID, GetCurrentAzureRegion()).ContinueWith((task) =>
                {
                    List<VirtualMachineSummary> result = task.Result;
                    LogMessage("Found {0} VMs", result.Count);

                    for (int i = 0; i < result.Count; ++i)
                    {
                        var thisVM = result[i];

                        string[] newRow = new string[]
                        {
                            thisVM.VmId,
                            thisVM.State.ToString()
                        };
                        gridVMs.Rows.Add(newRow);
                    }

                    SelectFirstRowHelper(gridVMs);
                    lblVMs_Click(lblVMs, e);

                }, TaskScheduler.FromCurrentSynchronizationContext());
            }
        }

        private void frmMain_Load(object sender, EventArgs e)
        {
            foreach (var region in Enum.GetValues(typeof(AzureRegion)))
            {
                cmbRegion.Items.Add(region.ToString());
                chkAllocationRegions.Items.Add(region.ToString());
            }

            cmbRegion.SelectedIndex = 0;
        }

        private void btnRDPVM_Click(object sender, EventArgs e)
        {
            string VMID = gridVMs.SelectedRows[0].Cells[0].Value.ToString();
            RDPToVM(g_VMOperations_CurrentBuildID, VMID);
        }

        private void btnRDP_Click(object sender, EventArgs e)
        {
            string VMID = gridViewSessions.SelectedRows[0].Cells[1].Value.ToString();
            RDPToVM(g_ServerOperations_CurrentBuildID, VMID);
        }

        private void lblBuilds_Click(object sender, EventArgs e)
        {
            SetActiveButton((Label)sender);
            tabControl1.SelectTab(0);
        }

        private void lblSessions_Click(object sender, EventArgs e)
        {
            SetActiveButton((Label)sender);
            tabControl1.SelectTab(1);
        }

        private void lblVMs_Click(object sender, EventArgs e)
        {
            SetActiveButton((Label)sender);
            tabControl1.SelectTab(2);
        }

        private void SetActiveButton(Label source)
        {
            if (source != lblBuilds)
            {
                lblBuilds.ForeColor = System.Drawing.Color.Gray;
            }

            if (source != lblSessions)
            {
                lblSessions.ForeColor = System.Drawing.Color.Gray;
            }

            if (source != lblVMs)
            {
                lblVMs.ForeColor = System.Drawing.Color.Gray;
            }

            source.ForeColor = System.Drawing.Color.Silver;
        }
    }
}
