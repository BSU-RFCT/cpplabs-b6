#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    unsigned int n;
    vector<int> v;

    cout << "Enter N value: ";
    cin >> n;

    while (n > 0)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    reverse(v.begin(), v.end());

    sort(v.begin(), v.end());
    bool haveDuplicates = adjacent_find(v.begin(), v.end()) != v.end();
    if (haveDuplicates) cout << "Duplicates found";
    else cout << "No duplicates found";
}
