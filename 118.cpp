#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
  int pancake_count;
  cin >> pancake_count;
  vector<int> sizes(pancake_count);
  for (int i = 0; i < pancake_count; ++i)
    cin >> sizes[i];

  deque<int> sequence_heads;
  for (vector<int>::const_reverse_iterator current_size = sizes.rbegin();
       current_size != sizes.rend(); ++ current_size)
  {
    deque<int>::iterator it = sequence_heads.begin();
    for (; it != sequence_heads.end(); ++it)
    {
      if ((*it) < (*current_size))
      {
        *it = (*current_size);
        break;
      }
    }
    if (it == sequence_heads.end())
      sequence_heads.push_back(*current_size);
  }
  cout << sequence_heads.size() << endl;
  return 0;
}
