#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string seperate(string str)
{
    string res[4];
    int point = 0;
    for (int i = 0; i < 4; i++)
    {
        if (str[point] == 'x')
        {
            string temp = seperate(str.substr(point + 1));
            temp = 'x' + temp;
            res[i] = temp;
            point += temp.length();
        }
        else
        {
            string temp = "";
            temp = str[point];
            res[i] = temp;
            point += 1;
        }
    }
    return res[2] + res[3] + res[0] + res[1];
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        string t;
        cin >> t;
        cout << seperate(t) << "\n";
    }
    return 0;
}