#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> prices;
    for (int i = 0; i < n; ++i)
    {
	int s;
	cin >> s;
	prices.push_back(-s);
    }

    if (n == 1)
    {
	if (prices[0] <= 0)
	{
	    cout << 1 << endl;
	}
	else
	{
	    cout << -1 << endl;
	}
	return 0;
    }

    vector<int> table(n + 1, -1);
    vector<int> newtable(n + 1, -1);
    table[1] = max(prices[n - 1], 0);

    for (int k = 1; k < n; ++k)
    {
	for (int i = 1; i < n + 1; ++i)
	{
	    if ((table[i] == -1) || (k == n - 1))
	    {
		if (table[i - 1] != -1)
		{
		    assert(table[i - 1] >= 0);
		    newtable[i] = max(table[i - 1] + prices[n - 1 - k], 0);
		}
	    }
	    else
	    {
		if (table[i - 1] == -1)
		{
		    assert(table[i] >= 0);
		    newtable[i] = table[i] + 100;
		}
		else
		{
		    assert(table[i - 1] >= 0);
		    assert(table[i] >= 0);
		    newtable[i] = min(
			max(table[i - 1] + prices[n - 1 - k], 0),
			table[i] + 100);
		}
	    }
	}
	newtable.swap(table);
	for (int i = 0; i < n + 1; ++i)
	{
	    newtable[i] = -1;
	}
    }
    for (int i = 0; i < n + 1; ++i)
    {
	if (table[i] == 0)
	{
	    cout << i << endl;
	    return 0;
	}
    }
    cout << -1 << endl;
    return 0;
}
