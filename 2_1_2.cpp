#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x;
    cout << "Введите число: ";
    cin >> x;

    int n, k;
    cout << "Введите n и k: ";
    cin >> n >> k;

    int pos = x.find_first_of(".,");
    if (pos == -1)
    {
        cout << "Нет дробной части." << endl;
        return 0;
    }

    string frac = x.substr(pos + 1);
    if (n - 1 + k > static_cast<int>(frac.size()))
    {
        cout << "Недостаточно цифр." << endl;
        return 0;
    }

    int sum = 0;
    for (int i = n - 1; i < n - 1 + k; i++)
        sum += frac[i] - '0';

    cout << "Сумма: " << sum << endl;
}
