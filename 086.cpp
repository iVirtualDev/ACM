#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef int integer;
const int number_of_digits = 1000;

void multiply(vector<integer>& m, integer d)
{
  integer additional = 0;
  for (vector<integer>::iterator it = m.begin();
       it != m.end(); ++it)
  {
    integer new_digit = (*it) * d + additional;
    *it = new_digit % number_of_digits;
    additional = new_digit / number_of_digits;
  }
  if (additional > 0)
  {
    m.push_back(additional);
  }
}

int main()
{
  string decimal_factorial;
  getline(cin, decimal_factorial);

  vector<integer> factorial;
  for (int i = decimal_factorial.size() - 1; i >= 0; i -= 3)
  {
    int small = decimal_factorial[i] - '0';
    int middle = i - 1 >= 0 ? decimal_factorial[i - 1] - '0' : 0;
    int big = i - 2 >= 0 ? decimal_factorial[i - 2] - '0' : 0;
    factorial.push_back(small + middle*10 + big*100);
  }

  vector<int> result;
  result.push_back(1);

  int possible_n = 1;
  while (result != factorial)
  {
    ++possible_n;
    multiply(result, possible_n);

    if (possible_n > 500)
      return -1;
  }

  cout << possible_n << endl;


  return 0;
}
