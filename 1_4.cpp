#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

int main()
{
    int k, m, n, l;
    cout << "Введите k, l, m, n: ";
    cin >> k >> l >> m >> n;

    if (k < 1 || m < 1 || n < 1 || l < 1 || k > 8 || m > 8 || n > 8 || l > 8)
        throw invalid_argument("Координаты неверны.");

    const bool rook_attacks = (k == m) || (l == n);
    const bool queen_attacks = (k == m) || (l == n) || (abs(k - m) == abs(l - n));

    if (rook_attacks || queen_attacks)
        cout << "Угроза";
    else
        cout << "Угрозы нет";
}
