#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int main()
{
    enum Mode
    {
        Initialised = 0,
        Random = 1,
        Input = 2
    };

    cout << "Выберите режим заполнения массива:\n"
        << "0 - Определённый при инициализации\n"
        << "1 - Заполнение случайными числами\n"
        << "2 - Ввод с клавиатуры\n";

    int choice;
    cin >> choice;
    const Mode mode = static_cast<Mode>(choice);

    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    vector<int> arr(n);

    switch (mode)
    {
    case Initialised:
        for (int i = 0; i < n; ++i)
            arr[i] = i + 1;
        cout << "Массив инициализирован по умолчанию." << endl;
        break;

    case Random:
        {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dist(-99, 99);

            for (int i = 0; i < n; ++i)
                arr[i] = dist(gen);

            cout << "Массив заполнен случайными числами." << endl;
            break;
        }

    case Input:
        cout << "Введите элементы массива: ";
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        break;

    default:
        cout << "Ошибка: неизвестный режим!" << endl;
        return 1;
    }

    cout << "Содержимое массива: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    stable_partition(arr.begin(), arr.end(), [](int x) { return x < 0; });

    cout << "Содержимое массива: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}
