#include <iostream>

using namespace std;

typedef unsigned int integer;

int main()
{
  if (sizeof(integer) < 4)
    return -1;

  integer n,k;
  cin >> n >> k;

  integer reminders[3];
  reminders[0] = 1;
  reminders[1] = 1;

  for (integer i = 2; i < n; ++i)
  {
    reminders[i % 3] = (reminders[(i - 1) % 3] + reminders[(i - 2) % 3]) % k;
  }

  cout << reminders[(n - 1) % 3] << endl;

  return 0;
}
