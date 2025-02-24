#include <iostream>
using namespace std;

const int N = 8;
int board[N][N];
int solutionsCount = 0;
bool isSafe(int row, int col) {
    // Проверка по столбцу
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) return false;
    }

    // Проверка по диагонали направо вверх
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) return false;
    }

    // Проверка по диагонали налево вверх
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) return false;
    }
    return true;
}

void printSolution() {
    setlocale(LC_ALL, "ru");
    cout << "Решение " << ++solutionsCount << ":" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 1) {
                cout << "Q ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueensUtil(int row) {
    if (row >= N) {
        printSolution();
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            solveNQueensUtil(row + 1);
            board[row][col] = 0;
        }
    }
}

void solveNQueens() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            board[i][j] = 0;
        }
    }
    solveNQueensUtil(0);
}

int main() {
    solveNQueens();
    return 0;
}
