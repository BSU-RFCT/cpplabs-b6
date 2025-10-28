#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

pair<long long, long long> convertNumberParts(string str)
{
    auto it = find(str.begin(), str.end(), '.');
    int j = distance(str.begin(), it);

    long long integer_part = stoll(str.substr(0, j));
    long long fractional_part = stoll(str.substr(j + 1));

    return {integer_part, fractional_part};
}

int main()
{
    string str;
    cout << "Введите вещественное число: ";
    cin >> str;

    pair<long long, long long> parts = convertNumberParts(str);

    if (parts.first > INT_MAX || parts.first < INT_MIN ||
        parts.second > INT_MAX || parts.second < INT_MIN)
    {
        cerr << "Ошибка: одно из чисел выходит за пределы типа int!" << endl;
    }
    else
    {
        cout << "Целая часть (hex): " << hex << parts.first << endl;
        cout << "Дробная часть (hex): " << hex << parts.second << endl;
    }

    return 0;
}
