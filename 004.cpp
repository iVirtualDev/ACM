#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Athlet
{
    int mass;
    int strength;
};

bool operator<(const Athlet& left, const Athlet& right)
{
    if (left.mass == right.mass)
	return left.strength < right.strength;
    return left.mass < right.mass;
}

int main()
{
    int count;
    cin >> count;

    vector<Athlet> athlets;
    athlets.reserve(count);
    for (int i = 0; i < count; ++i)
    {
	Athlet a;
	cin >> a.mass >> a.strength;
	athlets.push_back(a);
    }

    sort(athlets.begin(), athlets.end());

    int total_mass = 0;
    int total_count = 0;
    for (int i = 0; i < count; ++i)
    {
	if (athlets[i].strength >= total_mass)
	{
	    total_mass += athlets[i].mass;
	    total_count += 1;
	}
    }
    cout << total_count << endl;
    return 0;
}
