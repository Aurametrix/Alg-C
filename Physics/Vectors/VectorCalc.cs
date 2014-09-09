using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;


namespace Vectors
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public int current = 0;
        public double x1, x2, x3;
        public double y1, y2, y3;
        public double z1, z2, z3;
        public char choice = 'a';

        private void button1_Click(object sender, EventArgs e)
        {
            switch (current)
            {
                case 0:
                    textBox1.Text += "1";
                    break;
                case 1:
                    textBox2.Text += "1";
                    break;
                case 2:
                    textBox3.Text += "1";
                    break;
                default:
                    textBox1.Text += "1";
                    break;
            }
        }

        private void buttonRight_Click(object sender, EventArgs e)
        {
            if (current < 2)
                current++;
        }

        private void buttonLeft_Click(object sender, EventArgs e)
        {
            if (current > 0)
                current--;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            switch (current)
            {
                case 0:
                    textBox1.Text += "2";
                    break;
                case 1:
                    textBox2.Text += "2";
                    break;
                case 2:
                    textBox3.Text += "2";
                    break;
                default:
                    textBox1.Text += "2";
                    break;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            switch (current)
            {
                case 0:
                    textBox1.Text += "3";
                    break;
                case 1:
                    textBox2.Text += "3";
                    break;
                case 2:
                    textBox3.Text += "3";
                    break;
                default:
                    textBox1.Text += "3";
                    break;
            }
        }
        private void button4_Click(object sender, EventArgs e)
        {
            switch (current)
            {
                case 0:
                    textBox1.Text += "4";
                    break;
                case 1:
                    textBox2.Text += "4";
                    break;
                case 2:
                    textBox3.Text += "4";
                    break;
                default:
                    textBox1.Text += "4";
                    break;
            }
        }
        private void button5_Click(object sender, EventArgs e)
        {
            switch (current)
            {
                case 0:
                    textBox1.Text += "5";
                    break;
                case 1:
                    textBox2.Text += "5";
                    break;
                case 2:
                    textBox3.Text += "5";
                    break;
                default:
                    textBox1.Text += "5";
                    break;
            }
        }
        private void button6_Click(object sender, EventArgs e)
        {
            switch (current)
            {
                case 0:
                    textBox1.Text += "6";
                    break;
                case 1:
                    textBox2.Text += "6";
                    break;
                case 2:
                    textBox3.Text += "6";
                    break;
                default:
                    textBox1.Text += "6";
                    break;
            }
        }
        private void button7_Click(object sender, EventArgs e)
        {
            switch (current)
            {
                case 0:
                    textBox1.Text += "7";
                    break;
                case 1:
                    textBox2.Text += "7";
                    break;
                case 2:
                    textBox3.Text += "7";
                    break;
                default:
                    textBox1.Text += "7";
                    break;
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            switch (current)
            {
                case 0:
                    textBox1.Text += "8";
                    break;
                case 1:
                    textBox2.Text += "8";
                    break;
                case 2:
                    textBox3.Text += "8";
                    break;
                default:
                    textBox1.Text += "8";
                    break;
            }
        }

        private void button9_Click(object sender, EventArgs e)
        {
            switch (current)
            {
                case 0:
                    textBox1.Text += "9";
                    break;
                case 1:
                    textBox2.Text += "9";
                    break;
                case 2:
                    textBox3.Text += "9";
                    break;
                default:
                    textBox1.Text += "9";
                    break;
            }
        }

        private void button0_Click(object sender, EventArgs e)
        {
            switch (current)
            {
                case 0:
                    textBox1.Text += "0";
                    break;
                case 1:
                    textBox2.Text += "0";
                    break;
                case 2:
                    textBox3.Text += "0";
                    break;
                default:
                    textBox1.Text += "0";
                    break;
            }
        }

        private void buttonNeg_Click(object sender, EventArgs e)
        {
            switch (current)
            {
                case 0:
                    if (textBox1.Text.Length >= 1)
                    {
                        if (textBox1.Text[0] != '-')
                            textBox1.Text = '-' + textBox1.Text;
                        else
                            textBox1.Text = (-1 * Convert.ToDouble(textBox1.Text)).ToString();
                    }
                    break;
                case 1:
                    if (textBox2.Text.Length >= 1)
                    {
                        if (textBox2.Text[0] != '-')
                            textBox2.Text = '-' + textBox2.Text;
                        else
                            textBox2.Text = (-1 * Convert.ToDouble(textBox2.Text)).ToString();
                    }
                    break;
                case 2:
                    if (textBox3.Text.Length >= 1)
                    {
                        if (textBox3.Text[0] != '-')
                            textBox3.Text = '-' + textBox3.Text;
                        else
                            textBox3.Text = (-1 * Convert.ToDouble(textBox3.Text)).ToString();
                    }
                    break;
                default:
                    if (textBox1.Text.Length >= 1)
                    {
                        if (textBox1.Text[0] != '-')
                            textBox1.Text = '-' + textBox1.Text;
                        else
                            textBox1.Text = (-1 * Convert.ToDouble(textBox1.Text)).ToString();
                    }
                    break;
            }
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            switch (current)
            {
                case 0:
                    textBox1.Text = "";
                    break;
                case 1:
                    textBox2.Text = "";
                    break;
                case 2:
                    textBox3.Text = "";
                    break;
                default:
                    textBox1.Text = "";
                    break;
            }
        }

        private void buttonDec_Click(object sender, EventArgs e)
        {
            switch (current)
            {
                case 0:
                    textBox1.Text += ".";
                    break;
                case 1:
                    textBox2.Text += ".";
                    break;
                case 2:
                    textBox3.Text += ".";
                    break;
                default:
                    textBox1.Text += ".";
                    break;
            }
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            setValues();
            choice = 'a';
            clearValues();
        }

        private void buttonEquals_Click(object sender, EventArgs e)
        {
            y1 = Convert.ToDouble(textBox1.Text);
            y2 = Convert.ToDouble(textBox2.Text);
            y3 = Convert.ToDouble(textBox3.Text);

            switch (choice)
            {
                case 'a':
                    add();
                    break;
                case 's':
                    subtract();
                    break;
                case 'd':
                    dot();
                    break;
                case 'c':
                    cross();
                    break;
                default:
                    add();
                    break;
            }
        }
        private void setValues()
        {
            if (textBox1.Text.Length >= 1)
                x1 = Convert.ToDouble(textBox1.Text);
            else
                x1 = 0;
            if (textBox2.Text.Length >= 1)
                x2 = Convert.ToDouble(textBox2.Text);
            else
                x2 = 0;
            if (textBox3.Text.Length >= 1)
                x3 = Convert.ToDouble(textBox3.Text);
            else
                x3 = 0;
        }

        private void buttonSubtract_Click(object sender, EventArgs e)
        {
            setValues();
            choice = 's';
            clearValues();
        }

        private void buttonDot_Click(object sender, EventArgs e)
        {
            setValues();
            choice = 'd';
            clearValues();
        }

        private void buttonCross_Click(object sender, EventArgs e)
        {
            setValues();
            choice = 'c';
            clearValues();
        }
        private void add()
        {
            z1 = x1 + y1;
            z2 = x2 + y2;
            z3 = x3 + y3;
            textBox4.Text = "(" + z1.ToString() + ", " + z2.ToString() + ", " + z3.ToString() + ")";
        }
        private void subtract()
        {
            z1 = x1 - y1;
            z2 = x2 - y2;
            z3 = x3 - y3;
            textBox4.Text = "(" + z1.ToString() + ", " + z2.ToString() + ", " + z3.ToString() + ")";
        }
        private void dot()
        {
            double temp = x1 * y1 + x2 * y2 + x3 * y3;
            textBox4.Text = temp.ToString();
        }
        private void cross() // 23-32, 31-13, 12-21
        {
            z1 = x2 * y3 - x3 * y2;
            z2 = x3 * y1 - x1 * y3;
            z3 = x1 * y2 - x2 * y1;

            textBox4.Text = "(" + z1.ToString() + ", " + z2.ToString() + ", " + z3.ToString() + ")";
        }
        private void clearValues()
        {
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            current = 0;
        }

        private void buttonAC_Click(object sender, EventArgs e)
        {
            clearValues();
            textBox4.Text = "";
        }

        private void textBox1_MouseClick(object sender, MouseEventArgs e)
        {
            current = 0;
        }

        private void textBox2_MouseClick(object sender, MouseEventArgs e)
        {
            current = 1;
        }

        private void textBox3_MouseClick(object sender, MouseEventArgs e)
        {
            current = 2;
        }
    }
}
