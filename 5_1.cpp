#include <iostream>
using namespace std;

void factorial(const int n, long long &result)
{
    if (n <= 1)
        result = 1;
    else
    {
        factorial(n - 1, result);
        result *= n;
    }
}

double power(double x, int n)
{
    if (n == 0) return 1;
    if (n < 0) return 1.0 / power(x, -n);
    double result = 1;
    for (int i = 0; i < n; ++i)
        result *= x;
    return result;
}

void absolute_ptr(double x, double *res)
{
    *res = (x < 0) ? -x : x;
}

double series(const double x, const double eps, int& terms)
{
    double sum = 0;
    int k = 1;
    long long fact;

    factorial(2 * k + 1, fact);
    double term = power(-1, k + 1) * power(x, 2 * k - 1) /
                  ((2.0 * k - 1) * fact);

    double abs_term;
    absolute_ptr(term, &abs_term);

    while (abs_term >= eps)
    {
        sum += term;
        ++terms;
        ++k;

        factorial(2 * k + 1, fact);
        term = power(-1, k + 1) * power(x, 2 * k - 1) /
               ((2.0 * k - 1) * fact);

        absolute_ptr(term, &abs_term);
    }

    return sum;
}

int main()
{
    double x;
    cout << "Введите x (0 < x ≤ 1): ";
    cin >> x;

    constexpr double eps = 1e-6;
    int terms = 0;

    const double result = series(x, eps, terms);

    cout << "Сумма ряда: " << result << endl;
    cout << "Количество слагаемых: " << terms << endl;

    return 0;
}