using System;

double[,] m1 = new double[3, 3];
double[,] m2 = new double[3, 3];
double[,] m3 = new double[3, 3];

Console.Write("Enter elements in the first 3x3 matrix :\n");
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
        m1[i, j] = Convert.ToDouble(Console.ReadLine());
}

Console.Write("Enter elements in the second 3x3 matrix :\n");
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
        m2[i, j] = Convert.ToDouble(Console.ReadLine());
}

Console.Write("\nFirst matrix");
for (int i = 0; i < 3; i++)
{
    Console.Write("\n");
    for (int j = 0; j < 3; j++)
        Console.Write(m1[i, j] + " ");
}

Console.Write("\n\nSecond matrix");
for (int i = 0; i < 3; i++)
{
    Console.Write("\n");
    for (int j = 0; j < 3; j++)
        Console.Write(m2[i, j] + " ");
}

Console.Write("\n\nSum of both matrices");
for (int i = 0; i < 3; i++)
{
    Console.Write("\n");
    for (int j = 0; j < 3; j++)
    {
        m3[i, j] = m1[i, j] + m2[i, j];
        Console.Write(m3[i, j] + " ");
    }
}