using System;
using System.ComponentModel;
using System.IO;
using System.Net;
using System.Threading;

class Download
{
    private string url, op_folder;
    private bool result = false;
    public bool False { get; private set; }
    public Download(string url, string op)
    {
        if (string.IsNullOrEmpty(url)) throw new ArgumentNullException("url");
        if (string.IsNullOrEmpty(op)) throw new ArgumentNullException("op_folder");
        this.url = url;
        this.op_folder = op;
    }
    public bool StartDownload()
    {
        int ch = 0;
        try
        {
            System.IO.Directory.CreateDirectory(Path.GetDirectoryName(op_folder));
            if (File.Exists(op_folder))
            {
                ch = 1;
                Console.WriteLine("This file already exists do you want to replace it? (Enter 0 for yes else 1 for no) : ");
                ch = Convert.ToInt32(Console.ReadLine());
                if (ch == 0)
                {
                    File.Delete(op_folder);
                }
            }
            if (ch == 0)
            {
                using (WebClient client = new WebClient())
                {
                    var ur = new Uri(url);
                    Console.WriteLine(@"Downloading file:");
                    client.DownloadFileAsync(ur, op_folder);
                }
            }
            return true;
        }
        catch (Exception e)
        {
            Console.WriteLine("Was not able to download the file!");
            Console.Write(e);
            return false;
        }
    }
    public static bool DownloadFile(string url, string op)
    {
        return new Download(url, op).StartDownload();
    }


    static void Main(string[] args)
    {
        DateTime time = DateTime.Now;
        string format = "ddMMMyy";
        string s = time.ToString(format);
        Console.WriteLine("Enter valid url : ");
        string str = Console.ReadLine();
        string k = "Summary" + s;
        Console.WriteLine("Enter output folder directory : ");
        string b = Console.ReadLine();
        var success = Download.DownloadFile(str, b+k+".html");
        Console.WriteLine("Done  - success: " + success);
        Console.ReadLine();
    }
}