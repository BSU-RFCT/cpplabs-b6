#include <iostream>
using namespace std;

long long factorial(int n)
{
    return n <= 1 ? 1 : n * factorial(n - 1);
} //TODO: Сделвть некоторые процедурами

double power(double x, int n)
{
    if (n == 0) return 1;
    if (n < 0) return 1.0 / power(x, -n);
    double result = 1;
    for (int i = 0; i < n; ++i)
        result *= x;
    return result;
}

double absolute(double x)
{
    return (x < 0) ? -x : x;
}

double series(double x, double eps, int& terms)
{
    double sum = 0;
    double term;
    int k = 1;

    while (absolute(term) >= eps)
    {
        term = power(-1, k + 1) * power(x, 2 * k - 1) /
            ((2.0 * k - 1) * factorial(2 * k + 1));
        sum += term;
        ++terms;
        ++k;
    }

    return sum;
}

int main()
{
    double x;
    cout << "Введите x (0 < x ≤ 1): ";
    cin >> x;

    const double eps = 1e-6;
    int terms = 0;

    double result = series(x, eps, terms);

    cout << "Сумма ряда: " << result << endl;
    cout << "Количество слагаемых: " << terms << endl;

    return 0;
} //TODO: Починить, везде выдаёт ноль. Неявное преобразование типов а-ля float -> int???
