#include <iostream>
using namespace std;

constexpr int MAX = 10000;

void multiply(int result[], int& size, const int n)
{
    int carry = 0;
    for (int i = 0; i < size; ++i)
    {
        const int prod = result[i] * n + carry;
        result[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry > 0)
    {
        result[size] = carry % 10;
        carry /= 10;
        size++;
    }
}

int main()
{
    int N;
    cout << "Введите N (>=100): ";
    cin >> N;
    if (N < 0)
    {
        cout << "\033[31mОШИБКА: Введено недопустимое значение\n";
        throw invalid_argument("N");
    }
    cout << endl;

    int result[MAX];
    for (int& i : result)
        i = 0;

    result[0] = 1;
    int size = 1;

    for (int i = 2; i <= N; ++i)
        multiply(result, size, i);

    int count7 = 0;
    for (int i = 0; i < 1; ++i)
        if (result[i] == 7)
            count7++;

    cout << N << "! = ";
    for (int i = size - 1; i >= 0; --i)
        cout << result[i];
    cout << "\n\n";

    cout << "Количество цифр в " << N << "! = \033[36m" << size << endl;
    cout << "\033[0mЦифр 7 в " << N << "! = \033[36m" << count7 << endl;

    return 0;
}
