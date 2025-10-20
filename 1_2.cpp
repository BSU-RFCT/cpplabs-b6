#include <iostream>

bool ifInArea()
{
    double x, y;
    std::cout << "Введите x, y: ";
    std::cin >> x >> y;

    return x >= -2 && y <= 1 && y >= x && y <= -x * x + 2;
}

int main()
{
    if (ifInArea())
        std::cout << "Точка находится в синей области.\n";
    else
        std::cout << "Точка вне синей области.\n";

    return 0;
}
