#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> stringToBinary(string &str)
{
    int len = str.size();
    vector<int> res(len);

    for (int i = 0; i < len; i++)
    {
        res[i] = str[i] == 'M';
    }
    return res;
}

/*
a*b = (a0*10 +a1)+(b0 * 10  +b1) = a0 b0  +  (a0 * b1 + b0 * a1) 10 + a1 * b1 = z0 * 10^2 + z1 * 10 + z2
z0 = a0 * b0
z2 = a1 * b1
z1 = (a0+a1)(b0+b1) - a0b0 - a1b1
(a0+a1)(b0+b1) = a0b0 + a0b1 + b0a1 + a1b1 = z0 + z1 + z2
*/

vector<int> addTo(vector<int> a, vector<int> b)
{
    int len = a.size();
    vector<int> res;
    for (int i = 0; i < len; i++)
    {
        if ((a[i] == 1 && b[i] == 0) || (a[i] == 0 && b[i] == 1))
        {
            res.push_back(1);
            continue;
        }
        res.push_back(0);
    }
    return res;
}

vector<int> multiple(vector<int> a, vector<int> b)
{
    int len = a.size();
    if (a.size() == 1)
    {
        vector<int> res;
        res.push_back(a[0] * b[0]);
        // printf("%d %d \n", a[0], b[0]);
        return res;
    }
    vector<int> _a0(a.begin(), a.begin() + (len / 2));
    vector<int> _b0(b.begin(), b.begin() + (len / 2));
    vector<int> z0 = multiple(_a0, _b0);
    vector<int> _a1(a.begin() + (len / 2), a.end());
    vector<int> _b1(b.begin() + (len / 2), b.end());
    vector<int> z2 = multiple(_a1, _b1);
    vector<int> z1 = multiple(addTo(_a0, _a1), addTo(_b0, _b1));
    z1 = addTo(z1, z0);
    z1 = addTo(z1, z2);

    z0.insert(z0.end(), z1.begin(), z1.end());
    z0.insert(z0.end(), z2.begin(), z2.end());
    return z0;
}

int isHug(vector<int> membersToBinary, vector<int> fansToBinary)
{
    vector<int> res = multiple(membersToBinary, fansToBinary);
    int len = res.size();
    // printf("res\n");
    for (int i = 0; i < len; i++)
    {
        // printf("%d ", res[i]);
        if (res[i] == 1)
        {
            // printf("\n");
            return 0;
        }
    }

    // printf("\n");
    return 1;
}

int hug(string members, string fans)
{
    string larger = members.length() >= fans.length() ? members : fans;
    string smaller = members.length() < fans.length() ? members : fans;

    int largeLen = larger.length();
    int smallerLen = smaller.length();

    vector<int> largerBinary = stringToBinary(larger);
    vector<int> smallerBinary = stringToBinary(smaller);

    int sum = 0;
    for (int i = 0; i + smallerLen <= largeLen; i++)
    {
        // printf("i = %d \n", i);
        vector<int> temp(largerBinary.begin() + i, largerBinary.begin() + i + smallerLen);
        sum += isHug(temp, smallerBinary);
    }
    return sum;
}

int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        string members;
        string fans;
        cin >> members;
        cin >> fans;
        cout << hug(members, fans) << "\n";
    }
    return 0;
}