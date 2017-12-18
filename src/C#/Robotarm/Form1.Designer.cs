namespace Robotarm
{
    partial class Form1
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
            this.tb_rawCommand = new System.Windows.Forms.TextBox();
            this.btn_sendRawCommand = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.btn_connectToSelectedPort = new System.Windows.Forms.Button();
            this.lb_availablePorts = new System.Windows.Forms.ListBox();
            this.lb_sentCommands = new System.Windows.Forms.ListBox();
            this.btn_updateAvailablePorts = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // tb_rawCommand
            // 
            this.tb_rawCommand.Location = new System.Drawing.Point(12, 29);
            this.tb_rawCommand.Name = "tb_rawCommand";
            this.tb_rawCommand.Size = new System.Drawing.Size(103, 22);
            this.tb_rawCommand.TabIndex = 0;
            this.tb_rawCommand.KeyDown += new System.Windows.Forms.KeyEventHandler(this.onRawCommandTBKeyDown);
            // 
            // btn_sendRawCommand
            // 
            this.btn_sendRawCommand.Location = new System.Drawing.Point(121, 29);
            this.btn_sendRawCommand.Name = "btn_sendRawCommand";
            this.btn_sendRawCommand.Size = new System.Drawing.Size(75, 23);
            this.btn_sendRawCommand.TabIndex = 1;
            this.btn_sendRawCommand.Text = "Send";
            this.btn_sendRawCommand.UseVisualStyleBackColor = true;
            this.btn_sendRawCommand.Click += new System.EventHandler(this.onSendRawCommand);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(136, 17);
            this.label1.TabIndex = 2;
            this.label1.Text = "Send raw command:";
            // 
            // btn_connectToSelectedPort
            // 
            this.btn_connectToSelectedPort.Location = new System.Drawing.Point(12, 189);
            this.btn_connectToSelectedPort.Name = "btn_connectToSelectedPort";
            this.btn_connectToSelectedPort.Size = new System.Drawing.Size(75, 23);
            this.btn_connectToSelectedPort.TabIndex = 4;
            this.btn_connectToSelectedPort.Text = "Connect";
            this.btn_connectToSelectedPort.UseVisualStyleBackColor = true;
            this.btn_connectToSelectedPort.Click += new System.EventHandler(this.onConnectToSelectedPort);
            // 
            // lb_availablePorts
            // 
            this.lb_availablePorts.FormattingEnabled = true;
            this.lb_availablePorts.ItemHeight = 16;
            this.lb_availablePorts.Location = new System.Drawing.Point(12, 218);
            this.lb_availablePorts.Name = "lb_availablePorts";
            this.lb_availablePorts.Size = new System.Drawing.Size(156, 84);
            this.lb_availablePorts.TabIndex = 6;
            // 
            // lb_sentCommands
            // 
            this.lb_sentCommands.FormattingEnabled = true;
            this.lb_sentCommands.ItemHeight = 16;
            this.lb_sentCommands.Location = new System.Drawing.Point(12, 57);
            this.lb_sentCommands.Name = "lb_sentCommands";
            this.lb_sentCommands.Size = new System.Drawing.Size(184, 84);
            this.lb_sentCommands.TabIndex = 7;
            // 
            // btn_updateAvailablePorts
            // 
            this.btn_updateAvailablePorts.Location = new System.Drawing.Point(93, 189);
            this.btn_updateAvailablePorts.Name = "btn_updateAvailablePorts";
            this.btn_updateAvailablePorts.Size = new System.Drawing.Size(75, 23);
            this.btn_updateAvailablePorts.TabIndex = 8;
            this.btn_updateAvailablePorts.Text = "Update";
            this.btn_updateAvailablePorts.UseVisualStyleBackColor = true;
            this.btn_updateAvailablePorts.Click += new System.EventHandler(this.onUpdateAvailablePorts);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(9, 169);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(162, 17);
            this.label2.TabIndex = 9;
            this.label2.Text = "Connect to a Serial Port:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1086, 675);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.btn_updateAvailablePorts);
            this.Controls.Add(this.lb_sentCommands);
            this.Controls.Add(this.lb_availablePorts);
            this.Controls.Add(this.btn_connectToSelectedPort);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btn_sendRawCommand);
            this.Controls.Add(this.tb_rawCommand);
            this.Name = "Form1";
            this.Text = "Robotarm";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tb_rawCommand;
        private System.Windows.Forms.Button btn_sendRawCommand;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btn_connectToSelectedPort;
        private System.Windows.Forms.ListBox lb_availablePorts;
        private System.Windows.Forms.ListBox lb_sentCommands;
        private System.Windows.Forms.Button btn_updateAvailablePorts;
        private System.Windows.Forms.Label label2;
    }
}

