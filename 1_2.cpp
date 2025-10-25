#include <iostream>
using namespace std;

bool ifInArea()
{
    double x, y;
    cout << "Введите x, y: ";
    cin >> x >> y;

    if ((x <= 0 && y < (-x*x + 2) && y >= x) || (x >= 0 && y < (-x*x + 2) && y <= x))
        return true;
    return false;
}

int main()
{
    if (ifInArea())
        cout << "Точка находится в синей области.\n";
    else
        cout << "Точка вне синей области.\n";

    return 0;
}
