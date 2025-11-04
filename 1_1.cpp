#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int s, t;
    double x;
    cout << "Введите s (целое), t (целое), x (вещественное): ";
    cin >> s >> t >> x;

    double result; // результат
    double xt, xs, ln_xt, sqrt_val;

    if (x == 0 && t <= 0 && x != 1)
    {
        cout << "Ошибка: выражение x^t не определено." << endl;
    }
    else if (x == 0 && s <= 0)
    {
        cout << "Ошибка: выражение x^s не определено." << endl;
    }
    else
    {
        xt = pow(x, t);
        xs = pow(x, s);

        if (xt <= 0)
        {
            cout << "Ошибка: логарифм не определён." << endl;
        }
        else
        {
            ln_xt = log(xt);
            if (ln_xt == 0)
            {
                cout << "Ошибка: знаменатель обращается в ноль." << endl;
            }
            else
            {
                if (1 + xs < 0)
                {
                    cout << "Ошибка: корень не определён." << endl;
                }
                else if (1 + xs == 0)
                {
                    cout << "Ошибка: деление на ноль." << endl;
                }
                else
                {
                    sqrt_val = sqrt(1 + xs);
                    result = pow(sin(xt), 2) / (ln_xt * sqrt_val);
                    cout << fixed << setprecision(10);
                    cout << "Значение функции y = " << result << endl;
                }
            }
        }
    }

    return 0;
}
