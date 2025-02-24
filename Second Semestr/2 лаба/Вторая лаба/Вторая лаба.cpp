#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    const int n = 7;
    int a[n];

    // вводим элементы массива
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (!cin) return 1;
    }

    // выводим элементы массива на экран
    cout << "Массив:\n";
    for (int i = 0; i < n; ++i)
        cout << " " << a[i];
    cout << "\n";

    int minValue = a[0];
    int minIndex = 0;
    int minNumber = 1;
    int minCount = 1;

    // Ищем минимальное значение и его индекс
    for (int i = 1; i < n; ++i) {
        if (a[i] < minValue) {
            minValue = a[i];
            minIndex = i;
            minNumber = i + 1;
            minCount = 1;
        }
        else if (a[i] == minValue) {
            minCount++;
        }
    }

    // Выводим результаты
    cout << "Минимальное значение: " << minValue << endl;
    cout << "Индекс минимального элемента: " << minIndex << endl;
    cout << "Номер минимального элемента: " << minNumber << endl;
    cout << "Количество минимальных элементов: " << minCount << endl;
    return 0;
}
