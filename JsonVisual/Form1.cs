using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.IO.IsolatedStorage;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Json_net;

namespace JsonVisual
{

    public partial class Form1 : Form
    {
        rfJson JSONobj = new rfJson();
        public Form1()
        {
            InitializeComponent();
        }

        private void открытьToolStripMenuItem_Click(object sender, EventArgs e)
        {
/*            OpenFileDialog dialog = new OpenFileDialog();
            if (dialog.ShowDialog() == DialogResult.OK)*/
            {
                /*                string str = dialog.FileName;*/
                string str = "C:\\Users\\ipnnr\\source\\repos\\Json\\Json\\test.json";
                JSONobj.ReadFromFile(str);
                string s = JSONobj.WriteAsString();

                s = s.Replace("\n", Environment.NewLine);

                textBox1.Text = s;

                textBox1.Refresh();
                /*                label1.Text = s;
                                label1.Refresh();*/

            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try 
            {
                JSONobj.GoNext();
                paint();
            }
            catch(Exception a)
            {
                textBox1.Text += Environment.NewLine + "error: can not go next";
                textBox1.Refresh();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                JSONobj.GoRight();
                paint();
            }
            catch(Exception a)
            { 
                textBox1.Text += Environment.NewLine + "error: can not go right";
                textBox1.Refresh();
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                JSONobj.GoBack();
                paint();
            }
            catch (Exception a)
            {
                textBox1.Text += Environment.NewLine + "error: can not go back";
                textBox1.Refresh();
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            try
            {
                JSONobj.GoUp();
                paint();
            }
            catch (Exception a)
            {
                textBox1.Text += Environment.NewLine + "error: can not go up";
                textBox1.Refresh();
            }
        }

        private void paint()
        {
            if (radioButton1.Checked)
            {
                string s = JSONobj.WriteAsString();

                s = s.Replace("\n", Environment.NewLine);

                textBox1.Text = s;

            }
            if (radioButton2.Checked)
            {
                string s = JSONobj.WriteCurRow();

                s = s.Replace("\n", Environment.NewLine);

                textBox1.Text = s;

            }
            textBox1.Refresh();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            string s = JSONobj.WriteAsString();

            s = s.Replace("\n", Environment.NewLine);

            textBox1.Text = s;

            textBox1.Refresh();
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            string s = JSONobj.WriteCurRow();

            s = s.Replace("\n", Environment.NewLine);

            textBox1.Text = s;

            textBox1.Refresh();
        }
    }
}
