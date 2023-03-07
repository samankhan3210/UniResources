using Microsoft.VisualBasic.ApplicationServices;
using System;
using System.Data;
using System.Diagnostics.Contracts;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Reflection;
using System.Security.Cryptography.Xml;
using System.Security.Cryptography;
using System.Xml.Serialization;
using static System.Windows.Forms.AxHost;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Rebar;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.TextBox;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ToolTip;
using System.Xml.Linq;

namespace k190354_Q3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public void Populate()
        {
            string[] names = {"AUTOMOBILE ASSEMBLER", "AUTOMOBILE PARTS & ACCESSORIES", "CABLE & ELECTRICAL GOODS" , "CEMENT",
                              "CHEMICAL", "CLOSE - END MUTUAL FUND", "COMMERCIAL BANKS", "ENGINEERING", "EXCHANGE TRADED FUNDS",
                              "FERTILIZER", "FOOD & PERSONAL CARE PRODUCTS", "FUTURE CONTRACTS", "GLASS & CERAMICS", "INSURANCE",
                              "INV. BANKS / INV. COS. / SECURITIES COS.", "JUTE", "LEASING COMPANIES", "LEATHER & TANNERIES",
                              "MISCELLANEOUS", "MODARABAS", "OIL & GAS EXPLORATION COMPANIES", "OIL & GAS MARKETING COMPANIES",
                              "PAPER & BOARD", "PHARMACEUTICALS", "POWER GENERATION & DISTRIBUTION", "PROPERTY",
                              "REAL ESTATE INVESTMENT TRUST", "REFINERY", "SUGAR & ALLIED INDUSTRIES", "SYNTHETIC & RAYON",
                              "TECHNOLOGY & COMMUNICATION", "TEXTILE COMPOSITE", "TEXTILE SPINNING", "TEXTILE WEAVING", "TOBACCO",
                              "TRANSPORT", "VANASPATI & ALLIED INDUSTRIES", "WOOLLEN"};

            DataSet[] ds = new DataSet[names.Length];
            for (int i = 0; i < names.Length; i++)
            {
                string str = names[i];
                str = ' ' + str;
                str = str.Replace(" ", "_");
                str = str.Replace("/", "-");
                str = str.Replace(".", "");
                DataSet ds2 = new DataSet();
                ds2.ReadXml("D:\\Fast\\BS (CS)\\Semester 7\\IPT\\k190354_A1\\Q2\\Category\\" + str + "\\" + str + ".xml");
                ds[i] = ds2;
            }
            DataSet ds3 = new DataSet();
            foreach (DataSet d in ds)
            {
                foreach(DataTable t in d.Tables)
                { 
                    ds3.Merge(t);
                }
            }
            dataGridView3.DataSource = ds3.Tables[0];
        }

        public void Filter_Cat()
        {
            string? str = Category.SelectedItem.ToString();
            str = ' ' + str;
            str = str.Replace(" ", "_");
            str = str.Replace("/", "-");
            str = str.Replace(".", "");
            DataSet ds = new DataSet();
            ds.ReadXml("D:\\Fast\\BS (CS)\\Semester 7\\IPT\\k190354_A1\\Q2\\Category\\" + str + "\\" + str + ".xml");
            dataGridView3.DataSource = ds.Tables[0];
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (Category.SelectedItem != null)
            {
                Filter_Cat();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Category.SelectedIndex = -1;
            Category.Text = "Filter by Category";
            Populate();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Populate();
        }
    }
}