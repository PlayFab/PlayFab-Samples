namespace Client
{
    partial class frmMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.txtTitleID = new System.Windows.Forms.TextBox();
            this.lblTitleID = new System.Windows.Forms.Label();
            this.btnAuth = new System.Windows.Forms.Button();
            this.btnQueryBuilds = new System.Windows.Forms.Button();
            this.lstConsole = new System.Windows.Forms.ListBox();
            this.label2 = new System.Windows.Forms.Label();
            this.txtSecret = new System.Windows.Forms.TextBox();
            this.gridViewBuilds = new System.Windows.Forms.DataGridView();
            this.btnAllocate = new System.Windows.Forms.Button();
            this.btnQueryServers = new System.Windows.Forms.Button();
            this.gridViewSessions = new System.Windows.Forms.DataGridView();
            this.ServerID = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.VMID = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colRegion = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.State = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.btnConnectClient = new System.Windows.Forms.Button();
            this.btnRDP = new System.Windows.Forms.Button();
            this.lblSessionID = new System.Windows.Forms.Label();
            this.txtSessionID = new System.Windows.Forms.TextBox();
            this.btnGenerateSessionID = new System.Windows.Forms.Button();
            this.btnCopySessionID = new System.Windows.Forms.Button();
            this.btnUploadNewBuild = new System.Windows.Forms.Button();
            this.btnQueryVMS = new System.Windows.Forms.Button();
            this.gridVMs = new System.Windows.Forms.DataGridView();
            this.dataGridViewTextBoxColumn2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.btnRDPVM = new System.Windows.Forms.Button();
            this.lblCurrentRegion = new System.Windows.Forms.Label();
            this.cmbRegion = new System.Windows.Forms.ComboBox();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.lblAllocRegions = new System.Windows.Forms.Label();
            this.chkAllocationRegions = new System.Windows.Forms.CheckedListBox();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.lblBuilds = new System.Windows.Forms.Label();
            this.lblSessions = new System.Windows.Forms.Label();
            this.lblVMs = new System.Windows.Forms.Label();
            this.txtSessionCookie = new System.Windows.Forms.TextBox();
            this.lblCookie = new System.Windows.Forms.Label();
            this.ID = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.BuildName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.gridViewBuilds)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridViewSessions)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridVMs)).BeginInit();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.SuspendLayout();
            // 
            // txtTitleID
            // 
            this.txtTitleID.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(120)))), ((int)(((byte)(6)))));
            this.txtTitleID.Location = new System.Drawing.Point(962, 69);
            this.txtTitleID.Name = "txtTitleID";
            this.txtTitleID.Size = new System.Drawing.Size(159, 20);
            this.txtTitleID.TabIndex = 0;
            // 
            // lblTitleID
            // 
            this.lblTitleID.AutoSize = true;
            this.lblTitleID.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitleID.ForeColor = System.Drawing.Color.White;
            this.lblTitleID.Location = new System.Drawing.Point(909, 73);
            this.lblTitleID.Name = "lblTitleID";
            this.lblTitleID.Size = new System.Drawing.Size(53, 13);
            this.lblTitleID.TabIndex = 1;
            this.lblTitleID.Text = "Title ID:";
            // 
            // btnAuth
            // 
            this.btnAuth.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(106)))), ((int)(((byte)(12)))));
            this.btnAuth.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnAuth.Font = new System.Drawing.Font("Verdana", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnAuth.ForeColor = System.Drawing.Color.White;
            this.btnAuth.Location = new System.Drawing.Point(1132, 48);
            this.btnAuth.Name = "btnAuth";
            this.btnAuth.Size = new System.Drawing.Size(102, 56);
            this.btnAuth.TabIndex = 2;
            this.btnAuth.Text = "Auth";
            this.btnAuth.UseVisualStyleBackColor = false;
            this.btnAuth.Click += new System.EventHandler(this.btnAuth_Click);
            // 
            // btnQueryBuilds
            // 
            this.btnQueryBuilds.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(106)))), ((int)(((byte)(12)))));
            this.btnQueryBuilds.Enabled = false;
            this.btnQueryBuilds.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnQueryBuilds.Font = new System.Drawing.Font("Verdana", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnQueryBuilds.ForeColor = System.Drawing.Color.White;
            this.btnQueryBuilds.Location = new System.Drawing.Point(6, 6);
            this.btnQueryBuilds.Name = "btnQueryBuilds";
            this.btnQueryBuilds.Size = new System.Drawing.Size(127, 57);
            this.btnQueryBuilds.TabIndex = 3;
            this.btnQueryBuilds.Text = "Query Builds";
            this.btnQueryBuilds.UseVisualStyleBackColor = false;
            this.btnQueryBuilds.Click += new System.EventHandler(this.btnQueryBuilds_Click);
            // 
            // lstConsole
            // 
            this.lstConsole.BackColor = System.Drawing.Color.White;
            this.lstConsole.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lstConsole.Font = new System.Drawing.Font("Verdana", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lstConsole.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(112)))), ((int)(((byte)(6)))));
            this.lstConsole.FormattingEnabled = true;
            this.lstConsole.Location = new System.Drawing.Point(912, 180);
            this.lstConsole.Name = "lstConsole";
            this.lstConsole.Size = new System.Drawing.Size(322, 184);
            this.lstConsole.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(913, 96);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(48, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "Secret:";
            // 
            // txtSecret
            // 
            this.txtSecret.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(120)))), ((int)(((byte)(6)))));
            this.txtSecret.Location = new System.Drawing.Point(962, 92);
            this.txtSecret.Name = "txtSecret";
            this.txtSecret.Size = new System.Drawing.Size(159, 20);
            this.txtSecret.TabIndex = 7;
            // 
            // gridViewBuilds
            // 
            this.gridViewBuilds.AllowUserToAddRows = false;
            this.gridViewBuilds.AllowUserToDeleteRows = false;
            this.gridViewBuilds.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridViewBuilds.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.ID,
            this.BuildName});
            this.gridViewBuilds.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.gridViewBuilds.Location = new System.Drawing.Point(6, 69);
            this.gridViewBuilds.Name = "gridViewBuilds";
            this.gridViewBuilds.RowHeadersVisible = false;
            this.gridViewBuilds.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.gridViewBuilds.ShowEditingIcon = false;
            this.gridViewBuilds.Size = new System.Drawing.Size(863, 243);
            this.gridViewBuilds.TabIndex = 9;
            // 
            // btnAllocate
            // 
            this.btnAllocate.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(106)))), ((int)(((byte)(12)))));
            this.btnAllocate.Enabled = false;
            this.btnAllocate.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnAllocate.Font = new System.Drawing.Font("Verdana", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnAllocate.ForeColor = System.Drawing.Color.White;
            this.btnAllocate.Location = new System.Drawing.Point(139, 6);
            this.btnAllocate.Name = "btnAllocate";
            this.btnAllocate.Size = new System.Drawing.Size(127, 57);
            this.btnAllocate.TabIndex = 10;
            this.btnAllocate.Text = "Allocate";
            this.btnAllocate.UseVisualStyleBackColor = false;
            this.btnAllocate.Click += new System.EventHandler(this.btnAllocate_Click);
            // 
            // btnQueryServers
            // 
            this.btnQueryServers.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(106)))), ((int)(((byte)(12)))));
            this.btnQueryServers.Enabled = false;
            this.btnQueryServers.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnQueryServers.Font = new System.Drawing.Font("Verdana", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnQueryServers.ForeColor = System.Drawing.Color.White;
            this.btnQueryServers.Location = new System.Drawing.Point(405, 6);
            this.btnQueryServers.Name = "btnQueryServers";
            this.btnQueryServers.Size = new System.Drawing.Size(127, 57);
            this.btnQueryServers.TabIndex = 12;
            this.btnQueryServers.Text = "Query Servers";
            this.btnQueryServers.UseVisualStyleBackColor = false;
            this.btnQueryServers.Click += new System.EventHandler(this.btnQueryServers_Click);
            // 
            // gridViewSessions
            // 
            this.gridViewSessions.AllowUserToAddRows = false;
            this.gridViewSessions.AllowUserToDeleteRows = false;
            this.gridViewSessions.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridViewSessions.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.ServerID,
            this.VMID,
            this.colRegion,
            this.State});
            this.gridViewSessions.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.gridViewSessions.Location = new System.Drawing.Point(3, 64);
            this.gridViewSessions.Name = "gridViewSessions";
            this.gridViewSessions.RowHeadersVisible = false;
            this.gridViewSessions.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.gridViewSessions.Size = new System.Drawing.Size(858, 245);
            this.gridViewSessions.TabIndex = 13;
            // 
            // ServerID
            // 
            this.ServerID.Frozen = true;
            this.ServerID.HeaderText = "Server ID";
            this.ServerID.MinimumWidth = 250;
            this.ServerID.Name = "ServerID";
            this.ServerID.ReadOnly = true;
            this.ServerID.Width = 250;
            // 
            // VMID
            // 
            this.VMID.HeaderText = "VM ID";
            this.VMID.MinimumWidth = 250;
            this.VMID.Name = "VMID";
            this.VMID.ReadOnly = true;
            this.VMID.Width = 250;
            // 
            // colRegion
            // 
            this.colRegion.HeaderText = "Region";
            this.colRegion.MinimumWidth = 250;
            this.colRegion.Name = "colRegion";
            this.colRegion.ReadOnly = true;
            this.colRegion.Width = 250;
            // 
            // State
            // 
            this.State.HeaderText = "State";
            this.State.MinimumWidth = 100;
            this.State.Name = "State";
            this.State.ReadOnly = true;
            // 
            // btnConnectClient
            // 
            this.btnConnectClient.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(106)))), ((int)(((byte)(12)))));
            this.btnConnectClient.Enabled = false;
            this.btnConnectClient.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnConnectClient.Font = new System.Drawing.Font("Verdana", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnConnectClient.ForeColor = System.Drawing.Color.White;
            this.btnConnectClient.Location = new System.Drawing.Point(139, 3);
            this.btnConnectClient.Name = "btnConnectClient";
            this.btnConnectClient.Size = new System.Drawing.Size(127, 57);
            this.btnConnectClient.TabIndex = 14;
            this.btnConnectClient.Text = "Connect Client";
            this.btnConnectClient.UseVisualStyleBackColor = false;
            this.btnConnectClient.Click += new System.EventHandler(this.btnConnectClient_Click);
            // 
            // btnRDP
            // 
            this.btnRDP.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(106)))), ((int)(((byte)(12)))));
            this.btnRDP.Enabled = false;
            this.btnRDP.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnRDP.Font = new System.Drawing.Font("Verdana", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnRDP.ForeColor = System.Drawing.Color.White;
            this.btnRDP.Location = new System.Drawing.Point(6, 4);
            this.btnRDP.Name = "btnRDP";
            this.btnRDP.Size = new System.Drawing.Size(127, 57);
            this.btnRDP.TabIndex = 15;
            this.btnRDP.Text = "RDP (Session)";
            this.btnRDP.UseVisualStyleBackColor = false;
            this.btnRDP.Click += new System.EventHandler(this.btnRDP_Click);
            // 
            // lblSessionID
            // 
            this.lblSessionID.AutoSize = true;
            this.lblSessionID.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSessionID.ForeColor = System.Drawing.Color.White;
            this.lblSessionID.Location = new System.Drawing.Point(913, 125);
            this.lblSessionID.Name = "lblSessionID";
            this.lblSessionID.Size = new System.Drawing.Size(72, 13);
            this.lblSessionID.TabIndex = 18;
            this.lblSessionID.Text = "Session ID:";
            // 
            // txtSessionID
            // 
            this.txtSessionID.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(120)))), ((int)(((byte)(6)))));
            this.txtSessionID.Location = new System.Drawing.Point(987, 123);
            this.txtSessionID.Name = "txtSessionID";
            this.txtSessionID.Size = new System.Drawing.Size(123, 20);
            this.txtSessionID.TabIndex = 17;
            // 
            // btnGenerateSessionID
            // 
            this.btnGenerateSessionID.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(106)))), ((int)(((byte)(12)))));
            this.btnGenerateSessionID.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGenerateSessionID.Font = new System.Drawing.Font("Verdana", 6.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnGenerateSessionID.ForeColor = System.Drawing.Color.White;
            this.btnGenerateSessionID.Location = new System.Drawing.Point(1115, 120);
            this.btnGenerateSessionID.Name = "btnGenerateSessionID";
            this.btnGenerateSessionID.Size = new System.Drawing.Size(66, 20);
            this.btnGenerateSessionID.TabIndex = 19;
            this.btnGenerateSessionID.Text = "Generate";
            this.btnGenerateSessionID.UseVisualStyleBackColor = false;
            this.btnGenerateSessionID.Click += new System.EventHandler(this.btnGenerateSessionID_Click);
            // 
            // btnCopySessionID
            // 
            this.btnCopySessionID.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(106)))), ((int)(((byte)(12)))));
            this.btnCopySessionID.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnCopySessionID.Font = new System.Drawing.Font("Verdana", 6.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnCopySessionID.ForeColor = System.Drawing.Color.White;
            this.btnCopySessionID.Location = new System.Drawing.Point(1186, 120);
            this.btnCopySessionID.Name = "btnCopySessionID";
            this.btnCopySessionID.Size = new System.Drawing.Size(48, 20);
            this.btnCopySessionID.TabIndex = 20;
            this.btnCopySessionID.Text = "Copy";
            this.btnCopySessionID.UseVisualStyleBackColor = false;
            this.btnCopySessionID.Click += new System.EventHandler(this.btnCopySessionID_Click);
            // 
            // btnUploadNewBuild
            // 
            this.btnUploadNewBuild.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(106)))), ((int)(((byte)(12)))));
            this.btnUploadNewBuild.Enabled = false;
            this.btnUploadNewBuild.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnUploadNewBuild.Font = new System.Drawing.Font("Verdana", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnUploadNewBuild.ForeColor = System.Drawing.Color.White;
            this.btnUploadNewBuild.Location = new System.Drawing.Point(272, 6);
            this.btnUploadNewBuild.Name = "btnUploadNewBuild";
            this.btnUploadNewBuild.Size = new System.Drawing.Size(127, 57);
            this.btnUploadNewBuild.TabIndex = 21;
            this.btnUploadNewBuild.Text = "Upload New Build";
            this.btnUploadNewBuild.UseVisualStyleBackColor = false;
            this.btnUploadNewBuild.Click += new System.EventHandler(this.btnUploadNewBuild_Click);
            // 
            // btnQueryVMS
            // 
            this.btnQueryVMS.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(106)))), ((int)(((byte)(12)))));
            this.btnQueryVMS.Enabled = false;
            this.btnQueryVMS.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnQueryVMS.Font = new System.Drawing.Font("Verdana", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnQueryVMS.ForeColor = System.Drawing.Color.White;
            this.btnQueryVMS.Location = new System.Drawing.Point(537, 6);
            this.btnQueryVMS.Name = "btnQueryVMS";
            this.btnQueryVMS.Size = new System.Drawing.Size(127, 57);
            this.btnQueryVMS.TabIndex = 22;
            this.btnQueryVMS.Text = "Query VMs";
            this.btnQueryVMS.UseVisualStyleBackColor = false;
            this.btnQueryVMS.Click += new System.EventHandler(this.btnQueryVMS_Click);
            // 
            // gridVMs
            // 
            this.gridVMs.AllowUserToAddRows = false;
            this.gridVMs.AllowUserToDeleteRows = false;
            this.gridVMs.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridVMs.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn2,
            this.dataGridViewTextBoxColumn4});
            this.gridVMs.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.gridVMs.Location = new System.Drawing.Point(3, 71);
            this.gridVMs.Name = "gridVMs";
            this.gridVMs.RowHeadersVisible = false;
            this.gridVMs.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.gridVMs.Size = new System.Drawing.Size(872, 245);
            this.gridVMs.TabIndex = 23;
            // 
            // dataGridViewTextBoxColumn2
            // 
            this.dataGridViewTextBoxColumn2.HeaderText = "VM ID";
            this.dataGridViewTextBoxColumn2.MinimumWidth = 700;
            this.dataGridViewTextBoxColumn2.Name = "dataGridViewTextBoxColumn2";
            this.dataGridViewTextBoxColumn2.ReadOnly = true;
            this.dataGridViewTextBoxColumn2.Width = 700;
            // 
            // dataGridViewTextBoxColumn4
            // 
            this.dataGridViewTextBoxColumn4.HeaderText = "State";
            this.dataGridViewTextBoxColumn4.MinimumWidth = 100;
            this.dataGridViewTextBoxColumn4.Name = "dataGridViewTextBoxColumn4";
            this.dataGridViewTextBoxColumn4.ReadOnly = true;
            // 
            // btnRDPVM
            // 
            this.btnRDPVM.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(106)))), ((int)(((byte)(12)))));
            this.btnRDPVM.Enabled = false;
            this.btnRDPVM.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnRDPVM.Font = new System.Drawing.Font("Verdana", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnRDPVM.ForeColor = System.Drawing.Color.White;
            this.btnRDPVM.Location = new System.Drawing.Point(3, 8);
            this.btnRDPVM.Name = "btnRDPVM";
            this.btnRDPVM.Size = new System.Drawing.Size(127, 57);
            this.btnRDPVM.TabIndex = 24;
            this.btnRDPVM.Text = "RDP (VM)";
            this.btnRDPVM.UseVisualStyleBackColor = false;
            this.btnRDPVM.Click += new System.EventHandler(this.btnRDPVM_Click);
            // 
            // lblCurrentRegion
            // 
            this.lblCurrentRegion.AutoSize = true;
            this.lblCurrentRegion.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCurrentRegion.ForeColor = System.Drawing.Color.White;
            this.lblCurrentRegion.Location = new System.Drawing.Point(909, 50);
            this.lblCurrentRegion.Name = "lblCurrentRegion";
            this.lblCurrentRegion.Size = new System.Drawing.Size(96, 13);
            this.lblCurrentRegion.TabIndex = 25;
            this.lblCurrentRegion.Text = "Current Region:";
            // 
            // cmbRegion
            // 
            this.cmbRegion.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbRegion.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(120)))), ((int)(((byte)(6)))));
            this.cmbRegion.FormattingEnabled = true;
            this.cmbRegion.Location = new System.Drawing.Point(1008, 46);
            this.cmbRegion.Margin = new System.Windows.Forms.Padding(2);
            this.cmbRegion.Name = "cmbRegion";
            this.cmbRegion.Size = new System.Drawing.Size(113, 21);
            this.cmbRegion.TabIndex = 26;
            // 
            // tabControl1
            // 
            this.tabControl1.Appearance = System.Windows.Forms.TabAppearance.FlatButtons;
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.ItemSize = new System.Drawing.Size(0, 1);
            this.tabControl1.Location = new System.Drawing.Point(20, 50);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(883, 314);
            this.tabControl1.SizeMode = System.Windows.Forms.TabSizeMode.Fixed;
            this.tabControl1.TabIndex = 27;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.gridViewBuilds);
            this.tabPage1.Controls.Add(this.lblAllocRegions);
            this.tabPage1.Controls.Add(this.btnQueryBuilds);
            this.tabPage1.Controls.Add(this.chkAllocationRegions);
            this.tabPage1.Controls.Add(this.btnAllocate);
            this.tabPage1.Controls.Add(this.btnUploadNewBuild);
            this.tabPage1.Controls.Add(this.btnQueryServers);
            this.tabPage1.Controls.Add(this.btnQueryVMS);
            this.tabPage1.Location = new System.Drawing.Point(4, 5);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(875, 305);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Builds";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // lblAllocRegions
            // 
            this.lblAllocRegions.AutoSize = true;
            this.lblAllocRegions.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAllocRegions.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(106)))), ((int)(((byte)(12)))));
            this.lblAllocRegions.Location = new System.Drawing.Point(681, 6);
            this.lblAllocRegions.Name = "lblAllocRegions";
            this.lblAllocRegions.Size = new System.Drawing.Size(173, 13);
            this.lblAllocRegions.TabIndex = 31;
            this.lblAllocRegions.Text = "Allocation Preferred Regions:";
            // 
            // chkAllocationRegions
            // 
            this.chkAllocationRegions.FormattingEnabled = true;
            this.chkAllocationRegions.Location = new System.Drawing.Point(682, 19);
            this.chkAllocationRegions.Name = "chkAllocationRegions";
            this.chkAllocationRegions.Size = new System.Drawing.Size(172, 34);
            this.chkAllocationRegions.TabIndex = 31;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.gridViewSessions);
            this.tabPage2.Controls.Add(this.btnRDP);
            this.tabPage2.Controls.Add(this.btnConnectClient);
            this.tabPage2.Location = new System.Drawing.Point(4, 5);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(875, 305);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Sessions";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.btnRDPVM);
            this.tabPage3.Controls.Add(this.gridVMs);
            this.tabPage3.Location = new System.Drawing.Point(4, 5);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Size = new System.Drawing.Size(875, 305);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "VMs";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // lblBuilds
            // 
            this.lblBuilds.AutoSize = true;
            this.lblBuilds.Font = new System.Drawing.Font("Segoe UI", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblBuilds.ForeColor = System.Drawing.Color.Silver;
            this.lblBuilds.Location = new System.Drawing.Point(15, 9);
            this.lblBuilds.Name = "lblBuilds";
            this.lblBuilds.Size = new System.Drawing.Size(73, 30);
            this.lblBuilds.TabIndex = 28;
            this.lblBuilds.Text = "Builds";
            this.lblBuilds.Click += new System.EventHandler(this.lblBuilds_Click);
            // 
            // lblSessions
            // 
            this.lblSessions.AutoSize = true;
            this.lblSessions.Font = new System.Drawing.Font("Segoe UI", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSessions.ForeColor = System.Drawing.Color.Gray;
            this.lblSessions.Location = new System.Drawing.Point(94, 9);
            this.lblSessions.Name = "lblSessions";
            this.lblSessions.Size = new System.Drawing.Size(95, 30);
            this.lblSessions.TabIndex = 29;
            this.lblSessions.Text = "Sessions";
            this.lblSessions.Click += new System.EventHandler(this.lblSessions_Click);
            // 
            // lblVMs
            // 
            this.lblVMs.AutoSize = true;
            this.lblVMs.Font = new System.Drawing.Font("Segoe UI", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblVMs.ForeColor = System.Drawing.Color.Gray;
            this.lblVMs.Location = new System.Drawing.Point(195, 9);
            this.lblVMs.Name = "lblVMs";
            this.lblVMs.Size = new System.Drawing.Size(179, 30);
            this.lblVMs.TabIndex = 30;
            this.lblVMs.Text = "Virtual Machines";
            this.lblVMs.Click += new System.EventHandler(this.lblVMs_Click);
            // 
            // txtSessionCookie
            // 
            this.txtSessionCookie.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(120)))), ((int)(((byte)(6)))));
            this.txtSessionCookie.Location = new System.Drawing.Point(1009, 149);
            this.txtSessionCookie.Name = "txtSessionCookie";
            this.txtSessionCookie.Size = new System.Drawing.Size(172, 20);
            this.txtSessionCookie.TabIndex = 31;
            // 
            // lblCookie
            // 
            this.lblCookie.AutoSize = true;
            this.lblCookie.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCookie.ForeColor = System.Drawing.Color.White;
            this.lblCookie.Location = new System.Drawing.Point(911, 150);
            this.lblCookie.Name = "lblCookie";
            this.lblCookie.Size = new System.Drawing.Size(98, 13);
            this.lblCookie.TabIndex = 32;
            this.lblCookie.Text = "Session Cookie:";
            // 
            // ID
            // 
            this.ID.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.AllCells;
            this.ID.Frozen = true;
            this.ID.HeaderText = "ID";
            this.ID.MinimumWidth = 400;
            this.ID.Name = "ID";
            this.ID.ReadOnly = true;
            this.ID.Width = 400;
            // 
            // BuildName
            // 
            this.BuildName.Frozen = true;
            this.BuildName.HeaderText = "Name";
            this.BuildName.MinimumWidth = 400;
            this.BuildName.Name = "BuildName";
            this.BuildName.ReadOnly = true;
            this.BuildName.Width = 400;
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(38)))), ((int)(((byte)(55)))), ((int)(((byte)(70)))));
            this.ClientSize = new System.Drawing.Size(1239, 373);
            this.Controls.Add(this.lblCookie);
            this.Controls.Add(this.txtSessionCookie);
            this.Controls.Add(this.lblVMs);
            this.Controls.Add(this.lblSessions);
            this.Controls.Add(this.lblBuilds);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.cmbRegion);
            this.Controls.Add(this.lblCurrentRegion);
            this.Controls.Add(this.btnCopySessionID);
            this.Controls.Add(this.btnGenerateSessionID);
            this.Controls.Add(this.lblSessionID);
            this.Controls.Add(this.txtSessionID);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtSecret);
            this.Controls.Add(this.lstConsole);
            this.Controls.Add(this.btnAuth);
            this.Controls.Add(this.lblTitleID);
            this.Controls.Add(this.txtTitleID);
            this.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(106)))), ((int)(((byte)(12)))));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "frmMain";
            this.Text = "Playfab Multiplayer Servers - Admin Tool";
            this.Load += new System.EventHandler(this.frmMain_Load);
            ((System.ComponentModel.ISupportInitialize)(this.gridViewBuilds)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridViewSessions)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridVMs)).EndInit();
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage3.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtTitleID;
        private System.Windows.Forms.Label lblTitleID;
        private System.Windows.Forms.Button btnAuth;
        private System.Windows.Forms.Button btnQueryBuilds;
        private System.Windows.Forms.ListBox lstConsole;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtSecret;
        private System.Windows.Forms.DataGridView gridViewBuilds;
        private System.Windows.Forms.Button btnAllocate;
        private System.Windows.Forms.Button btnQueryServers;
        private System.Windows.Forms.DataGridView gridViewSessions;
        private System.Windows.Forms.Button btnConnectClient;
        private System.Windows.Forms.Button btnRDP;
        private System.Windows.Forms.Label lblSessionID;
        private System.Windows.Forms.TextBox txtSessionID;
        private System.Windows.Forms.Button btnGenerateSessionID;
        private System.Windows.Forms.Button btnCopySessionID;
        private System.Windows.Forms.Button btnUploadNewBuild;
        private System.Windows.Forms.Button btnQueryVMS;
        private System.Windows.Forms.DataGridView gridVMs;
        private System.Windows.Forms.Button btnRDPVM;
        private System.Windows.Forms.Label lblCurrentRegion;
        private System.Windows.Forms.ComboBox cmbRegion;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.Label lblBuilds;
        private System.Windows.Forms.Label lblSessions;
        private System.Windows.Forms.Label lblVMs;
        private System.Windows.Forms.CheckedListBox chkAllocationRegions;
        private System.Windows.Forms.Label lblAllocRegions;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn2;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn4;
        private System.Windows.Forms.DataGridViewTextBoxColumn ServerID;
        private System.Windows.Forms.DataGridViewTextBoxColumn VMID;
        private System.Windows.Forms.DataGridViewTextBoxColumn colRegion;
        private System.Windows.Forms.DataGridViewTextBoxColumn State;
        private System.Windows.Forms.TextBox txtSessionCookie;
        private System.Windows.Forms.Label lblCookie;
        private System.Windows.Forms.DataGridViewTextBoxColumn ID;
        private System.Windows.Forms.DataGridViewTextBoxColumn BuildName;
    }
}

