#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
void solve(int index, string digits, map<int, string> &mappedDigits, string current, vector<string> &result)
{
    if (index == digits.size())
    {
        if (current.size() == digits.size())
            result.push_back(current);
        return;
    }
    for (int idx = index; idx < digits.size(); idx++)
    {
        string digitLetter = mappedDigits[digits[idx] - '0'];
        for (int i = 0; i < digitLetter.size(); i++)
            solve(idx + 1, digits, mappedDigits, current + digitLetter[i], result);
    }
}
vector<string> letterCombinations(string digits)
{
    if (digits.size() == 0)
        return {};
    vector<string> result;
    string current;
    map<int, string> mappedDigits = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}};
    solve(0, digits, mappedDigits, current, result);
    return result;
}
int main()
{
    vector<string> result = letterCombinations("23");
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}

/*
Problem: Letter Combinations of a Phone Number
*/