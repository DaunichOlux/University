#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159265;

double f(double x) {
    return exp(x * cos(PI / 4)) * cos(x * sin(PI / 4));
}

double SummaN(double x) {
    int m;
    double sumN = 1;
    for (int n = m = 1; n <= 25; n++)
    {
        m *= n;
        sumN += ((cos(n * PI / 4)) / m) * pow(x, n);
    }
    return sumN;
}

double SummaE(double x) {
    double sumE = 1;
    double a = 1;
    for (int i = 1; a > 1e-4; i++) {
        a *= 1.0 * x / i;
        sumE += (cos(i * PI / 4)) * a;
    }
    return sumE;
}


int main()
{
    setlocale(LC_ALL, "RU");
    double x, a, b, sumE, k;
    int m;

    a = 0.1;
    b = 1;
    k = 10;
    x = 0.1;

    while (x <= b)
    {
        cout << "X=  " << x << "  Сумма N=  " << SummaN(x) << "  Сумма E=  " << SummaE(x) << "  f(x)=  " << f(x) << endl;
        x += (b - a) / k;
    }
    return 0;
}