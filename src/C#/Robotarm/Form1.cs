﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace Robotarm
{
    public partial class Form1 : Form
    {
        SerialPort port = null;


        public Form1()
        {
            InitializeComponent();

            getAvailablePorts();            
        }

        private void onSendRawCommand(object sender, EventArgs e)
        {
            string str = tb_rawCommand.Text;
            if (str != "")
            {
                sendRawCommand(str);
                tb_rawCommand.Text = "";
            }
            else
                MessageBox.Show("Don't send empty commands!");
        }

        private void onConnectToSelectedPort(object sender, EventArgs e)
        {
            string selectedPort;
            try
            {
                selectedPort = lb_availablePorts.SelectedItem.ToString();
                MessageBox.Show("Successfully connected to " + selectedPort + ".");
            }
            catch (Exception ex)    // e is not allowed
            {
                MessageBox.Show("No Port selected.");
                return;
            }

            try
            {
                port = new SerialPort(selectedPort, 9600);
                port.Open();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Not able to connect to \"" + selectedPort + "\".");
            }
        }

        private void onRawCommandTBKeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Enter)
            {
                string str = tb_rawCommand.Text;
                if (str != "")
                {
                    sendRawCommand(str);
                    tb_rawCommand.Text = "";
                }
                else
                    MessageBox.Show("Don't send empty commands!");
            }
        }

        private void onUpdateAvailablePorts(object sender, EventArgs e)
        {
            getAvailablePorts();
        }


        void sendRawCommand(string aStr)
        {
            if (port != null)
            {
                port.Write(aStr + '\n');
                lb_sentCommands.Items.Add(aStr);
            }
            else
            {
                MessageBox.Show("Connect to a port first.");
            }
        }

        void getAvailablePorts()
        {
            lb_availablePorts.Items.Clear();
            try
            {
                string[] ports = SerialPort.GetPortNames();
                foreach (string port in ports)
                {
                    lb_availablePorts.Items.Add(port);
                }
            }
            catch (Exception e)
            {
                MessageBox.Show("Unable to list available ports.");
            }
        }
    }
}