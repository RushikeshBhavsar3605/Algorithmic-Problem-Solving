#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
void solve(int index, string num, int target, string curr, long long prev, long long res, vector<string> &ans)
{
    if (index == num.size())
    {
        if (res == target)
            ans.push_back(curr);
        return;
    }

    string st = "";
    long long currRes = 0;

    for (int i = index; i < num.size(); i++)
    {
        if (i > index && num[index] == '0')
            break;

        st += num[i];
        currRes = currRes * 10 + (num[i] - '0');

        if (index == 0)
            solve(i + 1, num, target, st, currRes, currRes, ans);
        else
        {
            solve(i + 1, num, target, curr + '+' + st, currRes, res + currRes, ans);
            solve(i + 1, num, target, curr + '-' + st, -currRes, res - currRes, ans);
            solve(i + 1, num, target, curr + '*' + st, prev * currRes, res - prev + (prev * currRes), ans);
        }
    }
}
vector<string> addOperators(string num, int target)
{
    vector<string> ans;
    solve(0, num, target, "", 0, 0, ans);
    return ans;
}
int main()
{
    vector<string> result = addOperators("232", 8);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}

/*
Problem: Expression Add Operators
*/