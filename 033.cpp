#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

typedef pair<int, int> edge_type;

int main()
{
  int n;
  cin >> n;

  vector<edge_type> edges;

  int index = 0;
  for (int i = 0; i < 2 * (n - 1); ++i)
  {
    string line;
    cin >> line;

    if (i % 2 == 0)
    {
      const int input_size = (i / 2) + 1;
      assert(input_size == line.size());
      
      const int length = 2 * input_size - 1;
      for (int j = 0; j < input_size; ++j)
      {
	const int up_point = index + 2*j;
	const int down_point = up_point + length + 1;
	if (line[j] == '<')
	  edges.push_back(make_pair(up_point, down_point));
	else if (line[j] == '>')
	  edges.push_back(make_pair(down_point, up_point));
	else
	  assert(false);
      }

      index += length;
    }
    else
    {
      const int input_size = i + 1;
      assert(input_size == line.size());

      //const int length = input_size + 1;
      for (int j = 0; j < input_size; ++j)
      {
	const int right_point = index + j;
	const int left_point = right_point + 1;
	if (line[j] == '<')
	  edges.push_back(make_pair(right_point, left_point));
	else if (line[j] == '>')
	  edges.push_back(make_pair(left_point, right_point));
	else
	  assert(false);
      }
    }
  }

  vector<int> incoming(n*n, 0);
  vector<vector<int> > adjacency(n*n);

  for (vector<edge_type>::const_iterator it = edges.begin();
       it != edges.end(); ++it)
  {
    assert(it->first < n*n);
    assert(it->second < n*n);

    ++incoming[it->second];
    assert(incoming[it->second] <= 3);

    adjacency[it->first].push_back(it->second);
  }

  vector<int> numbers(n*n, 0);
  queue<int> q;
  for (int i = 0; i < n*n; ++i)
    if (incoming[i] == 0)
      q.push(i);

  int last_number = 1;
  while (!q.empty())
  {
    int next = q.front();
    for (int i = 0; i < adjacency[next].size(); ++i)
    {
      const int other_end = adjacency[next][i];
      assert(incoming[other_end] > 0);
      --incoming[other_end];
      if (incoming[other_end] == 0)
	q.push(other_end);
    }
    numbers[next] = last_number;
    ++last_number;
    q.pop();
  }

  if (last_number <= n*n)
  {
    cout << 0 << endl;
  }
  else if (last_number == n*n + 1)
  {
    cout << 1 << endl;
    int last_element = 0;
    int line_length = 1;
    for (int i = 0; i < n*n; ++i)
    {
      cout << numbers[i] << '\t';
      if (i == last_element)
      {
	cout << endl;
        line_length += 2;
        last_element += line_length;
      }
    }
  }
  else
    assert(false);

  return 0;
}
