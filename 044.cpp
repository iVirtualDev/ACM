#include <iostream>

using namespace std;

bool can_be_filled(int X, int Y, int size)
{
  if ((Y - 1) % size == 0)
  {
    if ((X - 1) % size == 0)
    {
      return true;
    }
    if (X % size == 0)
    {
      if (2 % size == 0)
	return true;
    }
  }
  if (Y % size == 0)
  {
    if ((X - 2) % size == 0)
    {
      return true;
    }
    if ((X - 1) % size == 0)
    {
      if (((Y - 1) % size == 0) && ((X - 1) % size == 0))
	return true;
      if ((Y - 2) % size == 0)
	return true;
    }
  }
  return false;
}

int main()
{
  int X,Y, count;
  cin >> X >> Y >> count;
  for (int i = 0; i < count; ++i)
  {
    int size;
    cin >> size;
    bool result = can_be_filled(X, Y, size) || can_be_filled(Y, X, size);
    if (result)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
