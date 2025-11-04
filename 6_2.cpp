#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

union CarNumber
{
    unsigned int value;

    struct
    {
        unsigned int digits : 14;
        unsigned int letter1 : 5;
        unsigned int letter2 : 5;
        unsigned int region : 3;
    } parts;
};

CarNumber randomNumber()
{
    CarNumber num{};
    num.parts.digits = rand() % 10000;
    num.parts.letter1 = rand() % 26;
    num.parts.letter2 = rand() % 26;
    num.parts.region = 1 + rand() % 7;
    return num;
}

void printNumber(const CarNumber& num)
{
    cout << static_cast<char>('A' + num.parts.letter1)
        << static_cast<char>('A' + num.parts.letter2)
        << setw(4) << setfill('0') << num.parts.digits
        << "-" << num.parts.region;
}

int main()
{
    constexpr int N = 20;
    vector<CarNumber> cars(N);

    for (auto& c : cars)
        c = randomNumber();

    sort(cars.begin(), cars.end(),
         [](const CarNumber& a, const CarNumber& b)
         {
             return a.value < b.value;
         });

    cout << "Отсортированные номера:\n";
    for (const auto& c : cars)
    {
        printNumber(c);
        cout << endl;
    }

    cout << "\nПовторяющиеся номера:\n";
    bool found = false;
    for (int i = 1; i < N; ++i)
    {
        if (cars[i].value == cars[i - 1].value)
        {
            printNumber(cars[i]);
            cout << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Нет повторов.\n";

    return 0;
}
