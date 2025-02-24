#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    const int n = 5;
    int a[n]; // минимальное число
    int k = 0;      // индекс минимального элемент

    // вводим элементы массива
    cout << "Введите элементы массива:\n";

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // переворачиваем
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        int r = a[i];
        a[i] = a[j];
        a[j] = r;
    }
    // выводим элементы массива на экран
    cout << "Массив:\n";
    for (int i = 0; i < n; ++i)
        cout << " " << a[i];
    cout << "\n";
}