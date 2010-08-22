#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <assert.h>

using namespace std;

long long howManyCablePieces(const vector<int>& cables, int size)
{
//    assert(size > 0);

    long long result = 0;
    for (vector<int>::const_iterator it = cables.begin();
         it != cables.end(); ++it)
    {
//        assert(*it >= 0);
        result += (*it) / size;
    }
    return result;
}

int getSolutionBruteForce(const vector<int>& cables, int piecesCount)
{
    long long canDoPiecesCount = 0;
    int size = 0;
    do
    {
        ++size;
        canDoPiecesCount = howManyCablePieces(cables, size);
    } while (canDoPiecesCount >= piecesCount);

    return (size - 1);
}

int getMaximum(const vector<int>& cables)
{
    int maxValue = 0;
    for (vector<int>::const_iterator it = cables.begin();
         it != cables.end(); ++it)
    {
        if (*it > maxValue)
            maxValue = *it;
    }
    return maxValue;
}


int main()
{
//  assert(sizeof(int) >= 4);

    int cablesCount;
    long long piecesCount;
    cin >> cablesCount >> piecesCount;

//    assert(cablesCount >= 1);
//    assert(piecesCount >= 1);

    vector<int> cables;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), insert_iterator<vector<int> >(cables, cables.end()));

//    assert(cables.size() == cablesCount);
    const int minValue = 0;
    const int maxValue = getMaximum(cables) + 1;

    int begin = minValue;
    int end = maxValue;

    while (begin + 1 != end)
    {
        int middle = (begin + end) / 2;
        long long canDoPiecesCount = howManyCablePieces(cables, middle);
        if (canDoPiecesCount >= piecesCount)
        {
            begin = middle;
        }
        else
        {
            end = middle;
        }
    }
    cout << begin << endl;

    return 0;
}
