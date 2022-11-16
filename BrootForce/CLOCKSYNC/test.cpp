#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int connectedClock[10][5] = {{0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}};
int length[10] = {3, 4, 4, 5, 5, 4, 3, 5, 5, 5};

bool isFit(int clock[16])
{
    bool res = true;

    for (int i = 0; i < 16; i++)
    {
        if (clock[i] != 12)
        {
            res = false;
        }
    }
    return res;
}

int fit(int num, int clock[16])
{
    int min = 987654321;
    if (num > 9)
    {
        if (isFit(clock))
        {
            return 0;
        }
        return min;
    }
    for (int i = 0; i < 4; i++)
    {
        int temp = i + fit(num + 1, clock);
        min = min > temp ? temp : min;

        for (int j = 0; j < length[num]; j++)
        {
            clock[connectedClock[num][j]] += 3;
            if (clock[connectedClock[num][j]] == 15)
            {
                clock[connectedClock[num][j]] = 3;
            }
        }
    }

    return min;
}

int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        int now[16] = {
            0,
        };
        for (int i = 0; i < 16; i++)
        {
            cin >> now[i];
        }
        int res = fit(0, now);
        res = res == 987654321 ? -1 : res;
        cout << res << '\n';
    }
    return 0;
}