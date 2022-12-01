#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// false = left true = right
bool choose(int l, int r, vector<int> arr)
{
    int len = arr.size();
    if (l - 1 < 0)
    {
        return true;
    }
    if (r + 1 == len)
    {
        return false;
    }
    if (arr[l - 1] > arr[r + 1])
    {
        return false;
    }
    return true;
}

int calculate(vector<int> arr)
{
    if (arr.size() == 1)
    {
        return arr[0];
    }
    int sum = 0;
    int middle = (arr.size()) / 2;

    vector<int> left;
    left.assign(arr.begin(), arr.begin() + middle);

    vector<int> right;
    right.assign(arr.begin() + middle, arr.end());

    int leftSum = calculate(left);
    int rightSum = calculate(right);

    sum = sum > leftSum ? sum : leftSum;
    sum = sum > rightSum ? sum : rightSum;

    int point = middle;
    int l = middle;
    int r = middle;
    for (int i = 0; i < arr.size(); i++)
    {
        int v = arr[point] * (r - l + 1);
        sum = sum > v ? sum : v;
        if (choose(l, r, arr))
        {
            r++;
            point = arr[r] > arr[point] ? point : r;
        }
        if (!choose(l, r, arr))
        {
            l--;
            point = arr[l] > arr[point] ? point : l;
        }
    }

    return sum;
}

int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        vector<int> arr;
        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        cout << calculate(arr) << "\n";
    }
    return 0;
}