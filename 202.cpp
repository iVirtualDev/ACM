#include <cassert>
#include <iostream>

int main()
{
    const int maxN = 100;
    unsigned int table[maxN][maxN];

    for (unsigned int n = 0; n < maxN; n++)
    {
        if (n == 0)
            for (unsigned int s = 0; s < maxN; s++)
                table[n][s] = 1;
        else
        {
            for (unsigned int s = 0; s < maxN; s++)
            {
                if (s == 0)
                {
                    assert(n > 0);
                    table[n][s] = 0;
                }

                if (s == 1)
                {
                    assert(n > 0);
                    table[n][s] = 1;
                }

                if (s > 1)
                {
                    table[n][s] = 0;
                    for (unsigned int k = 0; k <= n / s; k++)
                        table[n][s] += table[n - k*s][s - 1];
                }
            }
        }
    }

    unsigned int n;
    std::cin >> n;
    assert(n < maxN);
    
    std::cout << table[n][n] << std::endl;
}
