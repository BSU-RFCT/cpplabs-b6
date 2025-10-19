#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const double x0 = -0.5;
    const double xn = 0.5;
    const double dx = 0.1;

    for (double x = x0; x <= xn + 1e-12; x += dx) {
        const double eps = 1e-6;
        double term = 1.0;
        double sum = 0.0;
        int n = 0;

        // 1/(1+x) = 1 - x + x^2 - x^3 + ...
        while (fabs(term) >= eps) {
            sum += term;
            term *= -x;
            n++;
        }

        double y_series = sum + (x - 1.0);
        double y_exact = 1.0 / (1.0 + x) + (x - 1.0);


        cout << "x = " << x
             << "  y_series = " << y_series
             << "  y_exact = " << y_exact
             << "  terms = " << n << endl;
    }

    return 0;
}
