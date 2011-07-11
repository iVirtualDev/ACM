#include <iostream>

using namespace std;

int get_number_of_operations(unsigned int number)
{
    if (number == 0)
        return 0;
    if (number == 1)
        return 1;

    if (number % 2 == 0)
        return 1 + get_number_of_operations(number / 2);
    else
    {
        int x = get_number_of_operations(number / 2);
        int y = get_number_of_operations((number / 2) + 1);

        if (x < y)
            return 2 + x;
        else
            return 2 + y;
    }
}

int main()
{
    unsigned int number;
    cin >> number;

    int result = get_number_of_operations(number);

    cout << result << endl;
    return 0;
}
