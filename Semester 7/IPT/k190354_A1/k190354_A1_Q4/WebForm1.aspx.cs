using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace k190354_A1_Q4
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            Loading_Data();
        }

        public void Loading_Cat()
        {
            string str = DropDownList1.SelectedItem.Text.ToString();
            if (!str.Equals("Filter by Category"))
            {
                str = ' ' + str;
                str = str.Replace(" ", "_");
                str = str.Replace("/", "-");
                str = str.Replace(".", "");
                DataSet ds = new DataSet();
                ds.ReadXml("D:\\Fast\\BS (CS)\\Semester 7\\IPT\\k190354_A1\\Q2\\Category\\" + str + "\\" + str + ".xml");
                GridView1.DataSource = ds;
                GridView1.DataBind();
            }
        }
        public void Loading_Data()
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
                foreach (DataTable t in d.Tables)
                {
                    ds3.Merge(t);
                }
            }
            GridView1.DataSource = ds3;
            GridView1.DataBind();
        }
        protected void Button1_Click(object sender, EventArgs e)
        {
            Loading_Cat();
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            DropDownList1.SelectedIndex = -1;
            Loading_Data();
        }
    }
}