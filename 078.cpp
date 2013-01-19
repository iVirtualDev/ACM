#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void swapChars(string& str, int x, int y)
{
    char value = str[x];
    str[x] = str[y];
    str[y] = value;
}

int main()
{
    const char* NO_WORD = "no word";
    string word;
    cin >> word;

    if (word.size() >= 2)
    {
        const int last = word.length() - 1;
        for (int current = last - 1; current >= 0; current--)
        {
            bool finded = false;
            int argmin;

            for (int i = last; i > current; i--)
            {
                if (word[i] > word[current])
                {
                    if ((!finded) || (word[i] < word[argmin]))
                    {
                        finded = true;
                        argmin = i;
                    }
                }
            }

            if (finded)
            {
                swapChars(word, argmin, current);
                sort(word.begin() + current + 1, word.end());
                cout << word;
                return 0;
            }
        }
    }

    cout << NO_WORD;

    return 0;
}
