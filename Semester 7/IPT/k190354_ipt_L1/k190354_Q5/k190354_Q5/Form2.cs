﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace k190354_Q5
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            label6.Text = Convert.ToString(Form1.distance);
            label7.Text = Convert.ToString(Form1.radius);
            label8.Text = Convert.ToString(Form1.diagonal);
            label9.Text = Convert.ToString(Form1.circum);
            label10.Text = Convert.ToString(Form1.area);
        }
    }
}
