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
    enum mode
    {
        add,
        mod
    };
    public partial class Form1 : Form
    {
        rfJson JSONobj = new rfJson();
        mode param;
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
                string str = "D:\\git_reps\\Json\\Json.exe\\test.json";
                JSONobj.ReadFromFile(str);
                string s = JSONobj.WriteAsString();

                s = s.Replace("\n", Environment.NewLine);

                textBox1.Text = s;

                textBox1.Refresh();
                /*                label1.Text = s;
                                label1.Refresh();*/
                GoRight.Visible = true;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            JSONobj.GoNext();
            paint();
            if (!JSONobj.HasNext()) GoNext.Visible = false;
            if (!JSONobj.HasRight()) GoRight.Visible = false;
            GoBack.Visible = true;
            GoUp.Visible = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
                JSONobj.GoRight();
                paint();
            if (!JSONobj.HasNext()) GoNext.Visible = false;
            if (!JSONobj.HasRight()) GoRight.Visible = false;
            GoBack.Visible = true;
            GoUp.Visible = true;
        }

        private void button3_Click(object sender, EventArgs e)
        {
                JSONobj.GoBack();
                paint();
            GoNext.Visible = true;
            GoRight.Visible = true;
            if (!JSONobj.HasNext()) GoNext.Visible = false;
            if (!JSONobj.HasRight()) GoRight.Visible = false;
            if (!JSONobj.HasBack()) GoBack.Visible = false;
            if (!JSONobj.HasUp()) GoUp.Visible = false;
        }

        private void button4_Click(object sender, EventArgs e)
        {
                JSONobj.GoUp();
                paint();
            GoNext.Visible = true;
            GoRight.Visible = true;
            if (!JSONobj.HasNext()) GoNext.Visible = false;
            if (!JSONobj.HasBack()) GoBack.Visible = false;
            if (!JSONobj.HasUp()) GoUp.Visible = false;
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            param = mode.add;
            comboBox1.Visible = true;
            label1.Visible = true;
            label2.Visible = true;
            textBox2.Visible = true;
            textBox3.Visible = true;
            textBox2.Clear();
            textBox3.Clear();
            button4.Visible = true;
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            param = mode.mod;
            comboBox1.Visible = false;
            label1.Visible = false;
            label2.Visible = true;
            textBox2.Visible = false;
            textBox3.Visible = true;
            textBox3.Clear();
            button4.Visible = true;
        }

        private void button3_Click_1(object sender, EventArgs e)
        {
            JSONobj.delcur();
            paint();
        }

        private void button4_Click_1(object sender, EventArgs e)
        {
            change();
            paint();
            comboBox1.Visible = false;
            label1.Visible = false;
            label2.Visible = false;
            textBox2.Visible = false;
            textBox3.Visible = false;
            button4.Visible = false;
        }

        private void change()
        {
            switch (param)
            {
                case mode.add:
                    {
                        String key = textBox2.Text;
                        String content = textBox3.Text;
                        int depth = 1;
                        if (!JSONobj.empty())
                        {
                            depth = JSONobj.GetCur().GetDepth() + 1;
                        }
                        switch (comboBox1.SelectedIndex)
                        {
                            case 0:
                                {
                                    rfValueStr s = new rfValueStr(key, depth);
                                    s.SetContent(content);
                                    JSONobj.AddRight(s);
                                    break;
                                }
                            case 1:
                                {
                                    rfValueInt s = new rfValueInt(key, depth);
                                    s.SetContent(content);
                                    JSONobj.AddRight(s);
                                    break;
                                }
                            case 2:
                                {
                                    rfValueArr s = new rfValueArr(key, depth);
                                    JSONobj.AddRight(s);
                                    break;
                                }
                        }

                        break;
                    }
                case mode.mod:
                    {
                        String content = textBox3.Text;
                        JSONobj.SetContent(content);
                        break;
                    }
            }
        }

            private void paint1()
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
            GoNext.Visible = true;
            GoRight.Visible = true;
            GoBack.Visible = true;  
            GoUp.Visible = true;    
        }

        private void paint()
        {
            rfPointer point = new rfPointer();
            point.SetPointer(JSONobj);
            string s = "{\n";
            s += point.GetCur().To_String();
            point.GoRight();
            while (point.HasUp())
            {
                    while (point.HasRight())
                    {
                        s += point.GetCur().To_String();
                        point.GoRight();
                    }
                    s += point.GetCur().To_String();
                    while (point.HasUp() && !point.HasNext())
                    {
                    point.GoUp();
                    s += point.GetCur().tab(point.GetCur().GetDepth()) + "}\n";
                    }
                    if (point.HasNext())
                        point.GoNext();
            }
            s += "}";
            s = s.Replace("\n", Environment.NewLine);
            textBox1.Text = s;
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
