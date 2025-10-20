#include <iostream>
#include <vector>
using namespace std;

bool isPrime(const int num)
{
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i)
        if (num % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    cout << "Введите количество сверхпростых чисел: ";
    cin >> n;

    vector<int> primes;
    vector<int> superPrimes;

    int current = 2;
    while (superPrimes.size() < n)
    {
        if (isPrime(current))
        {
            primes.push_back(current);

            if (isPrime(primes.size()))
                superPrimes.push_back(current);
        }
        ++current;
    }

    cout << "Первые " << n << " сверхпростых чисел:\n";
    for (const int x : superPrimes)
        cout << x << " ";
    cout << endl;

    return 0;
}
