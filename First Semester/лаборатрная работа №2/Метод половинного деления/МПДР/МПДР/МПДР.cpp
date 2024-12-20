#include <iostream>
#include <cmath>
const double eps = 1e-6;
using namespace std;
int k;
double  f(const double& x)
{
    return 0.25 * pow(x, 3) + x - 1.2502;
}

double half(double a, double b, double eps)
{
    double  x = (a + b) / 2;
    cout << x << endl;
    if ((fabs(f(a) - f(b)) <= eps) and (fabs(f(x)) <= eps)) 
        return (a + b) / 2;

    if (f(a) * f(x) <= 0.0)
        half(a, x, eps);
    else
        half(x, b, eps);
    k++;
}

int  main()
{
    setlocale(LC_ALL, "RU");
    double  a = 0;
    double  b = 2; 
    cout << half(a, b, eps) << endl << "Итераций: " << k;
    return 0;
}