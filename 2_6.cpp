#include <iostream>
#include <iomanip>
using namespace std;

double poly_direct(const double x, int& addCount, int& mulCount)
{
    // y = -8x^8 + 6x^6 - 4x^4 + 2x^2 + 10
    double y = 10;

    // x²
    const double x2 = x * x;
    mulCount++;

    // 2x²
    double term = 2 * x2;
    mulCount++;
    y += term;
    addCount++;

    // -4x⁴
    term = -4 * x2 * x2;
    mulCount += 2;
    y += term;
    addCount++;

    // 6x⁶
    term = 6 * x2 * x2 * x2;
    mulCount += 3;
    y += term;
    addCount++;

    // -8x⁸
    term = -8 * x2 * x2 * x2 * x2;
    mulCount += 4;
    y += term;
    addCount++;

    return y;
}

double poly_horner(const double x, int& addCount, int& mulCount)
{
    // z = x^2: y = ((-8)z + 6)z + (-4))z + 2)z + 10
    const double z = x * x;
    mulCount++;
    double y = -8;
    y = y * z + 6;
    mulCount++;
    addCount++;
    y = y * z - 4;
    mulCount++;
    addCount++;
    y = y * z + 2;
    mulCount++;
    addCount++;
    y = y * z + 10;
    mulCount++;
    addCount++;
    return y;
}

int main()
{
    const double x0 = 1.0;
    const double xm = 2.0;
    const double dx = 0.25;

    cout << fixed << setprecision(6);
    cout << "   x\t\ty_direct\tadd\tmul\t|\ty_horner\tadd\tmul\n";
    cout << "--------------------------------------------------------------\n";

    for (double x = x0; x <= xm + 1e-9; x += dx)
    {
        int add1 = 0, mul1 = 0, add2 = 0, mul2 = 0;
        double y1 = poly_direct(x, add1, mul1);
        double y2 = poly_horner(x, add2, mul2);

        cout << setw(5) << x << "\t"
            << setw(12) << y1 << "\t" << add1 << "\t" << mul1
            << "\t|\t" << setw(10) << y2 << "\t" << add2 << "\t" << mul2 << "\n";
    }
    return 0;
}
