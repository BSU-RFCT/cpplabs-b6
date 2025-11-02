#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

constexpr int N = 10000;

int A[N][N];
int B[N][N];

void printMatrix(int M[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(nullptr));

    cout << "Матрица A:\n";
    for (auto& i : A)
    {
        for (int& j : i)
        {
            j = rand() % 100;
            cout << j << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            int mx = -1e9;
            for (int x = max(0, i - 2); x <= i; x++)
                for (int y = max(0, j - 2); y <= j; y++)
                    mx = max(mx, A[x][y]);

            B[i][j] = mx;
        }

    cout << "\nМатрица B:\n";
    printMatrix(B);
}
