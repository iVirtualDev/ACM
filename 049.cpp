#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

struct Integer
{
    int data;
    bool is_inf;

    Integer(int d):
	data(d),
	is_inf(false)
    {}

    static Integer get_inf();
};

Integer Integer::get_inf()
{
    Integer result(0);
    result.is_inf = true;
    return result;
}

Integer operator+(Integer left, Integer right)
{
    Integer result(0);
    result.data = left.data + right.data;
    result.is_inf = left.is_inf || right.is_inf;
    return result;
}

bool operator<(Integer left, Integer right)
{
    if (left.is_inf && right.is_inf)
	return false;
    if (left.is_inf)
	return false;
    if (right.is_inf)
	return true;
    return (left.data < right.data);
}

bool operator==(Integer left, Integer right)
{
    if (left.is_inf && right.is_inf)
	return true;
    if (left.is_inf)
	return false;
    if (right.is_inf)
	return false;
    return (left.data == right.data);
}

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

    vector<Integer> table(n + 1, Integer::get_inf());
    vector<Integer> newtable(n + 1, Integer::get_inf());
    table[1] = Integer(max(prices[n - 1], 0));

    for (int k = 1; k < n; ++k)
    {
	for (int i = 1; i < n + 1; ++i)
	{
	    if (k == n - 1)
	    {
		newtable[i] = max(table[i - 1] + Integer(prices[n - 1 - k]), Integer(0));
	    }
	    else
	    {
		newtable[i] = min(
			max(table[i - 1] + Integer(prices[n - 1 - k]), Integer(0)),
			table[i] + Integer(100));
	    }
	}
	newtable.swap(table);
	for (int i = 0; i < n + 1; ++i)
	{
	    newtable[i] = Integer::get_inf();
	}
    }
    for (int i = 0; i < n + 1; ++i)
    {
	if (table[i] == Integer(0))
	{
	    cout << i << endl;
	    return 0;
	}
    }
    cout << -1 << endl;
    return 0;
}
