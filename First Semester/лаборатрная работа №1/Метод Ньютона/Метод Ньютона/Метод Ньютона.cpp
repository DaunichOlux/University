#include <iostream>
#include <cmath>
#include <ctime>
unsigned int start_time = clock();
using namespace std;
// кол - во итераций
int k = 0;
const double eps = 1e-6;

// Функция
double F(double x) {
    return 0.25 * pow(x,3) + x - 1.2502;
}
// Производная функции
double derivF(double x) {
    return (0.75 * pow(x, 2)) + 1;
}
// Вторая производная функции
double derivF2(double x) {
    return 1.5 * x;
}
// Функция для метода Ньютона
double NewtonMetod(double x) {
    double h = F(x) / derivF(x);
    while (abs(h) >= eps)
    {
        ++k;
        h = F(x) / derivF(x);
        x = x - h;
    }
    return x;
}

int main() {
    setlocale(LC_ALL, "RU");
    double a = 0;
    double b = 2;
    double x = 0;

    if (F(a) * derivF2(a) > 0)
        x = a;
    else
        x = b;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << NewtonMetod(x) << endl << "Количество итераций: " << k << endl << search_time << "мс";

    return 0;
}