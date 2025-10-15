#include <iostream>
#include <bitset>
using namespace std;

int main() {
    signed short int n;
    cout << "Введите число n (signed short int): ";
    cin >> n;

    cout << "Двоичное представление: " << bitset<16>(n) << endl;

    int bit0 = (n >> 0) & 1;
    int bit2 = (n >> 2) & 1;
    int bit15 = (n >> 15) & 1;

    cout << "Бит 0: " << bit0 << endl;
    cout << "Бит 2: " << bit2 << endl;
    cout << "Бит 15: " << bit15 << " (знаковый бит)" << endl;

    n ^= (1 << 1); // инверсия бита 1
    n ^= (1 << 7); // инверсия бита 7

    cout << "\nПосле инверсии битов 1 и 7:" << endl;
    cout << "Двоичное представление: " << bitset<16>(n) << endl;

    cout << "Бит 0: " << ((n >> 0) & 1) << endl;
    cout << "Бит 2: " << ((n >> 2) & 1) << endl;
    cout << "Бит 15: " << ((n >> 15) & 1) << " (знаковый бит)" << endl;

    return 0;
}
