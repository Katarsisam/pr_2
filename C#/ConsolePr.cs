using System;

class Program
{
    static void Main()
    {
        long x = 1;
        int p, X, a;
        
        Console.WriteLine("Print A: ");
        a = int.Parse(Console.ReadLine());
        
        do
        {
            Console.WriteLine("Print mod: ");
            p = int.Parse(Console.ReadLine());
            
            if (!IsPrime(p))
            {
                Console.WriteLine("Try again");
            }
        } while (!IsPrime(p));
        
        X = p - 1; 
        Console.WriteLine("Pow {0}", X);
        Console.WriteLine("a^x Mod({0}) = {1}", p, PowX(ref x, a, X) % p);
        PrintTheFermat(a, X, p);
    }

    static long PowX(ref long x, int a, int X)
    {
        int N = (int)Math.Floor(Math.Log(X,2) + 1);
        int MX = X;
        
        int[] binaryRep = new int[N];
        for (int i = 0; i < N; i++)
        {
            binaryRep[i] = MX % 2;
            MX /= 2;
        }
        
        for (int i = 0; i < N; i++)
        {
            x *= (long)Math.Pow(Math.Pow(a, (int)Math.Pow(2, i)), binaryRep[i]);
        }
        
        return x;
    }

    static bool IsPrime(int a)
    {
        if (a > 2)
        {
            for (int i = 2; i < a; i++)
            {
                if (a % i == 0)
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    static int FermatsTheorem(int number, int deductionModule)
    {
        if (number % deductionModule == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    static void PrintTheFermat(int number, int degree, int deductionModule)
    {
        Console.WriteLine("\nBy Fermat's theorem:\n");
        
        if (FermatsTheorem(number, deductionModule) == 0)
        {
            Console.WriteLine("{0}^{1} mod {2} = 0", number, degree, deductionModule);
        }
        else
        {
            Console.WriteLine("{0}^{1} mod {2} = {0}^{3} mod {2} = 1", number, degree, deductionModule, degree - 1);
        }
    }
}