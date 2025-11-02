#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cout << "Введите n: ";
    cin >> n;

    long long digits = 1;
    long long count = 9;
    long long range = digits * count;

    while (n > range) {
        n -= range;
        digits++;
        count *= 10;
        range = digits * count;
    }

    long long start = pow(10, digits - 1);
    long long number = start + (n - 1) / digits;

    int index = (n - 1) % digits;
    for (int i = 0; i < digits - index - 1; i++) {
        number /= 10;
    }

    int digit = number % 10;

    cout << "Цифра на позиции: " << digit << endl;
    return 0;
}
