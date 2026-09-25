using System;
using System.Globalization;
using System.Text;

namespace Lab1Variant17
{
    internal static class Program
    {
        public static void Main()
        {
            Console.OutputEncoding = Encoding.UTF8;
            Console.WriteLine("Лаба 1. Вариант 17");

            try
            {
                SolveTask1();
                SolveTask2();
                SolveTask3();
            }
            catch (InvalidOperationException exception)
            {
                Console.WriteLine(exception.Message);
            }
        }

        private static void SolveTask1()
        {
            Console.WriteLine("\nЗадача 1");
            var n = ReadInt("n: ");
            var m = ReadInt("m: ");

            try
            {
                var sum = CalculateSum(ref n, ref m);
                Console.WriteLine($"n++ + m-- = {sum}, n = {n}, m = {m}");

                var isLess = CompareProduct(ref n, m);
                Console.WriteLine($"n * m < n++ = {isLess}, n = {n}, m = {m}");

                var isGreater = CompareNumbers(ref n, ref m);
                Console.WriteLine($"n-- > ++m = {isGreater}, n = {n}, m = {m}");
            }
            catch (OverflowException)
            {
                Console.WriteLine("Переполнение.");
            }

            var x = ReadDouble("x: ");
            var isAsinValid = IsAsinValid(x);

            if (isAsinValid)
            {
                var result = CalculateAsin(x);
                Console.WriteLine($"arcsin(x + x^2) = {result:G17} рад");
            }
            else
            {
                Console.WriteLine("arcsin не считается при таком x.");
            }
        }

        private static void SolveTask2()
        {
            Console.WriteLine("\nЗадача 2");
            var rightX = ReadRightX();
            var x = ReadDouble("x1: ");
            var y = ReadDouble("y1: ");

            var isInside = IsPointInside(x, y, rightX);
            Console.WriteLine($"Принадлежит: {isInside.ToString().ToUpperInvariant()}");
        }

        private static void SolveTask3()
        {
            Console.WriteLine("\nЗадача 3");
            Console.WriteLine("a = 1000, b = 0,0001");

            var floatResult = CalculateFraction(1000f, 0.0001f);
            var doubleResult = CalculateFraction(1000.0, 0.0001);

            Console.WriteLine($"float:  {floatResult:G9}");
            Console.WriteLine($"double: {doubleResult:G17}");
        }

        private static int CalculateSum(ref int n, ref int m)
        {
            return checked(n++ + m--);
        }

        private static bool CompareProduct(ref int n, int m)
        {
            return checked(n * m < n++);
        }

        private static bool CompareNumbers(ref int n, ref int m)
        {
            return checked(n-- > ++m);
        }

        private static bool IsAsinValid(double x)
        {
            var argument = x + x * x;
            return argument >= -1 && argument <= 1;
        }

        private static double CalculateAsin(double x)
        {
            return Math.Asin(x + x * x);
        }

        private static bool IsPointInside(double x, double y, double rightX)
        {
            var isInTop = x >= 0 && x <= rightX && y >= 2 && y <= 5;
            var isInBottom = x >= -7 && x <= 0 && y >= -5 && y <= -3;

            return isInTop || isInBottom;
        }

        private static float CalculateFraction(float a, float b)
        {
            var diff = a - b;
            var diff4 = (float)Math.Pow(diff, 4);
            var a2 = (float)Math.Pow(a, 2);
            var b2 = (float)Math.Pow(b, 2);
            var a3 = (float)Math.Pow(a, 3);
            var b3 = (float)Math.Pow(b, 3);
            var a4 = (float)Math.Pow(a, 4);
            var b4 = (float)Math.Pow(b, 4);

            var bracket = a4 + 6 * a2 * b2 - 4 * a * b3;
            var numerator = diff4 - bracket;
            var denominator = b4 - 4 * a3 * b;

            return numerator / denominator;
        }

        private static double CalculateFraction(double a, double b)
        {
            var diff = a - b;
            var diff4 = Math.Pow(diff, 4);
            var a2 = Math.Pow(a, 2);
            var b2 = Math.Pow(b, 2);
            var a3 = Math.Pow(a, 3);
            var b3 = Math.Pow(b, 3);
            var a4 = Math.Pow(a, 4);
            var b4 = Math.Pow(b, 4);

            var bracket = a4 + 6 * a2 * b2 - 4 * a * b3;
            var numerator = diff4 - bracket;
            var denominator = b4 - 4 * a3 * b;

            return numerator / denominator;
        }

        private static int ReadInt(string message)
        {
            while (true)
            {
                Console.Write(message);
                var input = ReadText();
                var isValid = int.TryParse(input, out var number);

                if (isValid)
                    return number;

                Console.WriteLine("Неверный ввод.");
            }
        }

        private static double ReadDouble(string message)
        {
            while (true)
            {
                Console.Write(message);
                var input = ReadText().Replace(',', '.');
                var isValid = double.TryParse(input, NumberStyles.Float,
                    CultureInfo.InvariantCulture, out var number);

                if (isValid && double.IsFinite(number))
                    return number;

                Console.WriteLine("Неверный ввод.");
            }
        }

        private static double ReadRightX()
        {
            while (true)
            {
                var rightX = ReadDouble("Правая граница сверху (x): ");

                if (rightX > 0)
                    return rightX;

                Console.WriteLine("Граница должна быть больше 0.");
            }
        }

        private static string ReadText()
        {
            var input = Console.ReadLine();

            if (input == null)
                throw new InvalidOperationException("Ввод закончен.");

            return input;
        }
    }
}
