using System;
using System.Diagnostics.Metrics;

Console.Write("Enter any string : ");
string str = Console.ReadLine();
Console.Write("Original string  = " + str);
str = str.ToUpper();
int len = str.Length - 1;
string reverse = "";
while (len >= 0)
{
    reverse = reverse + str[len];
    len--;
}

Console.WriteLine();
Console.Write("Reversed and Capatalized string  = " + reverse);