#include <iostream>
#include <cmath>
using namespace std;
const double pi = 3.14159;

double f(double x) {
    return fabs(exp(x * cos(pi / 4)) * cos(x * sin(pi / 4)));
}

double recursiveSummaN(double x, int n, int m, double sumN) {
    if (n > 25) {
        return sumN;
    }
    m *= n;
    sumN += ((cos(n * pi / 4)) / m) * pow(x, n);
    return recursiveSummaN(x, n + 1, m, sumN);
}

double SummaN(double x) {
    return recursiveSummaN(x, 1, 1, 1);
}

double SummaE_recursive(double x, double a = 1, int i = 1, double sumE = 1) {
    if (a <= 1e-4) {
        return sumE;
    }
    a *= 1.0 * x / i;
    sumE += (cos(i * pi / 4)) * a;
    return SummaE_recursive(x, a, i + 1, sumE);
}

double SummaE(double x) {
    return SummaE_recursive(x);
}

int main()
{
    setlocale(LC_ALL, "RU");
    double x, a, b, k;
    int m;

    a = 0.1;
    b = 1;
    k = 10;
    x = 0.1;

    while (x <= b)
    {
        cout << "X=  " << x << "|" << "  Сумма N=  " << SummaN(x) << "|" << "  Сумма E=  " << SummaE(x) << "|" << "  f(x)=  " << f(x) << endl;
        x += (b - a) / k;
    }
    return 0;
}
