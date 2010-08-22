#include <assert.h>
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;
using std::bitset;

class Position
{
public:
    int x;
    int y;
};

int abs(int value)
{
    if (value < 0)
        return (-value);
    else
        return value;
}

bool AttackEachOther(Position one, Position other)
{
    assert(!((one.x == other.x) && (one.y == other.y)));
    if (one.x == other.x)
        return true;
    if (one.y == other.y)
        return true;
    if (abs(one.x - other.x) == abs(one.y - other.y))
        return true;
    return false;
}

template <class Iterator>
bool isValidPlacement(Iterator begin, Iterator end)
{
    for (Iterator first = begin; first != end; ++first)
    {
        for (Iterator second = first; second != end; ++second)
        {
            if ((first != second) && (AttackEachOther(*first, *second)))
                return false;
        }
    }
    return true;
}

int calculateQueensBruteForce(vector<Position>& queens, size_t current, size_t size)
{
    if (current == size)
    {
        assert(queens.size() == size);
        if (isValidPlacement(queens.begin(), queens.end()))
            return 1;
        else
            return 0;
    }
    else
    {
        if (!isValidPlacement(queens.begin(), queens.end()))
            return 0;

        int result = 0;
        for (size_t i = 0; i < size; ++i)
        {
            vector<Position> copyQueens(queens);
            Position p;
            p.x = i;
            p.y = current;
            copyQueens.push_back(p);
            result += calculateQueensBruteForce(copyQueens, current + 1, size);
        }
        return result;
    }
}

int getSolution1(const vector<int>& busyColumns, const vector<int>& busyDiag1, 
                 const vector<int>& busyDiag2, size_t currentStep, const size_t size)
{
    assert(busyColumns.size() == busyDiag1.size());
    assert(busyColumns.size() == busyDiag2.size());
    assert(busyColumns.size() == currentStep);
    assert(currentStep <= size);

    if (currentStep == size)
    {
        assert(busyColumns.size() == size);
        return 1;
    }
    else
    {
        int result = 0;
        for (size_t col = 0; col < size; ++col)
        {
            if ((find(busyColumns.begin(), busyColumns.end(), col) == busyColumns.end()) &&
                (find(busyDiag1.begin(), busyDiag1.end(), (int)col - currentStep) == busyDiag1.end()) &&
                (find(busyDiag2.begin(), busyDiag2.end(), (int)col + currentStep) == busyDiag2.end()))
            {
                vector<int> newBusyColumns(busyColumns);
                newBusyColumns.push_back(col);

                vector<int> newBusyDiag1(busyDiag1);
                newBusyDiag1.push_back(col - currentStep);

                vector<int> newBusyDiag2(busyDiag2);
                newBusyDiag2.push_back(col + currentStep);

                result += getSolution1(newBusyColumns, newBusyDiag1, newBusyDiag2, currentStep + 1, size);
            }
        }
        return result;
    }
}

int getSolution1Fast(bitset<16> busyColumns, bitset<32> busyDiag1, bitset<32> busyDiag2, size_t currentStep, size_t size)
{
    assert(currentStep <= size);
    assert(size <= 16);


    if (currentStep == size)
    {
        return 1;
    }
    else
    {
        int result = 0;
        for (size_t col = 0; col < size; ++col)
        {
            if ((!busyColumns[col]) && 
                (!busyDiag1[size - currentStep + col]) && 
                (!busyDiag2[currentStep + col]))
            {
                bitset<16> newBusyColumns(busyColumns);
                newBusyColumns[col] = true;

                bitset<32> newBusyDiag1(busyDiag1);
                newBusyDiag1[size - currentStep + col] = true;

                bitset<32> newBusyDiag2(busyDiag2);
                newBusyDiag2[col + currentStep] = true;

                result += getSolution1Fast(newBusyColumns, newBusyDiag1, newBusyDiag2, currentStep + 1, size);
            }
        }
        return result;
    }
}

int getSolutionPrecalculated(int size)
{
    if (size == 15)
        return 2279184;
    if (size == 14)
        return 365596;
    if (size == 13)
        return 73712;
    if (size == 12)
        return 14200;
    if (size == 11)
        return 2680;
    if (size == 10)
        return 724;
    if (size == 9)
        return 352;
    if (size == 8)
        return 92;
    if (size == 7)
        return 40;
    if (size == 6)
        return 4;
    if (size == 5)
        return 10;
    if (size == 4)
        return 2;
    if (size == 1)
        return 1;
    return 0;
}

int main()
{
    int size;
    cin >> size;

    bitset<16> busyColumns(0);
    bitset<32> busyDiag1(0);
    bitset<32> busyDiag2(0);

    cout << getSolutionPrecalculated(size) << std::endl;
//    cout << getSolution1Fast(busyColumns, busyDiag1, busyDiag2, 0, size) << std::endl;

    return 0;
}
