#include <iostream>
#include <cmath>
#include <ctime>
unsigned int start_time = clock();
using namespace std;
//epsilon
const double eps = 1e-6;

//кол-во итераций
int k;

//Функция
double F(double x) {
    return 0.25 * pow(x, 3) + x - 1.2502;
}

//Функция метода половинного деления
double Fhalf(double a, double b) {
    double x, Fb, Fx;
    while (abs(b - a) >= eps)
    {
        x = (a + b) / 2;
        cout << x << endl;
        k++;

        Fb = F(b);
        Fx = F(x);

        if (Fb * Fx < 0)
            a = x;
        else
            b = x;
    }
    return x;
}

int main()
{
    setlocale(LC_ALL, "RU");
    double a = 0;
    double b = 2;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "Корень: " << Fhalf(a, b) << endl << "Итераций: " << k << endl << search_time << "мс";
    return 0;
}

