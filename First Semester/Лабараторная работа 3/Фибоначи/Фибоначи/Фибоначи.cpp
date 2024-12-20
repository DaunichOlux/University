#include <iostream>
using namespace std;

int fib(int n){
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    cout << "Введите желаемое число фибоначи: " << endl; cin >> n;
    cout << fib(n);
    return 0;
}