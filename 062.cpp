#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cassert>

using namespace std;

int main()
{
    string regexp;
    getline(cin, regexp);

    vector<int> end_brackets(regexp.size(), -1);
    {
        stack<int> begin_brackets;
        for (int i = 0; i < regexp.size(); ++i)
        {
            if (regexp[i] == '[')
                begin_brackets.push(i);
            if (regexp[i] == ']')
            {
                end_brackets[begin_brackets.top()] = i;
                begin_brackets.pop();
            }
        }
    }

    string input;
    getline(cin, input);

    queue<int> possible;
    possible.push(0);

    for (int k = 0; k < input.size(); ++k)
    {
        queue<int> new_possible;
        while (!possible.empty())
        {
            const int current = possible.front();
            if (current < regexp.size())
            {
                if (regexp[current] == '[')
                {
                    assert(end_brackets[current] + 1 <= regexp.size());
                    assert(end_brackets[current] != -1);
                    possible.push(end_brackets[current] + 1);
                    assert(current + 1 <= regexp.size());
                    possible.push(current + 1);
                } else if (regexp[current] == ']')
                {
                    assert(current + 1 <= regexp.size());
                    possible.push(current + 1);
                } else
                {
                    if (input[k] == regexp[current])
                    {
                        assert(current + 1 <= regexp.size());
                        new_possible.push(current + 1);
                    }
                }
            }
            possible.pop();
        }
        if (new_possible.empty())
        {
            cout << "NO" << endl;
            return 0;
        }
        possible = new_possible;
    }
    while (!possible.empty())
    {
        const int current = possible.front();
        if (current == regexp.size())
        {
            cout << "YES" << endl;
            return 0;
        }
        else
        {
            if (regexp[current] == '[')
            {
                assert(end_brackets[current] + 1 <= regexp.size());
                assert(end_brackets[current] != -1);
                possible.push(end_brackets[current] + 1);
                assert(current + 1 <= regexp.size());
                possible.push(current + 1);
            } else if (regexp[current] == ']')
            {
                assert(current + 1 <= regexp.size());
                possible.push(current + 1);
            }
        }
        possible.pop();
    }

    cout << "NO" << endl;
    return 0;
}
