#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int sequence_size;
  cin >> sequence_size;

  vector<int> sequence(sequence_size);
  for (int i = 0; i < sequence_size; ++i)
  {
    cin >> sequence[i];
  }

  vector<int> original_sequence(sequence_size);
  int max = sequence_size;

  while (max > 0)
  {
    int current = 0;
    while (sequence[current] != 0)
    {
      ++current;
      if (current == sequence_size)
      {
        cout << -1 << endl;
        return 0;
      }
    }
    sequence[current] = -1;
    original_sequence[current] = max;
    for (int i = 0; i < current; ++i)
    {
      if (sequence[i] > 0)
        --sequence[i];
    }
    --max;
  }
  for (int i = 0; i < sequence_size; ++i)
    cout << original_sequence[i] << '\t';
  cout << endl;

  return 0;
}
