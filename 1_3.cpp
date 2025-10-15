#include <iostream>
#include <string>
using namespace std;

int main()
{
    double x1, x2, x3, x4;
    string n1 = "x1", n2 = "x2", n3 = "x3", n4 = "x4";
    int mode;

    cout << "Введите режим:\n1 - режим if\n2 - режим тернарного оператора" << endl;
    cin >> mode;
    cout << "Введите x1, x2, x3, x4: " << endl;
    cin >> x1 >> x2 >> x3 >> x4;

    if (mode == 1)
    {
        if (x1 > x2) { swap(x1, x2); swap(n1, n2); }
        if (x3 > x4) { swap(x3, x4); swap(n3, n4); }
        if (x2 < x3) { swap(x2, x3); swap(n2, n3); }
    }
    else if (mode == 2)
    {
        double t;
        string s;
        x1 > x2 ? (void)(t = x1, x1 = x2, x2 = t, s = n1, n1 = n2, n2 = s) : (void)0;
        x3 > x4 ? (void)(t = x3, x3 = x4, x4 = t, s = n3, n3 = n4, n4 = s) : (void)0;
        x2 < x3 ? (void)(t = x2, x2 = x3, x3 = t, s = n2, n2 = n3, n3 = s) : (void)0;
    }
    else
    {
        cout << "Выбран неверный режим." << endl;
        return 1;
    }

    cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;
    cout << n1 << " " << n2 << " " << n3 << " " << n4 << endl;

    return 0;
}
