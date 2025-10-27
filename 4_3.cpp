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
    {
        if (isConsonant(word[i]))
            count++;
    }
    return count;
}

int main()
{
    constexpr int SIZE = 256;
    char input[SIZE];

    cout << "Enter a sentence: ";
    cin.getline(input, SIZE);

    int maxCounter = 0;
    vector<string> maxWords;

    char buffer[SIZE];
    strcpy(buffer, input);

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

    cout << "Maximum number of consonants in a word: " << maxCounter << endl;

    if (!maxWords.empty())
    {
        cout << "Word(s) with the maximum number of consonants: ";
        for (const auto& word : maxWords)
            cout << word << " ";
        cout << endl;
    }

    return 0;
}