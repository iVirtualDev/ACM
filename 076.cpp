#include <string>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <assert.h>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int getDistanceToRight(const std::string& brackets)
{
    if (brackets.size() % 2 == 1)
        return -1;

    int distance = 0;
    int summ = 0;

    for (string::const_iterator it = brackets.begin();
         it != brackets.end();
         ++it)
    {
        if ((*it) == ')')
            summ--;
        if ((*it) == '(')
            summ++;
        if (summ < 0)
        {
            summ += 2;
            ++distance;
            assert(summ > 0);
        }
    }

    assert(summ % 2 == 0);
    distance += summ / 2;

    return distance;
}


int main()
{
    std::stringstream ss;
    copy(std::istream_iterator<char>(cin), std::istream_iterator<char>(), std::ostream_iterator<char>(ss));

    int distance = getDistanceToRight(ss.str());
    if (distance == -1)
        cout << "NO" << endl;
    else
        cout << distance << endl;
    return 0;
}

