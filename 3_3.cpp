#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> getPrimes(int n)
{
    if (n < 1) return {};

    const int limit = (n < 6) ? 15 : n * (log(n) + log(log(n)));

    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++)
        if (isPrime[i])
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;

    vector<int> primes;
    for (int i = 2; i <= limit && primes.size() < n; i++)
        if (isPrime[i])
            primes.push_back(i);

    return primes;
}


int main()
{
    cout << "Введите желаемое количество простых чисел: ";
    int n;
    cin >> n;
    vector<int> ans = getPrimes(n);
    for (auto& x : ans) cout << x << " ";
    cout << endl;
}
