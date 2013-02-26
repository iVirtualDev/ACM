#include <iostream>
#include <vector>
#include <limits>
#include <cassert>
#include <math.h>

using namespace std;

typedef pair<double, double> point_type;
double get_length(const point_type& a, const point_type& b)
{
    return sqrt((a.first - b.first)*(a.first - b.first) +
		(a.second - b.second)*(a.second - b.second));
}

int main()
{
    int n;
    double d;
    cin >> n >> d;

    vector<point_type> vertices;
    for (int i = 0; i < n; ++i)
    {
	double x,y;
	cin >> x >> y;
	vertices.push_back(make_pair(x, y));
    }


    vector<double> l1(n, numeric_limits<double>::infinity());
    vector<double> l2(n, numeric_limits<double>::infinity());

    vector<double>* lens[] = { &l1, &l2 };
    int currents[] = { 0, 1 };

    for (int k = 0; k < 2; ++k)
    {
	vector<double>& l = (*lens[k]);
	int current = currents[k];
	l[current] = .0;

	vector<bool> visited(n, false);
	int visited_count = 0;
	while (visited_count < n)
	{
	    assert(current != -1);
	    visited[current] = true;
	    ++visited_count;

	    double min_length = numeric_limits<double>::infinity();
	    int best_v = -1;
	    for (int i = 0; i < n; ++i)
	    {
		const double length = get_length(vertices[current], vertices[i]);
		assert(length >= 0);

		if ((!visited[i]) && (length <= d))
		{
		    l[i] = min(l[i], l[current] + length);
		}
		if ((!visited[i]) && (l[i] < min_length))
		{
		    min_length = l[i];
		    best_v = i;
		}
	    }
	    current = best_v;
	}
    }

    double min_len = numeric_limits<double>::infinity();
    for (int i = 0; i < n; ++i)
    {
	if ((vertices[i].first < 0) && (l1[i] + l2[i] < min_len))
	{
	    min_len = l1[i] + l2[i];
	}
    }
    cout << min_len << endl;
    return 0;
}
