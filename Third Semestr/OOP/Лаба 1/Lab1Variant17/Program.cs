using System;

internal class Program
{
    private static void Main()
    {
        Console.WriteLine("Лаба 1. Вариант 17");
        DoTask1();
        DoTask2();
        DoTask3();
    }

    private static void DoTask1()
    {
        Console.WriteLine("\nЗадача 1");
        int n = ReadInt("n: ");
        int m = ReadInt("m: ");

        try
        {
            checked
            {
                int sum = n++ + m--;
                Console.WriteLine($"n++ + m-- = {sum}, n = {n}, m = {m}");

                bool isLess = n * m < n++;
                Console.WriteLine($"n * m < n++ = {isLess}, n = {n}, m = {m}");

                bool isGreater = n-- > ++m;
                Console.WriteLine($"n-- > ++m = {isGreater}, n = {n}, m = {m}");
            }
        }
        catch (OverflowException)
        {
            Console.WriteLine("Слишком большие числа.");
        }

        double x = ReadDouble("x: ");
        double number = x + x * x;
        if (number >= -1 && number <= 1)
            Console.WriteLine("arcsin = " + Math.Asin(number));
        else
            Console.WriteLine("arcsin не считается.");
    }

    private static void DoTask2()
    {
        Console.WriteLine("\nЗадача 2");
        double right = ReadDouble("Правая граница сверху: ");
        while (right <= 0)
        {
            Console.WriteLine("Нужно число больше 0.");
            right = ReadDouble("Правая граница сверху: ");
        }

        double x = ReadDouble("x1: ");
        double y = ReadDouble("y1: ");
        bool isInTop = x >= 0 && x <= right && y >= 2 && y <= 5;
        bool isInBottom = x >= -7 && x <= 0 && y >= -5 && y <= -3;
        bool isInside = isInTop || isInBottom;
        Console.WriteLine("Принадлежит: " + isInside.ToString().ToUpper());
    }

    private static void DoTask3()
    {
        Console.WriteLine("\nЗадача 3");
        float aFloat = 1000f;
        float bFloat = 0.0001f;
        float powerFloat = (float)Math.Pow(aFloat - bFloat, 4);
        float skobkaFloat = (float)Math.Pow(aFloat, 4)
            + 6 * (float)Math.Pow(aFloat, 2) * (float)Math.Pow(bFloat, 2)
            - 4 * aFloat * (float)Math.Pow(bFloat, 3);
        float znamenatelFloat = (float)Math.Pow(bFloat, 4)
            - 4 * (float)Math.Pow(aFloat, 3) * bFloat;
        float resultFloat = (powerFloat - skobkaFloat) / znamenatelFloat;

        double aDouble = 1000;
        double bDouble = 0.0001;
        double powerDouble = Math.Pow(aDouble - bDouble, 4);
        double skobkaDouble = Math.Pow(aDouble, 4)
            + 6 * Math.Pow(aDouble, 2) * Math.Pow(bDouble, 2)
            - 4 * aDouble * Math.Pow(bDouble, 3);
        double znamenatelDouble = Math.Pow(bDouble, 4)
            - 4 * Math.Pow(aDouble, 3) * bDouble;
        double resultDouble = (powerDouble - skobkaDouble) / znamenatelDouble;

        Console.WriteLine("float: " + resultFloat);
        Console.WriteLine("double: " + resultDouble);
    }

    private static int ReadInt(string text)
    {
        int number;
        Console.Write(text);
        while (!int.TryParse(Console.ReadLine(), out number))
            Console.Write("Введите число: ");
        return number;
    }

    private static double ReadDouble(string text)
    {
        double number;
        Console.Write(text);
        while (!double.TryParse(Console.ReadLine(), out number))
            Console.Write("Введите число: ");
        return number;
    }
}
