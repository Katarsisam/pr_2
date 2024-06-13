class Program
{
    static void Main()
    {
        int number, stepen1, stepen2;
        
        Console.Write("Number: ");
        number = int.Parse(Console.ReadLine());
        
        Console.Write("pow of Number: ");
        stepen1 = int.Parse(Console.ReadLine());
        
        Console.Write("pow of pow: ");
        stepen2 = int.Parse(Console.ReadLine());
        
        long result = (long)Math.Pow(number, stepen1);
        result = (long)Math.Pow(result, stepen2);
        
        int lastfigure = (int)(result % 10);
        
        Console.WriteLine("the last digit of number: " + lastfigure);
    }
}