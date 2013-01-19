#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

const char* digits =
    " - "
    "| |"
    "   "
    "| |"
    " - "

    "   "
    "  |"
    "   "
    "  |"
    "   "

    " - "
    "  |"
    " - "
    "|  "
    " - "

    " - "
    "  |"
    " - "
    "  |"
    " - "

    "   "
    "| |"
    " - "
    "  |"
    "   "

    " - "
    "|  "
    " - "
    "  |"
    " - "

    " - "
    "|  "
    " - "
    "| |"
    " - "

    " - "
    "  |"
    "   "
    "  |"
    "   "

    " - "
    "| |"
    " - "
    "| |"
    " - "

    " - "
    "| |"
    " - "
    "  |"
    " - "
    ;

const int DIGIT_SIZE = 15;
const int ROW_SIZE = 3;

const int ROW_COUNT = 5;
const int COL_COUNT = 3;

char get(int digit, int row, int column)
{
    assert(digit >= 0);
    assert(digit < 10);
    assert((row >= 0) && (row < 5));
    assert((column >= 0) && (column < 3));

    return digits[digit * DIGIT_SIZE + row * ROW_SIZE + column];
}

int main()
{
    int k, s;
    cin >> k >> s;

    int row_sizes[] = { 1, k, 1, k, 1, 0 };
    int col_sizes[] = { 1, k, 1, 0 };

    string numbers;
    cin >> numbers;

    int row_index = 0;
    int row_left = row_sizes[row_index];

    while (row_index < ROW_COUNT)
    {
	for (unsigned int i = 0; i < numbers.size(); ++i)
	{
	    int col_index = 0;
	    int col_left = col_sizes[col_index];
	    while (col_index < COL_COUNT)
	    {
		cout << get(numbers[i] - '0', row_index, col_index);
		--col_left;
		if (col_left == 0)
		{
		    ++col_index;
                    col_left = col_sizes[col_index];
		}
	    }
	    for (int j = 0; j < s; ++j)
	    {
		cout << ' ';
	    }
	}
	cout << endl;
	--row_left;
	if (row_left == 0)
	{
	    ++row_index;
	    row_left = row_sizes[row_index];
	}
    }
    return 0;
}
