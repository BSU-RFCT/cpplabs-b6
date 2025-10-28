#include <iostream>
#include <cmath>
using namespace std;

double cross(double x1, double y1, double x2, double y2)
{
    return x1 * y2 - y1 * x2;
}

int main()
{
    double x1, y1, x2, y2, x3, y3;
    cout << "Введите x1, y1, x2, y2, x3, y3: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    constexpr double EPS = 1e-9;

    const double c1 = cross(x2 - x1, y2 - y1, -x1, -y1);
    const double c2 = cross(x3 - x2, y3 - y2, -x2, -y2);
    const double c3 = cross(x1 - x3, y1 - y3, -x3, -y3);

    const bool sameSign = (c1 >= -EPS && c2 >= -EPS && c3 >= -EPS) ||
                    (c1 <= EPS && c2 <= EPS && c3 <= EPS);

    if (sameSign)
        cout << "Точка (0,0) находится внутри или на границе треугольника" << endl;
    else
        cout << "Точка (0,0) не находится внутри треугольника" << endl;

    return 0;
}
