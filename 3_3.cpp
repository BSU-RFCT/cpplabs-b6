#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GRAY    "\033[90m"

void visualize(const int limit)
{
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    cout << "Начинаем решето Эратосфена до " << limit << "\n\n";

    auto printState = [&](const int current)
    {
        for (int i = 2; i <= limit; i++)
        {
            if (i == current)
                cout << YELLOW << "[" << i << "] " << RESET;
            else if (!isPrime[i])
                cout << RED << "X " << RESET;
            else
                cout << GREEN << i << " " << RESET;
        }
        cout << "\r";
        cout.flush();
    };

    for (int i = 2; i * i <= limit; i++)
    {
        if (isPrime[i])
        {
            cout << "\n>>> Берем " << YELLOW << i << RESET << " как простое. Убираем кратные...\n";
            this_thread::sleep_for(chrono::milliseconds(200));

            for (int j = i * i; j <= limit; j += i)
            {
                if (isPrime[j])
                {
                    isPrime[j] = false;
                    printState(i);
                    this_thread::sleep_for(chrono::milliseconds(150));
                }
            }
        }
    }

    cout << "\n\nПростые числа до " << limit << ":\n";
    for (int i = 2; i <= limit; i++)
        if (isPrime[i]) cout << GREEN << i << " " << RESET;
    cout << endl;
}

int main()
{
    int n;
    cout << "Введите верхний предел решета: ";
    cin >> n;
    visualize(n);
    return 0;
}
