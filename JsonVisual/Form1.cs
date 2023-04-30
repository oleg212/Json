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
        addright,
        addnext,
        mod
    };
    public partial class Form1 : Form
    {
        rfJson JSONobj = new rfJson();
        ButtonObserver obs = new ButtonObserver();
        mode param;
        int i = 1;
        public Form1()
        {
            InitializeComponent();
        }

        private void открытьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                string str = dialog.FileName;
/*                string str = "C:\\Users\\ipnnr\\source\\repos\\Json\\Json\\test.json";*/
                JSONobj.ReadFromFile(str);
                paint();
                /*                label1.Text = s;
                                label1.Refresh();*/
                obs.SetButtons(JSONobj, GoNext, GoRight, GoBack, GoUp, button1, button5);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            JSONobj.GoNext();
            paint();
            obs.SetButtons(JSONobj, GoNext, GoRight, GoBack, GoUp, button1, button5);
        }

        private void button2_Click(object sender, EventArgs e)
        {
                JSONobj.GoRight();
                paint();
            obs.SetButtons(JSONobj, GoNext, GoRight, GoBack, GoUp, button1, button5);
        }

        private void button3_Click(object sender, EventArgs e)
        {
                JSONobj.GoBack();
                paint();
            obs.SetButtons(JSONobj, GoNext, GoRight, GoBack, GoUp, button1, button5);
        }

        private void button4_Click(object sender, EventArgs e)
        {
                JSONobj.GoUp();
                paint();
            obs.SetButtons(JSONobj, GoNext, GoRight, GoBack, GoUp, button1, button5);
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            param = mode.addright;
            comboBox1.Visible = true;
            label1.Visible = true;
            label2.Visible = true;
            button4.Visible = true;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            param = mode.addnext;
            comboBox1.Visible = true;
            label1.Visible = true;
            label2.Visible = true;
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
            obs.SetButtons(JSONobj, GoNext, GoRight, GoBack, GoUp, button1, button5);
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
            obs.SetButtons(JSONobj, GoNext, GoRight, GoBack, GoUp, button1, button5);
        }



        private void change()
        {
            switch (param)
            {
                case mode.addright:
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
                                    s.SetContent(" \"" + content + '"');
                                    JSONobj.AddRight(s);
                                    break;
                                }
                            case 1:
                                {
                                    rfValueInt s = new rfValueInt(key, depth);
                                    s.SetContent(' ' + content);
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
                case mode.addnext:
                    {
                        String key = textBox2.Text;
                        String content = textBox3.Text;
                        int depth = 1;
                        if (!JSONobj.empty())
                        {
                            depth = JSONobj.GetCur().GetDepth();
                        }
                        switch (comboBox1.SelectedIndex)
                        {
                            case 0:
                                {
                                    rfValueStr s = new rfValueStr(key, depth);
                                    s.SetContent(" \"" + content + '"');
                                    JSONobj.AddNext(s);
                                    break;
                                }
                            case 1:
                                {
                                    rfValueInt s = new rfValueInt(key, depth);
                                    s.SetContent(' ' + content);
                                    JSONobj.AddNext(s);
                                    break;
                                }
                            case 2:
                                {
                                    rfValueArr s = new rfValueArr(key, depth);
                                    JSONobj.AddNext(s);
                                    break;
                                }
                        }

                        break;
                    }
                case mode.mod:
                    {
                        String content = textBox3.Text;
                        if (JSONobj.GetCur().GetType() == "string ")
                            JSONobj.SetContent(" \"" + content + '"');
                        else
                            JSONobj.SetContent(" " + content);
                        break;
                    }
            }
        }

            private void paint()
        {
            if (radioButton1.Checked)
            {
                markout();

            }
            if (radioButton2.Checked)
            {
                string s = JSONobj.WriteCurRow();

                s = s.Replace("\n", Environment.NewLine);

                textBox1.Text = s;

            }
            textBox1.Refresh();
        }

        private void markout()
        {
            rfPointer point = new rfPointer();
            point.SetPointer(JSONobj);
            string s = "{\n";
            if (JSONobj.GetCur().equals(point.GetCur()))
                s += ">>";
            s += point.GetCur().To_String();
            point.GoRight();
            textBox1.ForeColor = Color.Red;
            while (point.HasUp())
            {
                    while (point.HasRight())
                    {
                    if (JSONobj.GetCur().equals(point.GetCur()))
                        s += ">>";
                    s += point.GetCur().To_String();
                        point.GoRight();
                    }
                    if (JSONobj.GetCur().equals(point.GetCur()))
                        s += ">>";
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

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            textBox2.Visible = true;
            textBox2.Clear();
            if (comboBox1.SelectedIndex != 2) { textBox3.Visible = true; textBox3.Clear(); }

        }
    }

    public class ButtonObserver
    {
        public void SetButtons(rfJson val, Button gn, Button gr, Button gb, Button gu, Button ar, Button an)
        {
            if (val.GetCur().GetType() == "array ")
                ar.Visible = true;
            else ar.Visible = false;
            if (val.HasNext()) gn.Visible = true;
            else gn.Visible = false;
            if (val.HasRight()) gr.Visible = true;
            else gr.Visible = false;
            if (val.HasBack()) { gb.Visible = true; an.Visible = true; }
            else { gb.Visible = false; an.Visible = false;}  
            if (val.HasUp()) gu.Visible = true;
            else gu.Visible = false;
        }
    }
}
