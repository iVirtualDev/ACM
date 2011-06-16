#include <iostream>
#include <vector>

using namespace std;

bool try_find_augmenting_chain(
  const vector< vector<int> >& b_graph,
  vector<int>& matching,
  vector<bool>& used_postcards,
  int current_postcard)
{
  if (used_postcards[current_postcard])
    return false;
  used_postcards[current_postcard] = true;
  for (vector<int>::const_iterator it = b_graph[current_postcard].begin();
       it != b_graph[current_postcard].end(); ++it)
  {
    int to = *it;
    if ((matching[to] == -1) ||
        try_find_augmenting_chain(b_graph, matching, used_postcards, matching[to]))
    {
      matching[to] = current_postcard;
      return true;
    }
  }
  return false;
}

int main()
{
  int postcard_count, envelope_count, edges_count;
  cin >> postcard_count >> envelope_count >> edges_count;

  vector< vector<int> > bipartite_graph;
  bipartite_graph.resize(postcard_count);

  for (int i = 0; i < edges_count; ++i)
  {
    int from, to;
    cin >> from >> to;
    --from;
    --to;
    bipartite_graph[from].push_back(to);
  }

  vector<int> matching(envelope_count, -1);
  vector<bool> used_postcards(postcard_count, false);

  for (int current_postcard = 0; current_postcard < postcard_count; ++current_postcard)
  {
    used_postcards.assign(postcard_count, false);
    try_find_augmenting_chain(bipartite_graph, matching, used_postcards, current_postcard); 
  }

  int count = 0;
  for (int i = 0; i < matching.size(); ++i)
    if (matching[i] != -1)
      ++count;

  cout << count << endl;
  for (int i = 0; i < matching.size(); ++i)
    if (matching[i] != -1)
      cout << (matching[i] + 1) << ' ' << (i + 1) << endl;

  return 0;
}
