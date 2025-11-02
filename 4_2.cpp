#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

pair<long long, long long> convertNumberParts(char* str)
{
    char* dot = strchr(str, '.');

    long long integer_part = 0;
    long long fractional_part = 0;

    if (dot != nullptr)
    {
        *dot = '\0';
        integer_part = atoll(str);

        const char* fracStr = dot + 1;
        fractional_part = atoll(fracStr);

        *dot = '.';
    }
    else
    {
        integer_part = atoll(str);
        fractional_part = 0;
    }

    return {integer_part, fractional_part};
}

int main()
{
    char str[25];
    cout << "Введите вещественное число: ";
    cin >> str;

    const float x = atof(str);

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
        cout << "Кстати говоря, правильнее сказать " << hexfloat << x << endl;
        cout << "Вот такие пироги...";
    }

    return 0;
}
