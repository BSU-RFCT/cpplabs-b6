#include <iostream>
#include <cstring>
using namespace std;

void insert(char* S, const char* SS, int n)
{
    char temp[256];
    strcpy(temp, S + n);
    strcpy(S + n, SS);
    strcat(S, temp);
}

int main()
{
    char s[256] = "3+ 5+(x+ 2)” -> “3 + 5 + (x + 2)";
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '+')
        {
            if (i > 0 && s[i - 1] != ' ')
            {
                insert(s, " ", i);
                i++;
            }
            if (s[i + 1] != ' ' && s[i + 1] != '\0')
            {
                insert(s, " ", i + 1);
            }
        }
        i++;
    }

    cout << "Результат: " << s << endl;
    return 0;
}
