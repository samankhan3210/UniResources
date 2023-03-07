using System.Xml;
using HtmlAgilityPack;
using System.Xml.Linq;

public class Program
{
    public void Create_Text_Files(HtmlDocument doc)
    {
        var nodes = doc.DocumentNode.SelectNodes("//div[@class='tab-content']/div/div[@class='table-responsive']/table");
        foreach (var n in nodes)
        {
            string str = n.SelectSingleNode(".//thead/tr/th/h4").InnerHtml;
            str = str.Replace(" ", "_");
            str = str.Replace("/", "-");
            str = str.Replace(".", "");
            string dir = "D:\\Fast\\BS (CS)\\Semester 7\\IPT\\k190354_A1\\Q2\\Category\\" + str;
            if (!Directory.Exists(dir))
            {
                Directory.CreateDirectory(dir);
            }
            string f = "D:\\Fast\\BS (CS)\\Semester 7\\IPT\\k190354_A1\\Q2\\Category\\" + str + "\\" + str + ".txt";
            System.IO.File.Create(f).Dispose();
            int i = 0;
            var scripts = n.SelectNodes("..//td[1]").Skip(1).ToArray();
            var price = n.SelectNodes("..//td[6]").Skip(1).ToArray();
            foreach (var s in scripts)
            {
                using (StreamWriter tw = System.IO.File.AppendText(f))
                {
                    tw.WriteLine(s.InnerText + " | " + price[i].InnerText);
                }
                i++;
            }
            Create_XML_Files(dir, f);
        }
    }

    public void Create_XML_Files(string dir, string file_name)
    {
        string[] f = file_name.Split(".txt");
        string f1 = f[0] + ".xml";
        if (System.IO.File.Exists(f1))
        {
            System.IO.File.Delete(f1);
        }
        XmlWriter.Create(f1).Dispose();
        XElement root = new XElement("xml");
        foreach (string ln in System.IO.File.ReadAllLines(file_name))
        {
            string[] fields = ln.Split('|');
            XElement record = new XElement("Scripts");
            int pos = 1;
            foreach (string sp in fields)
            {
                XElement field;
                if (pos == 1)
                {
                    field = new XElement("Script");
                    field.Add(sp);
                    pos++;
                }
                else
                {
                    field = new XElement("Price");
                    field.Add(sp);
                }
                record.Add(field); // add to parent node
            }
            root.Add(record); // add to root
        }
        root.Save(f1);
        System.IO.File.Delete(file_name);
    }

    public static void Main()
    {
        var path = "D:\\Fast\\BS (CS)\\Semester 7\\IPT\\k190354_A1\\Summary05Oct22.html";
        var doc = new HtmlDocument();
        doc.Load(path);

        string dir = "D:\\Fast\\BS (CS)\\Semester 7\\IPT\\k190354_A1\\Q2\\Category";
        if (!Directory.Exists(dir))
        {
            Directory.CreateDirectory(dir);
        }
        Program p = new Program();
        p.Create_Text_Files(doc);
    }
}