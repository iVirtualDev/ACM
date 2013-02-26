#include <iostream>
#include <vector>
#include <limits>
#include <cassert>

using namespace std;

int intlog(int n)
{
    assert(n > 0);

    int result = 0;
    int k = 1;
    while (k <= n)
    {
	k *= 2;
	++result;
    }
    return (result - 1);
}

int pow2(int k)
{
    assert(k >= 0);
    return 1<<k;
}

// min[s*2**k, b)
double plus_min(const vector<vector<double> >& table, int s, int k, int b)
{
    double result = numeric_limits<double>::infinity();
    while (s * pow2(k) < b)
    {
	int next_k = intlog(b - s*pow2(k));
	int next_s = s * pow2(k - next_k) + 1;
	result = min(table[next_k][next_s - 1], result);
	k = next_k;
	s = next_s;
    }
    return result;
}

// min[a, s*2**k)
double minus_min(const vector<vector<double> >& table, int s, int k, int a)
{
    double result = numeric_limits<double>::infinity();
    while (a < s * pow2(k))
    {
	int next_k = intlog(s*pow2(k) - a);
	int next_s = s * pow2(k - next_k) - 1;
	result = min(result, table[next_k][next_s]);
	k = next_k;
	s = next_s;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<double> > numbers(intlog(n) + 1);
    for (int i = 0; i < n; ++i)
    {
	double num;
	cin >> num;
	numbers[0].push_back(num);
    }

    for (int k = 0; k + 1 < numbers.size(); ++k)
    {
	for (int i = 0; i < numbers[k].size(); i += 2)
	{
	    double x = numbers[k][i];
	    double y = x;
	    if (i + 1 < numbers[k].size())
	    {
		y = numbers[k][i + 1];
	    }
	    numbers[k + 1].push_back(min(x, y));
	}
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
	int a, b;
	cin >> a >> b;
	int k = intlog(b - a);
	const int two_pow_k = pow2(k);
	int s = a / two_pow_k;
	if (a % two_pow_k != 0)
	{
	    ++s;
	}
	double result = min(
	    plus_min(numbers, s, k, b),
	    minus_min(numbers, s, k, a));
	cout << result << endl;
    }

    return 0;
}
