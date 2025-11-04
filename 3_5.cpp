#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Размер n: ";
    cin >> n;

    if (n > 15)
    {
        cout << "Максимум 15.\n";
        return 0;
    }

    int** A = new int*[n];
    int** B = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        A[i] = new int[i + 1];
        B[i] = new int[i + 1];
    }

    cout << "Матрица A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> A[i][j];

    cout << "Матрица B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> B[i][j];

    int** B2 = new int*[n];
    for (int i = 0; i < n; ++i)
        B2[i] = new int[n]();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k <= min(i, k); k++)
                if (k <= i && j <= k)
                    B2[i][j] += B[i][k] * B[k][j];

    for (int i = 0; i < n; i++)
        B2[i][i] += 1;

    int** C = new int*[n];
    for (int i = 0; i < n; ++i)
        C[i] = new int[n]();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k <= i; k++)
                C[i][j] += A[i][k] * B2[k][j];

    cout << "\nМатрица C = A * (E + B^2):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }


    for (int i = 0; i < n; i++)
    {
        delete[] A[i];
        delete[] B[i];
        delete[] B2[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] B2;
    delete[] C;

    return 0;
}
