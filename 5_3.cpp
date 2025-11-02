#include <iostream>
using namespace std;

int** createMatrix(int& n, int& m)
{
    cout << "Введите размеры матрицы (n, m): ";
    cin >> n >> m;

    auto M = new int*[n];
    for (int i = 0; i < n; i++)
        M[i] = new int[m];

    cout << "Введите матрицу " << n << "*" << m << ":\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> M[i][j];

    return M;
}

void deleteMatrix(const int n, int** M) //! А вот если бы был vector...
{
    for (int i = 0; i < n; i++)
        delete[] M[i];
    delete[] M;
}

void sortMatrix(int** M, const int n, const int m)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (M[j][m - 1] < M[j + 1][m - 1])
                swap(M[j], M[j + 1]);
}

void printMatrix(int** M, const int n, const int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n, m;
    int** M = createMatrix(n, m);

    cout << "Ваша матрица:\n";
    printMatrix(M, n, m);

    cout << "Отсортированная по последним элементам:\n";
    sortMatrix(M, n, m);
    printMatrix(M, n, m);

    deleteMatrix(n, M);
}
