using System;

class Program
{
    static (int, int, int) GenerEuclidAlg(int a, int b)
    {
        if (b == 0)
        {
            return (a, 1, 0);
        }
        else
        {
            int d, x, y;
            (d, x, y) = GenerEuclidAlg(b, a % b);
            return (d, y, x - (a / b) * y);
        }
    }

    static int FindMultIn(int d, int m)
    {
        int s, _;
        (_, s, _) = GenerEuclidAlg(d, m);
        return (s % m + m) % m; // Handling negative modulo result
    }

    static void Main()
    {
        int m, num;
        Console.WriteLine("Enter d,mod:");
        num = int.Parse(Console.ReadLine());
        m = int.Parse(Console.ReadLine());

        int s = FindMultIn(num, m);
        Console.WriteLine($"{num}^-1 mod {m} = {s}");
        Console.WriteLine($"{num} * {s} mod {m} = 1");
    }
}