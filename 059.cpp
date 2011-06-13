#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cassert>

using namespace std;

int main()
{
  int cassete_length, tracks_count;
  cin >> cassete_length >> tracks_count;

  vector<int> tracks_length(tracks_count);
  for (int i = 0; i < tracks_count; ++i)
    cin >> tracks_length[i];

  sort(tracks_length.begin(), tracks_length.end(), greater<int>());

  int best_summ = -1;

  assert(tracks_count > 0);

  stack<int> possible_set;
  possible_set.push(0);
  int current_summ = tracks_length[0];

  while (true)
  {
    const int candidate = possible_set.top() + 1;
    if ((current_summ <= cassete_length) && (candidate < tracks_count))
    {
      if (current_summ > best_summ)
      {
        best_summ = current_summ;
      }
      //going down
      possible_set.push(candidate);
      current_summ += tracks_length[candidate];
    }
    else
    {
      if ((current_summ <= cassete_length) && (current_summ > best_summ))
      {
        best_summ = current_summ;
      }
      //going right
      while ((!possible_set.empty()) && (possible_set.top() + 1 >= tracks_count))
      {
        current_summ -= tracks_length[possible_set.top()];
        possible_set.pop();
      }
      if (possible_set.empty())
      {
        cout << best_summ << endl;
        break;
      }
      current_summ -= tracks_length[possible_set.top()];
      possible_set.top() += 1;
      current_summ += tracks_length[possible_set.top()];
    }
  }

  return 0;
}
