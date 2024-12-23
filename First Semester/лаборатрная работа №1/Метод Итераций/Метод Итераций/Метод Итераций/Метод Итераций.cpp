#include <iostream>
#include <cmath>
#include <ctime>
unsigned int start_time = clock();
using namespace std;

// epsilon
const double eps = 1e-6;

//кол-во итераций
int k = 0;

//Функция
double F(double x) {
    x = -0.25 * pow(x, 3) + 1.2502;
    return x;
}

//Функция метода итераций
double iter(double x, double eps) {
    double x0;
    do {
        x0 = x;
        x = F(x0);
        k++;
        cout << x << endl;
    } while (abs(x0 - x) >= eps);
    return x;
}

int main() {
    setlocale(LC_ALL, "RU");
    double a = 0;
    double b = 2;
    double x0 = (a+b) / 2;

    double x = iter(x0, eps);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "Корень: " << x << endl << "Итераций: " << k << endl << search_time << "мс";
    return 0;
}

