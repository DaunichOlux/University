#include <iostream>
#include <cmath>
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
    double a, b;
    double x = 0;
    cout << "Введите левую границу интервала (a): " << endl;
    cin >> a;
    cout << "Введите правую границу интервала (b): " << endl;
    cin >> b;

    if (F(a) * derivF2(a) > 0)
        x = a;
    else
        x = b;
    cout << NewtonMetod(x) << endl << "Количество итераций: " << k;

    return 0;
}