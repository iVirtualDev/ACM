#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;

  if (n == 0)
  {
    cout << 1 << endl;
    return 0;
  }
  if (n == 1)
  {
    cout << 1 << endl;
    return 0;
  }

  const int vector_length = (n) / 3 + 1;
  vector<int> numbers[3];
  for (int i = 0; i < 3; ++i)
    numbers[i].resize(vector_length, 0); 

  numbers[0][0] = 1;
  numbers[1][0] = 1;

  vector<int>* current = &numbers[2];
  vector<int>* current_min1 = &numbers[1];
  vector<int>* current_min2 = &numbers[0];
  for (int k = 2; k <= n; ++k)
  {
    int additional = 0;
    for (int l = 0; l < vector_length; ++l)
    {
      int new_digit = (*current_min2)[l] + (*current_min1)[l] + additional;
      (*current)[l] = new_digit % 10;
      additional = new_digit / 10;
    }
    vector<int>* new_current = current_min2;
    current_min2 = current_min1;
    current_min1 = current;
    current = new_current;
  }

  int most_significant = vector_length - 1;
  while ((*current_min1)[most_significant] == 0)
    --most_significant;
    
  for (int i = most_significant; i >= 0; --i)
  {
    cout << (*current_min1)[i];
  }
  cout << endl;

  return 0;
}
