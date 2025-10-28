#include "2_3.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

bool isConsonant(char c)
{
    c = tolower(static_cast<unsigned char>(c));
    const char* consonants = "bcdfghjklmnpqrstvwxyz";
    return strchr(consonants, c) != nullptr;
}

int countConsonants(const char* word)
{
    int count = 0;
    for (int i = 0; word[i] != '\0'; i++)
        if (isConsonant(word[i]))
            count++;
    return count;
}

pair<int, vector<string>> findMaxConsonantWords(const string& input)
{
    int maxCounter = 0;
    vector<string> maxWords;

    constexpr int SIZE = 256;
    char buffer[SIZE];
    strncpy(buffer, input.c_str(), SIZE - 1);
    buffer[SIZE - 1] = '\0';

    const char* delimiters = " ,.!?;:\t\n";
    const char* token = strtok(buffer, delimiters);

    while (token != nullptr)
    {
        int counter = countConsonants(token);

        if (counter > maxCounter)
        {
            maxCounter = counter;
            maxWords.clear();
            maxWords.push_back(token);
        }
        else if (counter == maxCounter)
        {
            maxWords.push_back(token);
        }

        token = strtok(nullptr, delimiters);
    }

    return {maxCounter, maxWords};
}

#ifndef UNIT_TEST
int main()
{
    constexpr int SIZE = 256;
    char input[SIZE];

    cout << "Enter a sentence: ";
    cin.getline(input, SIZE);

    auto [maxCount, words] = findMaxConsonantWords(input);

    cout << "Maximum number of consonants in a word: " << maxCount << endl;
    if (!words.empty())
    {
        cout << "Word(s) with the maximum number of consonants: ";
        for (const auto& w : words)
            cout << w << " ";
        cout << endl;
    }
}
#endif