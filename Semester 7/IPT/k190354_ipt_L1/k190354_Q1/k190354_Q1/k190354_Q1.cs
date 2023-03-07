using System;
using System.Diagnostics.Metrics;

double a, b, c, sum;
Console.Write("Enter first number : ");
a = Convert.ToDouble(Console.ReadLine());
Console.Write("Enter second number : ");
b = Convert.ToDouble(Console.ReadLine());
Console.Write("Enter third number : ");
c = Convert.ToDouble(Console.ReadLine());
sum = a + b + c;
Console.WriteLine(string.Format("Sum of {0}, {1}, and {2} is = {3}", a, b, c, sum));