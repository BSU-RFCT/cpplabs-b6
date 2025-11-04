#include <iostream>
using namespace std;

bool isPowerOfTwo(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

int main()
{
    int x;
    int currentLen = 0;
    int maxLen = 0;
    cout << "Введите последовательность чисел (0 — конец ввода):\n";

    while (cin >> x && x != 0)
    {
        if (isPowerOfTwo(x))
        {
            currentLen++;
            if (currentLen > maxLen)
                maxLen = currentLen;
        }
        else
        {
            currentLen = 0;
        }
    }

    cout << "Наибольшая длина подряд идущих степеней двойки = " << maxLen << endl;
    return 0;
}
