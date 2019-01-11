using PlayFab.MultiplayerModels;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Windows.Forms;

namespace Client
{
    public partial class frmCreateBuild : Form
    {
        public frmCreateBuild()
        {
            InitializeComponent();
        }

        private void frmCreateBuild_Load(object sender, EventArgs e)
        {
            // populate container flavors
            foreach (var flavor in Enum.GetValues(typeof(ContainerFlavor)))
            {
                cmbContainerFlavor.Items.Add(flavor.ToString());
            }

            // populate Azure VMs
            foreach (var azureVMType in Enum.GetValues(typeof(AzureVmSize)))
            {
                cmbAzureVMs.Items.Add(azureVMType.ToString());
            }
        }

        private void gridviewRegionConfig_UserAddedRow(object sender, DataGridViewRowEventArgs e)
        {
            // populate azure regions
            foreach (var region in Enum.GetValues(typeof(AzureRegion)))
            {
                ((DataGridViewComboBoxCell)(gridviewRegionConfig.Rows[e.Row.Index - 1].Cells[0])).Items.Add(region.ToString());
            }
        }

        private async void btnDeploy_Click(object sender, EventArgs e)
        {
            Dictionary<string, string> dictAssetNames = new Dictionary<string, string>();

            try
            {
                foreach (DataGridViewRow row in gridviewAssets.Rows)
                {
                    if (!row.IsNewRow)
                    {
                        string strPath = row.Cells[0].Value.ToString();
                        string strAssetName = await PlayFabMultiplayerServerHelper.Singleton.UploadAsset(strPath, new Dictionary<string, string>());
                        if (strAssetName != null)
                        {
                            dictAssetNames.Add(strPath, strAssetName);
                        }
                        else
                        {
                            MessageBox.Show("Failed to upload asset");
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error Occured", MessageBoxButtons.OK);
            }

            if (dictAssetNames.Count > 0)
            {

                List<AssetReferenceParams> lstGameAssets = new List<AssetReferenceParams>();
                foreach (var keyValuePair in dictAssetNames)
                {
                    // Get mount path from grid view
                    DataGridViewRow row = gridviewAssets.Rows.Cast<DataGridViewRow>().Where(r => r.Cells[0].Value.ToString().Equals(keyValuePair.Key)).First();

                    if (row != null)
                    {
                        var assetRefParams = new AssetReferenceParams() { FileName = keyValuePair.Value, MountPath = row.Cells[1].Value.ToString() };
                        lstGameAssets.Add(assetRefParams);
                    }
                }

                List<Port> lstPorts = new List<Port>();
                foreach (DataGridViewRow row in gridviewPorts.Rows)
                {
                    if (!row.IsNewRow)
                    {
                        string strPortName = row.Cells[0].Value.ToString();

                        int portNumber = -1;
                        if (int.TryParse(row.Cells[1].Value.ToString(), out portNumber))
                        {
                            ProtocolType protoType = (ProtocolType)Enum.Parse(typeof(ProtocolType), row.Cells[2].Value.ToString());
                            lstPorts.Add(new Port { Name = strPortName, Num = portNumber, Protocol = protoType });
                        }
                        else
                        {
                            MessageBox.Show("Invalid port number.");
                        }
                    }
                }

                List<BuildRegionParams> lstRegions = new List<BuildRegionParams>();

                foreach (DataGridViewRow row in gridviewRegionConfig.Rows)
                {
                    if (!row.IsNewRow)
                    {
                        AzureRegion region = (AzureRegion)Enum.Parse(typeof(AzureRegion), row.Cells[0].Value.ToString());
                        int numSessions;
                        int numStandingBy;
                        if (int.TryParse(row.Cells[1].Value.ToString(), out numSessions))
                        {
                            if (int.TryParse(row.Cells[2].Value.ToString(), out numStandingBy))
                            {
                                lstRegions.Add(new BuildRegionParams { MaxServers = numSessions, Region = region, StandbyServers = numStandingBy });
                            }
                            else
                            {
                                MessageBox.Show("Invalid StandingBy number");
                            }
                        }
                        else
                        {
                            MessageBox.Show("Invalid NumSessions number");
                        }
                    }
                };

                Dictionary<string, string> dictMetaData = new Dictionary<string, string>();
                foreach (DataGridViewRow row in gridviewMetadata.Rows)
                {
                    if (!row.IsNewRow)
                    {
                        dictMetaData.Add(row.Cells[0].ToString(), row.Cells[1].ToString());
                    }
                }

                List<GameCertificateReferenceParams> lstCerts = new List<GameCertificateReferenceParams>();
                foreach (DataGridViewRow row in gridviewCertificates.Rows)
                {
                    if (!row.IsNewRow)
                    {
                        string certName = row.Cells[0].ToString();
                        lstCerts.Add(new GameCertificateReferenceParams()
                        {
                            GsdkAlias = certName,
                            Name = certName
                        });
                    }
                }

                try
                {
                    var res = await PlayFabMultiplayerServerHelper.Singleton.CreateBuild(txtBuildName.Text,
                    (ContainerFlavor)cmbContainerFlavor.SelectedIndex,
                    lstGameAssets,
                    lstCerts,
                    lstPorts,
                    dictMetaData,
                    lstRegions,
                    Convert.ToInt32(numTenants.Value),
                    txtStartupCMD.Text,
                    (AzureVmSize)cmbAzureVMs.SelectedIndex);

                    MessageBox.Show(res ? "Build created" : "Build creation failed", "Create Build");
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Error Occured", MessageBoxButtons.OK);
                }
            }

            this.Enabled = true;
            this.Close();
        }

        private void btnAddAsset_Click(object sender, EventArgs e)
        {
            OpenFileDialog openDlg = new OpenFileDialog();
            openDlg.Filter = "Zip Files (*.zip)|"; // Text files (*.txt)|*.txt|All files (*.*)|*.*"
            DialogResult result = openDlg.ShowDialog();
            if (result == DialogResult.OK)
            {
                gridviewAssets.Rows.Add(new string[] { openDlg.FileName, @"C:\Server\" });
            }
        }
    }
}
