#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    constexpr int SIZE = 256;
    char input[SIZE];
    int freq[256] = {0};

    cout << "Enter text: ";
    cin.getline(input, SIZE);

    for (int i = 0; input[i] != '\0'; i++)
        freq[(unsigned char)input[i]]++;

    char result[SIZE];
    int pos = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (freq[(unsigned char)input[i]] <= 2)
            result[pos++] = input[i];
    }

    result[pos] = '\0';

    cout << "Result: " << result << endl;

    return 0;
}
