#include <iostream>
#include <iterator>
#include <algorithm>
#include <assert.h>

using namespace std;

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

void insertIntoSortedArray(int* begin, int* end, int number)
{
    int* current = begin;
    while (current != end)
    {
        if ((number > (*current)) || ((*current == 0)))
            break;
        ++current;
    }

    while (current != end)
    {
        swap(number, *current);
        ++current;        
    }
}

template <class Iterator>
void getTrinityWhichGiveMaxProduct(Iterator begin, Iterator end, int* result)
{
    int maxPositive[3];
    maxPositive[0] = maxPositive[1] = maxPositive[2] = 0;

    int maxNegative[2];
    maxNegative[0] = maxNegative[1] = 0;

    int minNegative[3];
    minNegative[0] = minNegative[1] = minNegative[2] = 0;

    size_t positiveCount = 0;
    size_t negativeCount = 0;
    size_t zeroCount = 0;
    
    Iterator current = begin;
    while (current != end)
    {
        if ((*current) == 0)
        {
            ++zeroCount;
            ++current;
            continue;
        }

        if ((*current) > 0)
        {
            insertIntoSortedArray(maxPositive, maxPositive + 3, *current);            
            ++positiveCount;
        }
        else
        {
            insertIntoSortedArray(maxNegative, maxNegative + 2, -(*current));
            insertIntoSortedArray(minNegative, minNegative + 3, *current);
            ++negativeCount;
        }

        ++current;
    }

    if (positiveCount + negativeCount < 3)
    {
        size_t k = 0;
        for (size_t i = 0; i < positiveCount; ++i)
        {
            result[k] = maxPositive[i];
            ++k;
        }
        for (size_t i = 0; i < negativeCount; ++i)
        {
            result[k] = - maxNegative[i];
            ++k;
        }
        for (size_t i = k; i < 3; ++i)
        {
            result[i] = 0;
        }
    }
    else
    {
        if (positiveCount > 0)
        {
            long long cand1 = (long long)maxPositive[0] * (long long)maxPositive[1] * (long long)maxPositive[2];
            long long cand2 = (long long)maxPositive[0] * (long long)maxNegative[0] * (long long)maxNegative[1];
            if (cand1 > cand2)
            {
                result[0] = maxPositive[0];
                result[1] = maxPositive[1];
                result[2] = maxPositive[2];
            }
            else
            {
                result[0] = maxPositive[0];
                result[1] = -maxNegative[0];
                result[2] = -maxNegative[1];
            }
        }
        else
        {
            if (zeroCount > 0)
            {
                result[0] = 0;
                result[1] = minNegative[0];
                result[2] = minNegative[1];
            }
            else
            {
                result[0] = minNegative[0];
                result[1] = minNegative[1];
                result[2] = minNegative[2];
            }
        }
    }
}

int main()
{
    assert(sizeof(int) >= 4);
    assert(sizeof(long long) >= 8);

    int count;
    cin >> count;
    assert(count >= 3);

    if (count == 3)
    {
        copy(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, " "));
    }
    else
    {
        int result[3];
        getTrinityWhichGiveMaxProduct(istream_iterator<int>(cin), istream_iterator<int>(), result);
        cout << result[0] << ' ' << result[1] << ' ' << result[2] << endl;
    }
    return 0;
}
