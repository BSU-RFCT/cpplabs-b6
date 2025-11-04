#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Размерn n: ";
    cin >> n;

    if (n > 15)
    {
        cout << "Максимум 15.\n";
        return 0;
    }

    int A[15][15], B[15][15], B2[15][15], C[15][15];

    cout << "Матрица A:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cin >> A[i][j];
        for (int j = i + 1; j < n; j++)
            A[i][j] = 0;
    }

    cout << "Матрицу B:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cin >> B[i][j];
        for (int j = i + 1; j < n; j++)
            B[i][j] = 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            B2[i][j] = 0;
            for (int k = 0; k < n; k++)
                B2[i][j] += B[i][k] * B[k][j];
        }

    for (int i = 0; i < n; i++)
        B2[i][i] += 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B2[k][j];
        }

    cout << "\nМатрица C = A * (E + B^2):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
