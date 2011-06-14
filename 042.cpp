#include <iostream>
#include <vector>
#include <string>

using namespace std;

int get_cell_val(const vector<int>& table, int width, int x, int y)
{
  if (x < 0)
    return 0;
  if (y < 0)
    return 0;
  return table[x + y * width];
}

int& get_cell_ref(vector<int>& table, int width, int x, int y)
{
  return table[x + y * width];
}

int main()
{
  string x,y;
  getline(cin, x);
  getline(cin, y);

  if ((x.empty()) || (y.empty()))
  {
    cout << "Empty" << endl;
    return 0;
  }

  const int width = x.size();
  const int height = y.size();

  vector<int> table;
  table.resize(width * height);

  for (int row = 0; row < height; ++row)
  {
    for (int column = 0; column < width; ++column)
    {
      if (x[row] == y[column])
      {
        get_cell_ref(table, width, row, column) =
          get_cell_val(table, width, row - 1, column - 1) + 1;
      }
      else
      {
        get_cell_ref(table, width, row, column) =
          max(
            get_cell_val(table, width, row - 1, column),
            get_cell_val(table, width, row, column - 1)
          );
      }
    }
  }

  vector<char> result;
  int row = height - 1;
  int column = width - 1;
  while ((row >= 0) && (column >= 0))
  {
    if (x[row] == y[column])
    {
      result.push_back(x[row]);
      --row;
      --column;
    }
    else
    {
      if (get_cell_val(table, width, row - 1, column) > 
          get_cell_val(table, width, row, column - 1))
        --row;
      else
        --column;
    }
  }

  if (result.empty())
    cout << "Empty" << endl;
  else
  {
    for (int i = result.size() - 1; i >= 0; --i)
      cout << result[i];
    cout << endl;
  }
  return 0;
}
