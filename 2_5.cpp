#include <iostream>
using namespace std;

// Возвращает цифру на позиции n в последовательности 1011121314...
int digitAt(long long n) {
    long long len = 1;     // длина чисел в текущем блоке
    long long count = 9;   // количество чисел в блоке
    long long start = 1;   // первое число блока

    // Находим блок, в котором находится позиция n
    while (n > len * count) {
        n -= len * count;
        len++;
        count *= 10;
        start *= 10;
    }

    // Определяем число, которое содержит нужную цифру
    long long numberIndex = (n - 1) / len;
    long long number = start + numberIndex;

    // Индекс цифры внутри числа (0-индекс)
    long long digitIndex = (n - 1) % len;

    // Вычисляем цифру через деление и остаток
    long long pow10 = 1;
    for (long long i = 0; i < len - digitIndex - 1; i++)
        pow10 *= 10;

    int digit = static_cast<int>((number / pow10) % 10);
    return digit;
}

int main() {
    long long n;
    cout << "Введите n: ";
    cin >> n;

    int d = digitAt(n);
    cout << "Цифра на позиции " << n << " : " << d << endl;

    return 0;
}
