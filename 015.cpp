#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int points_count;
  cin >> points_count;

  vector<vector<int> > points_coordinates(101);
  for (int i = 0; i < points_count; ++i)
  {
    int x,y;
    cin >> x >> y;
    points_coordinates[x].push_back(y);
  }

  int best_area = 0;
  for (int x0 = 0; x0 < 100; ++x0)
  {
    for (int y0 = 0; y0 < 100; ++y0)
    {
      int y1 = 100;
      for (int x1 = x0 + 1; x1 <= 100; ++x1)
      {
        int area = (x1 - x0) * (y1 - y0);
        if (area > best_area)
        {
          best_area = area;
        }

        int new_y = -1;
        for (int i = 0; i < points_coordinates[x1].size(); ++i)
        {
          if ((points_coordinates[x1][i] > y0) &&
              (points_coordinates[x1][i] < y1))
          {
            if ((new_y == -1) ||
                (points_coordinates[x1][i] < new_y))
            {
              new_y = points_coordinates[x1][i];
            }
          }
        }
        if (new_y != -1)
          y1 = new_y;
      }
    }
  }
  cout << best_area << endl;

  return 0;
}
