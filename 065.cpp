#include <iostream>
#include <vector>

using namespace std;

struct time_record
{
  int time[3];
};

int main()
{
  int count;
  cin >> count;

  vector<time_record> timings(count);
  for (int i = 0; i < count; ++i)
  {
    cin >> timings[i].time[0] >> timings[i].time[1] >> timings[i].time[2];
  }

  vector<int> total_time(count);
  for (int i = 0; i < count; ++i)
  {
    if (i == 0)
      total_time[i] = timings[i].time[0];
    if (i == 1)
    {
      total_time[i] = min(
        total_time[i - 1] + timings[i].time[0],
        timings[i - 1].time[1]);
    }
    if (i == 2)
    {
      total_time[i] = min(
        min(
          total_time[i - 1] + timings[i].time[0],
          total_time[i - 2] + timings[i - 1].time[1]),
        timings[i - 2].time[2]);
    }
    if (i > 2)
    {
      total_time[i] = min(
        min(
          total_time[i - 1] + timings[i].time[0],
          total_time[i - 2] + timings[i - 1].time[1]),
        total_time[i - 3] + timings[i - 2].time[2]);
    }
  }
  cout << total_time[count - 1] << endl;

  return 0;
}
