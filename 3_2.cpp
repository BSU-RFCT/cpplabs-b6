#include <iostream>
#include <climits>  // для INT_MIN
using namespace std;

int main() {
    const int n = 3;
    int a[n][n] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int b[n][n];

    int row_max[n];
    int col_max[n];

    for (int i = 0; i < n; i++) {
        row_max[i] = INT_MIN;
        for (int j = 0; j < n; j++) {
            if (a[i][j] > row_max[i])
                row_max[i] = a[i][j];
        }
    }

    for (int j = 0; j < n; j++) {
        col_max[j] = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (a[i][j] > col_max[j])
                col_max[j] = a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = (row_max[i] > col_max[j]) ? row_max[i] : col_max[j];
        }
    }

    cout << "Матрица B:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }

    return 0;
}
