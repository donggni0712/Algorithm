#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int C;

bool isFinish(int isChecked[12], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (isChecked[i] == 0)
            return false;
    }
    return true;
}

int match(vector<pair<int, int>> friends, int n, int isChecked[12], int start)
{
    if (isFinish(isChecked, n))
    {
        return 1;
    }
    int len = friends.size();
    if (start == len)
    {
        return 0;
    }
    int sum = 0;

    for (int i = start; i < len; i++)
    {
        int f = friends[i].first;
        int s = friends[i].second;
        if (isChecked[f] == 0 && isChecked[s] == 0)
        {
            isChecked[f] = 1;
            isChecked[s] = 1;
            sum += match(friends, n, isChecked, i);
            isChecked[f] = 0;
            isChecked[s] = 0;
        }
    }
    return sum;
}

int main()
{
    cin >> C;
    while (C--)
    {

        int isChecked[12] = {
            0,
        };
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> friendsPiars;
        for (int i = 0; i < m; i++)
        {
            pair<int, int> t;
            int a, b;
            cin >> a >> b;
            t.first = a;
            t.second = b;
            friendsPiars.push_back(t);
        }
        int res = match(friendsPiars, n, isChecked, 0);
        cout << res << '\n';
    }
}