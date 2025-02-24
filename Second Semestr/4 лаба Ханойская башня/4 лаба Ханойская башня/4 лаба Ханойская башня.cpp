#include <iostream>
using namespace std;

void displayTowers(int towers[3][10], int numDisks) {
    for (int i = numDisks - 1; i >= 0; --i) {
        for (int j = 0; j < 3; ++j) {
            if (towers[j][i] != 0) {
                cout << towers[j][i] << "\t";
            }
            else {
                cout << "|\t";  // добавляем символ стержня
            }
        }
        cout << endl;
    }
    cout << "A\tB\tC\n\n";
}

void moveDisk(int n, int from, int to, int aux, int towers[3][10], int numDisks) {
    if (n == 1) {
        for (int i = 0; i < numDisks; ++i) {
            if (towers[to][i] == 0) {
                for (int j = numDisks - 1; j >= 0; --j) {
                    if (towers[from][j] != 0) {
                        towers[to][i] = towers[from][j];
                        towers[from][j] = 0;
                        break;
                    }
                }
                break;
            }
        }
        displayTowers(towers, numDisks);
        return;
    }

    moveDisk(n - 1, from, aux, to, towers, numDisks);
    for (int i = 0; i < numDisks; ++i) {
        if (towers[to][i] == 0) {
            for (int j = numDisks - 1; j >= 0; --j) {
                if (towers[from][j] != 0) {
                    towers[to][i] = towers[from][j];
                    towers[from][j] = 0;
                    break;
                }
            }
            break;
        }
    }
    displayTowers(towers, numDisks);
    moveDisk(n - 1, aux, to, from, towers, numDisks);
}

int main() {
    setlocale(LC_ALL, "ru");
    int numRods = 3, numDisks;

    cout << "Введите количество дисков: ";
    cin >> numDisks;

    int towers[3][10] = { 0 };
    for (int i = numDisks; i > 0; --i) {
        towers[0][numDisks - i] = i;
    }

    displayTowers(towers, numDisks);
    moveDisk(numDisks, 0, 2, 1, towers, numDisks);

    return 0;
}
