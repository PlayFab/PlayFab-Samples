namespace Client
{
    partial class frmCreateBuild
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
            this.lblName = new System.Windows.Forms.Label();
            this.txtBuildName = new System.Windows.Forms.TextBox();
            this.cmbContainerFlavor = new System.Windows.Forms.ComboBox();
            this.gridviewMetadata = new System.Windows.Forms.DataGridView();
            this.Key = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Value = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gridviewPorts = new System.Windows.Forms.DataGridView();
            this.dataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Protocol = new System.Windows.Forms.DataGridViewComboBoxColumn();
            this.gridviewCertificates = new System.Windows.Forms.DataGridView();
            this.dataGridViewTextBoxColumn3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gridviewRegionConfig = new System.Windows.Forms.DataGridView();
            this.dataGridViewComboBoxColumn1 = new System.Windows.Forms.DataGridViewComboBoxColumn();
            this.dataGridViewTextBoxColumn4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.numTenants = new System.Windows.Forms.NumericUpDown();
            this.txtStartupCMD = new System.Windows.Forms.TextBox();
            this.cmbAzureVMs = new System.Windows.Forms.ComboBox();
            this.btnDeploy = new System.Windows.Forms.Button();
            this.btnAddAsset = new System.Windows.Forms.Button();
            this.gridviewAssets = new System.Windows.Forms.DataGridView();
            this.dataGridViewTextBoxColumn6 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.MountDir = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.lblContainer = new System.Windows.Forms.Label();
            this.lblTenants = new System.Windows.Forms.Label();
            this.lblStartupCMD = new System.Windows.Forms.Label();
            this.lblVMSize = new System.Windows.Forms.Label();
            this.lblPorts = new System.Windows.Forms.Label();
            this.lblRegionConfig = new System.Windows.Forms.Label();
            this.lblAssets = new System.Windows.Forms.Label();
            this.lblMetadata = new System.Windows.Forms.Label();
            this.lblCerts = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.gridviewMetadata)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridviewPorts)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridviewCertificates)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridviewRegionConfig)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numTenants)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridviewAssets)).BeginInit();
            this.SuspendLayout();
            // 
            // lblName
            // 
            this.lblName.AutoSize = true;
            this.lblName.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblName.ForeColor = System.Drawing.Color.White;
            this.lblName.Location = new System.Drawing.Point(6, 7);
            this.lblName.Name = "lblName";
            this.lblName.Size = new System.Drawing.Size(71, 13);
            this.lblName.TabIndex = 0;
            this.lblName.Text = "Build Name";
            // 
            // txtBuildName
            // 
            this.txtBuildName.Location = new System.Drawing.Point(83, 4);
            this.txtBuildName.Name = "txtBuildName";
            this.txtBuildName.Size = new System.Drawing.Size(179, 20);
            this.txtBuildName.TabIndex = 1;
            // 
            // cmbContainerFlavor
            // 
            this.cmbContainerFlavor.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbContainerFlavor.FormattingEnabled = true;
            this.cmbContainerFlavor.Location = new System.Drawing.Point(83, 30);
            this.cmbContainerFlavor.Name = "cmbContainerFlavor";
            this.cmbContainerFlavor.Size = new System.Drawing.Size(179, 21);
            this.cmbContainerFlavor.TabIndex = 2;
            // 
            // gridviewMetadata
            // 
            this.gridviewMetadata.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridviewMetadata.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Key,
            this.Value});
            this.gridviewMetadata.EditMode = System.Windows.Forms.DataGridViewEditMode.EditOnKeystroke;
            this.gridviewMetadata.Location = new System.Drawing.Point(268, 219);
            this.gridviewMetadata.Name = "gridviewMetadata";
            this.gridviewMetadata.RowHeadersVisible = false;
            this.gridviewMetadata.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.gridviewMetadata.Size = new System.Drawing.Size(303, 150);
            this.gridviewMetadata.TabIndex = 10;
            // 
            // Key
            // 
            this.Key.Frozen = true;
            this.Key.HeaderText = "Key";
            this.Key.MinimumWidth = 150;
            this.Key.Name = "Key";
            this.Key.Width = 150;
            // 
            // Value
            // 
            this.Value.Frozen = true;
            this.Value.HeaderText = "Value";
            this.Value.MinimumWidth = 150;
            this.Value.Name = "Value";
            this.Value.Width = 150;
            // 
            // gridviewPorts
            // 
            this.gridviewPorts.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridviewPorts.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn1,
            this.dataGridViewTextBoxColumn2,
            this.Protocol});
            this.gridviewPorts.EditMode = System.Windows.Forms.DataGridViewEditMode.EditOnKeystroke;
            this.gridviewPorts.Location = new System.Drawing.Point(268, 24);
            this.gridviewPorts.Name = "gridviewPorts";
            this.gridviewPorts.RowHeadersVisible = false;
            this.gridviewPorts.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.gridviewPorts.Size = new System.Drawing.Size(303, 169);
            this.gridviewPorts.TabIndex = 11;
            // 
            // dataGridViewTextBoxColumn1
            // 
            this.dataGridViewTextBoxColumn1.Frozen = true;
            this.dataGridViewTextBoxColumn1.HeaderText = "Name";
            this.dataGridViewTextBoxColumn1.MinimumWidth = 100;
            this.dataGridViewTextBoxColumn1.Name = "dataGridViewTextBoxColumn1";
            // 
            // dataGridViewTextBoxColumn2
            // 
            this.dataGridViewTextBoxColumn2.Frozen = true;
            this.dataGridViewTextBoxColumn2.HeaderText = "Number";
            this.dataGridViewTextBoxColumn2.MinimumWidth = 100;
            this.dataGridViewTextBoxColumn2.Name = "dataGridViewTextBoxColumn2";
            // 
            // Protocol
            // 
            this.Protocol.Frozen = true;
            this.Protocol.HeaderText = "Protocol";
            this.Protocol.Items.AddRange(new object[] {
            "TCP",
            "UDP"});
            this.Protocol.MinimumWidth = 100;
            this.Protocol.Name = "Protocol";
            this.Protocol.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.Protocol.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
            // 
            // gridviewCertificates
            // 
            this.gridviewCertificates.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridviewCertificates.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn3});
            this.gridviewCertificates.EditMode = System.Windows.Forms.DataGridViewEditMode.EditOnKeystroke;
            this.gridviewCertificates.Location = new System.Drawing.Point(5, 159);
            this.gridviewCertificates.Name = "gridviewCertificates";
            this.gridviewCertificates.RowHeadersVisible = false;
            this.gridviewCertificates.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.gridviewCertificates.Size = new System.Drawing.Size(256, 147);
            this.gridviewCertificates.TabIndex = 12;
            // 
            // dataGridViewTextBoxColumn3
            // 
            this.dataGridViewTextBoxColumn3.Frozen = true;
            this.dataGridViewTextBoxColumn3.HeaderText = "ID";
            this.dataGridViewTextBoxColumn3.MinimumWidth = 300;
            this.dataGridViewTextBoxColumn3.Name = "dataGridViewTextBoxColumn3";
            this.dataGridViewTextBoxColumn3.Width = 300;
            // 
            // gridviewRegionConfig
            // 
            this.gridviewRegionConfig.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridviewRegionConfig.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewComboBoxColumn1,
            this.dataGridViewTextBoxColumn4,
            this.dataGridViewTextBoxColumn5});
            this.gridviewRegionConfig.EditMode = System.Windows.Forms.DataGridViewEditMode.EditOnKeystroke;
            this.gridviewRegionConfig.Location = new System.Drawing.Point(577, 23);
            this.gridviewRegionConfig.Name = "gridviewRegionConfig";
            this.gridviewRegionConfig.RowHeadersVisible = false;
            this.gridviewRegionConfig.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.gridviewRegionConfig.Size = new System.Drawing.Size(303, 169);
            this.gridviewRegionConfig.TabIndex = 13;
            this.gridviewRegionConfig.UserAddedRow += new System.Windows.Forms.DataGridViewRowEventHandler(this.gridviewRegionConfig_UserAddedRow);
            // 
            // dataGridViewComboBoxColumn1
            // 
            this.dataGridViewComboBoxColumn1.Frozen = true;
            this.dataGridViewComboBoxColumn1.HeaderText = "Region";
            this.dataGridViewComboBoxColumn1.MinimumWidth = 100;
            this.dataGridViewComboBoxColumn1.Name = "dataGridViewComboBoxColumn1";
            this.dataGridViewComboBoxColumn1.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewComboBoxColumn1.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
            // 
            // dataGridViewTextBoxColumn4
            // 
            this.dataGridViewTextBoxColumn4.Frozen = true;
            this.dataGridViewTextBoxColumn4.HeaderText = "Max Sessions";
            this.dataGridViewTextBoxColumn4.MinimumWidth = 100;
            this.dataGridViewTextBoxColumn4.Name = "dataGridViewTextBoxColumn4";
            // 
            // dataGridViewTextBoxColumn5
            // 
            this.dataGridViewTextBoxColumn5.Frozen = true;
            this.dataGridViewTextBoxColumn5.HeaderText = "Num Standing By";
            this.dataGridViewTextBoxColumn5.MinimumWidth = 100;
            this.dataGridViewTextBoxColumn5.Name = "dataGridViewTextBoxColumn5";
            // 
            // numTenants
            // 
            this.numTenants.Location = new System.Drawing.Point(83, 59);
            this.numTenants.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numTenants.Name = "numTenants";
            this.numTenants.Size = new System.Drawing.Size(178, 20);
            this.numTenants.TabIndex = 14;
            this.numTenants.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // txtStartupCMD
            // 
            this.txtStartupCMD.Location = new System.Drawing.Point(83, 85);
            this.txtStartupCMD.Name = "txtStartupCMD";
            this.txtStartupCMD.Size = new System.Drawing.Size(179, 20);
            this.txtStartupCMD.TabIndex = 15;
            // 
            // cmbAzureVMs
            // 
            this.cmbAzureVMs.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(38)))), ((int)(((byte)(55)))), ((int)(((byte)(70)))));
            this.cmbAzureVMs.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbAzureVMs.FormattingEnabled = true;
            this.cmbAzureVMs.Location = new System.Drawing.Point(83, 111);
            this.cmbAzureVMs.Name = "cmbAzureVMs";
            this.cmbAzureVMs.Size = new System.Drawing.Size(179, 21);
            this.cmbAzureVMs.TabIndex = 16;
            // 
            // btnDeploy
            // 
            this.btnDeploy.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(106)))), ((int)(((byte)(12)))));
            this.btnDeploy.Font = new System.Drawing.Font("Verdana", 8.25F, System.Drawing.FontStyle.Bold);
            this.btnDeploy.ForeColor = System.Drawing.Color.White;
            this.btnDeploy.Location = new System.Drawing.Point(134, 312);
            this.btnDeploy.Name = "btnDeploy";
            this.btnDeploy.Size = new System.Drawing.Size(127, 57);
            this.btnDeploy.TabIndex = 22;
            this.btnDeploy.Text = "Deploy";
            this.btnDeploy.UseVisualStyleBackColor = false;
            this.btnDeploy.Click += new System.EventHandler(this.btnDeploy_Click);
            // 
            // btnAddAsset
            // 
            this.btnAddAsset.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(106)))), ((int)(((byte)(12)))));
            this.btnAddAsset.Font = new System.Drawing.Font("Verdana", 8.25F, System.Drawing.FontStyle.Bold);
            this.btnAddAsset.ForeColor = System.Drawing.Color.White;
            this.btnAddAsset.Location = new System.Drawing.Point(2, 312);
            this.btnAddAsset.Name = "btnAddAsset";
            this.btnAddAsset.Size = new System.Drawing.Size(127, 57);
            this.btnAddAsset.TabIndex = 23;
            this.btnAddAsset.Text = "Add Asset";
            this.btnAddAsset.UseVisualStyleBackColor = false;
            this.btnAddAsset.Click += new System.EventHandler(this.btnAddAsset_Click);
            // 
            // gridviewAssets
            // 
            this.gridviewAssets.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridviewAssets.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn6,
            this.MountDir});
            this.gridviewAssets.EditMode = System.Windows.Forms.DataGridViewEditMode.EditOnKeystroke;
            this.gridviewAssets.Location = new System.Drawing.Point(577, 218);
            this.gridviewAssets.Name = "gridviewAssets";
            this.gridviewAssets.RowHeadersVisible = false;
            this.gridviewAssets.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.gridviewAssets.Size = new System.Drawing.Size(303, 151);
            this.gridviewAssets.TabIndex = 24;
            // 
            // dataGridViewTextBoxColumn6
            // 
            this.dataGridViewTextBoxColumn6.Frozen = true;
            this.dataGridViewTextBoxColumn6.HeaderText = "Asset Path";
            this.dataGridViewTextBoxColumn6.MinimumWidth = 150;
            this.dataGridViewTextBoxColumn6.Name = "dataGridViewTextBoxColumn6";
            this.dataGridViewTextBoxColumn6.Width = 150;
            // 
            // MountDir
            // 
            this.MountDir.HeaderText = "Mount Dir";
            this.MountDir.MinimumWidth = 150;
            this.MountDir.Name = "MountDir";
            this.MountDir.Width = 150;
            // 
            // lblContainer
            // 
            this.lblContainer.AutoSize = true;
            this.lblContainer.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblContainer.ForeColor = System.Drawing.Color.White;
            this.lblContainer.Location = new System.Drawing.Point(6, 33);
            this.lblContainer.Name = "lblContainer";
            this.lblContainer.Size = new System.Drawing.Size(61, 13);
            this.lblContainer.TabIndex = 25;
            this.lblContainer.Text = "Container";
            // 
            // lblTenants
            // 
            this.lblTenants.AutoSize = true;
            this.lblTenants.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTenants.ForeColor = System.Drawing.Color.White;
            this.lblTenants.Location = new System.Drawing.Point(6, 61);
            this.lblTenants.Name = "lblTenants";
            this.lblTenants.Size = new System.Drawing.Size(53, 13);
            this.lblTenants.TabIndex = 26;
            this.lblTenants.Text = "Tenants";
            // 
            // lblStartupCMD
            // 
            this.lblStartupCMD.AutoSize = true;
            this.lblStartupCMD.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblStartupCMD.ForeColor = System.Drawing.Color.White;
            this.lblStartupCMD.Location = new System.Drawing.Point(2, 88);
            this.lblStartupCMD.Name = "lblStartupCMD";
            this.lblStartupCMD.Size = new System.Drawing.Size(79, 13);
            this.lblStartupCMD.TabIndex = 27;
            this.lblStartupCMD.Text = "Startup CMD";
            // 
            // lblVMSize
            // 
            this.lblVMSize.AutoSize = true;
            this.lblVMSize.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblVMSize.ForeColor = System.Drawing.Color.White;
            this.lblVMSize.Location = new System.Drawing.Point(6, 114);
            this.lblVMSize.Name = "lblVMSize";
            this.lblVMSize.Size = new System.Drawing.Size(53, 13);
            this.lblVMSize.TabIndex = 28;
            this.lblVMSize.Text = "VM Size";
            // 
            // lblPorts
            // 
            this.lblPorts.AutoSize = true;
            this.lblPorts.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPorts.ForeColor = System.Drawing.Color.White;
            this.lblPorts.Location = new System.Drawing.Point(268, 7);
            this.lblPorts.Name = "lblPorts";
            this.lblPorts.Size = new System.Drawing.Size(36, 13);
            this.lblPorts.TabIndex = 29;
            this.lblPorts.Text = "Ports";
            // 
            // lblRegionConfig
            // 
            this.lblRegionConfig.AutoSize = true;
            this.lblRegionConfig.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblRegionConfig.ForeColor = System.Drawing.Color.White;
            this.lblRegionConfig.Location = new System.Drawing.Point(579, 7);
            this.lblRegionConfig.Name = "lblRegionConfig";
            this.lblRegionConfig.Size = new System.Drawing.Size(126, 13);
            this.lblRegionConfig.TabIndex = 30;
            this.lblRegionConfig.Text = "Region Configuration";
            // 
            // lblAssets
            // 
            this.lblAssets.AutoSize = true;
            this.lblAssets.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAssets.ForeColor = System.Drawing.Color.White;
            this.lblAssets.Location = new System.Drawing.Point(579, 202);
            this.lblAssets.Name = "lblAssets";
            this.lblAssets.Size = new System.Drawing.Size(156, 13);
            this.lblAssets.TabIndex = 32;
            this.lblAssets.Text = "Assets (Add via AddAsset)";
            // 
            // lblMetadata
            // 
            this.lblMetadata.AutoSize = true;
            this.lblMetadata.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblMetadata.ForeColor = System.Drawing.Color.White;
            this.lblMetadata.Location = new System.Drawing.Point(268, 202);
            this.lblMetadata.Name = "lblMetadata";
            this.lblMetadata.Size = new System.Drawing.Size(262, 13);
            this.lblMetadata.TabIndex = 31;
            this.lblMetadata.Text = "Metadata (Applied to build and assets)";
            // 
            // lblCerts
            // 
            this.lblCerts.AutoSize = true;
            this.lblCerts.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCerts.ForeColor = System.Drawing.Color.White;
            this.lblCerts.Location = new System.Drawing.Point(6, 143);
            this.lblCerts.Name = "lblCerts";
            this.lblCerts.Size = new System.Drawing.Size(71, 13);
            this.lblCerts.TabIndex = 33;
            this.lblCerts.Text = "Certificates";
            // 
            // frmCreateBuild
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(38)))), ((int)(((byte)(55)))), ((int)(((byte)(70)))));
            this.ClientSize = new System.Drawing.Size(886, 378);
            this.Controls.Add(this.lblCerts);
            this.Controls.Add(this.lblAssets);
            this.Controls.Add(this.lblMetadata);
            this.Controls.Add(this.lblRegionConfig);
            this.Controls.Add(this.lblPorts);
            this.Controls.Add(this.lblVMSize);
            this.Controls.Add(this.lblStartupCMD);
            this.Controls.Add(this.lblTenants);
            this.Controls.Add(this.lblContainer);
            this.Controls.Add(this.gridviewAssets);
            this.Controls.Add(this.btnAddAsset);
            this.Controls.Add(this.btnDeploy);
            this.Controls.Add(this.cmbAzureVMs);
            this.Controls.Add(this.txtStartupCMD);
            this.Controls.Add(this.numTenants);
            this.Controls.Add(this.gridviewRegionConfig);
            this.Controls.Add(this.gridviewCertificates);
            this.Controls.Add(this.gridviewPorts);
            this.Controls.Add(this.gridviewMetadata);
            this.Controls.Add(this.cmbContainerFlavor);
            this.Controls.Add(this.txtBuildName);
            this.Controls.Add(this.lblName);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "frmCreateBuild";
            this.Text = "Playfab Multiplayer Servers - Admin Tool - Create Build";
            this.Load += new System.EventHandler(this.frmCreateBuild_Load);
            ((System.ComponentModel.ISupportInitialize)(this.gridviewMetadata)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridviewPorts)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridviewCertificates)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridviewRegionConfig)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numTenants)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridviewAssets)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblName;
        private System.Windows.Forms.TextBox txtBuildName;
        private System.Windows.Forms.ComboBox cmbContainerFlavor;
        private System.Windows.Forms.DataGridView gridviewMetadata;
        private System.Windows.Forms.DataGridViewTextBoxColumn Key;
        private System.Windows.Forms.DataGridViewTextBoxColumn Value;
        private System.Windows.Forms.DataGridView gridviewPorts;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn2;
        private System.Windows.Forms.DataGridViewComboBoxColumn Protocol;
        private System.Windows.Forms.DataGridView gridviewCertificates;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn3;
        private System.Windows.Forms.DataGridView gridviewRegionConfig;
        private System.Windows.Forms.NumericUpDown numTenants;
        private System.Windows.Forms.TextBox txtStartupCMD;
        private System.Windows.Forms.ComboBox cmbAzureVMs;
        private System.Windows.Forms.Button btnDeploy;
        private System.Windows.Forms.Button btnAddAsset;
        private System.Windows.Forms.DataGridView gridviewAssets;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn6;
        private System.Windows.Forms.DataGridViewTextBoxColumn MountDir;
        private System.Windows.Forms.Label lblContainer;
        private System.Windows.Forms.Label lblTenants;
        private System.Windows.Forms.Label lblStartupCMD;
        private System.Windows.Forms.Label lblVMSize;
        private System.Windows.Forms.DataGridViewComboBoxColumn dataGridViewComboBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn4;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn5;
        private System.Windows.Forms.Label lblPorts;
        private System.Windows.Forms.Label lblRegionConfig;
        private System.Windows.Forms.Label lblAssets;
        private System.Windows.Forms.Label lblMetadata;
        private System.Windows.Forms.Label lblCerts;
    }
}