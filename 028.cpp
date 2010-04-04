#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

bool isFirstTeam(int playerNum, int teamCount)
{
    return (playerNum < teamCount);
}

void removeChild(vector<int>& circle, int index)
{
    assert(index < circle.size());
    circle.erase(circle.begin() + index);
}

bool firstTeamWins(int teamCount, int m)
{
    vector<int> circle(2*teamCount);
    for (int i = 0; i < circle.size(); i++)
        circle[i] = i;

    int current = 0;
    int firstTeamCount = teamCount, secondTeamCount = teamCount;

    while ((firstTeamCount > 0) && (secondTeamCount > 0)) 
    {
        assert(firstTeamCount + secondTeamCount == circle.size());

        current += (m - 1);
        current = current % (firstTeamCount + secondTeamCount);
        //std::cout << circle[current] << '\t';
        if (isFirstTeam(circle[current], teamCount))
            firstTeamCount--;
        else
            secondTeamCount--;

        removeChild(circle, current);
    }
    //std::cout << std::endl;

    return (firstTeamCount == teamCount);
}

int main()
{
    int teamCount;
    std::cin >> teamCount;

    int m = 2;
    while (!firstTeamWins(teamCount, m))
        m++;

    std::cout << m << std::endl;

    return 0;
}
