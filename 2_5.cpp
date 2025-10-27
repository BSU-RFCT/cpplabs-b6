#include <iostream>
using namespace std;

int digitAt(long long n) {
    long long len = 1;
    long long count = 9;
    long long start = 1;

    while (n > len * count) {
        n -= len * count;
        len++;
        count *= 10;
        start *= 10;
    }

    long long numberIndex = (n - 1) / len;
    long long number = start + numberIndex;

    long long digitIndex = (n - 1) % len;

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
