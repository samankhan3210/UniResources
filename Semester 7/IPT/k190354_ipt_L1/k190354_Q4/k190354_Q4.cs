using System;
using System.Drawing;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;

class TelephoneRecord
{
    public string[] Pname;
    public int[] Parea;
    public int[] Pno;

    public void Create_phoneBook()
    {
        Console.Write("How many records do you want to create : ");
        int n = Convert.ToInt32(Console.ReadLine());
        Pname = new string[n];
        Parea = new int[n];
        Pno = new int[n];
        for (int i = 0; i < n; i++)
        {
            Console.Write("Enter the name " + (i + 1) + " : ");
            string m = Console.ReadLine();
            this.Pname[i] = m;
            Console.Write("Enter area number " + (i + 1) + " : ");
            int a = Convert.ToInt32(Console.ReadLine());
            this.Parea[i] = a;
            Console.Write("Enter phone number " + (i + 1) + " : ");
            int j = Convert.ToInt32(Console.ReadLine());
            this.Pno[i] = j;
        }
        Console.Write("\n\n-------------------------------------------------------------\n\n");
    }

    public void Update()
    {
       Console.Write("Enter the phone number of the perosn who's data you want to update : ");
       int n = Convert.ToInt32(Console.ReadLine());
       int numIndex = Array.IndexOf(Pno, n);
       if (Pno.Contains(n))
       {
          Console.Write("Enter the new name of the person : ");
          string name = Console.ReadLine();
          Console.Write("Enter new area number of the person : ");
          int area = Convert.ToInt32(Console.ReadLine());
          Console.Write("Enter new phone number of the person : ");
          int number = Convert.ToInt32(Console.ReadLine());
          Pname[numIndex] = name;
          Parea[numIndex] = area;
          Pno[numIndex] = number;
          Console.Write("\n---------------Data is updated------------------\n\n");
        }
        else
        {
            Console.Write("---------------Invalid phone number------------------\n");
        }
    }
    public void Display()
    {
        Console.Write("Person Name\t\t\t\tArea Number\t\t\t\t\tPhone Number\n");
        for (int i = 0; i < Pname.Length; i++)
        {
            Console.Write(Pname[i]+"\t\t\t\t\t"+ Parea[i]+"\t\t\t\t\t\t"+Pno[i]+"\n");
        }
    }

    public void Insert()
    {
        int size = Pname.Length;
        Array.Resize(ref Pname, size + 1);
        Array.Resize(ref Parea, size + 1);
        Array.Resize(ref Pno, size + 1);
        Console.Write("Enter the name : ");
        Pname[size] = Console.ReadLine();
        Console.Write("Enter area number : ");
        Parea[size] = Convert.ToInt32(Console.ReadLine());
        Console.Write("Enter phone number : ");
        Pno[size] = Convert.ToInt32(Console.ReadLine());
    }
    static void Main()
    {
        Console.Write("Enter data in the telephone book\n");
        TelephoneRecord obj = new();
        obj.Create_phoneBook();
        int choice = 1;
        while (choice >= 1 && choice <= 3)
        {
            Console.Write("\nClick 1, 2, or 3 to :\n");
            Console.Write("1. Insert\n");
            Console.Write("2. Update\n");
            Console.Write("3. Display\n");
            Console.Write("Enter your choice : ");
            choice = Convert.ToInt32(Console.ReadLine());
            if (choice == 1)
            {
                obj.Insert();
            }
            else if (choice == 2)
            {
                obj.Update();
            }
            else if(choice == 3)
            {
                obj.Display();
            }
            else
            {
                Console.Write("Invalid Choice!!\n\n");
                break;
            }
        }
        
    }
}