#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string input;
    cout << "Введите число: ";
    cin >> input;

    int n, k;
    cout << "Введите n (номер первой цифры) и k (сколько суммировать): ";
    cin >> n >> k;

    string digits;
    for (char c : input)
        if (isdigit(c))
            digits += c;

    if (n < 1 || n > digits.size()) {
        cout << "Ошибка: n выходит за пределы числа." << endl;
        return 1;
    }

    if (n - 1 + k > digits.size()) {
        cout << "Недостаточно цифр для суммирования!" << endl;
        return 1;
    }

    int sum = 0;
    for (int i = n - 1; i < n - 1 + k; ++i)
        sum += digits[i] - '0';

    cout << "Сумма цифр: " << sum << endl;
    return 0;
}
