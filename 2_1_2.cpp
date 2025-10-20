#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() { // Считает только цифры после запятой/точки
    string input;
    cout << "Введите число: ";
    cin >> input;

    int n, k;
    cout << "Введите n (номер первой цифры) и k (сколько суммировать): ";
    cin >> n >> k;

    // Найдем разделитель дробной части: запятая или точка
    size_t sep = input.find_first_of(".,");
    if (sep == string::npos || sep + 1 >= input.size()) {
        cout << "Ошибка: в числе нет дробной части." << endl;
        return 1;
    }

    string digits;
    for (size_t i = sep + 1; i < input.size(); ++i) {
        char c = input[i];
        if (isdigit(static_cast<unsigned char>(c))) digits += c;
    }

    if (digits.empty()) {
        cout << "Ошибка: после запятой нет цифр." << endl;
        return 1;
    }

    if (n < 1 || static_cast<size_t>(n) > digits.size()) {
        cout << "Ошибка: n выходит за пределы дробной части числа." << endl;
        return 1;
    }

    if (static_cast<size_t>(n - 1 + k) > digits.size()) {
        cout << "Недостаточно цифр для суммирования в дробной части!" << endl;
        return 1;
    }

    int sum = 0;
    for (int i = n - 1; i < n - 1 + k; ++i)
        sum += digits[static_cast<size_t>(i)] - '0';

    cout << "Сумма цифр (после запятой): " << sum << endl;
    return 0;
}
