﻿#include <iostream>
#include <cmath>
#include <ctime>
unsigned int start_time = clock();
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
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << half(a, b, eps) << endl << "Итераций: " << k << endl << search_time << "мс";
    return 0;
}