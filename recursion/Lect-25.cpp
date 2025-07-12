#include <bits/stdc++.h>
using namespace std;
void solve(string &current, vector<string> &result, int index, int num)
{
    if (index == num)
    {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        if (!current.empty() && i == 1 && current.back() == '1')
            continue;
        current += to_string(i);
        solve(current, result, index + 1, num);
        current.pop_back();
    }
}
vector<string> generateBinaryStrings(int num)
{
    vector<string> result;
    string current;
    solve(current, result, 0, num);
    return result;
}
int main()
{
    vector<string> result = generateBinaryStrings(3);
    for (auto i : result)
        cout << i << endl;
    cout << endl;
    return 0;
}

/*
Problem: Generate all binary strings.
*/