#include <iostream>

using namespace std;

int euler_function(int n)
{
  int result = n;
  for (int i = 2; i * i <= n; ++i)
  {
    if (n % i == 0)
    {
      while (n % i == 0)
      {
        n /= i;
      }
      result -= result / i;
    }
  }
  if (n > 1)
    result -= result / n;
  return result;
}

int main()
{
  int max_denominator;
  cin >> max_denominator;

  int count = 0;
  for (int denominator = 2; denominator <= max_denominator; ++denominator)
  {
    count += euler_function(denominator);
  }

  int number_of_questions = 0;
  int x = 1;
  while (count > x)
  {
    ++number_of_questions;
    x = 2 * x;
  }

  cout << number_of_questions << endl;
  return 0;
}
