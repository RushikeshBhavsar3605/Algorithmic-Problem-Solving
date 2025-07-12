#include <bits/stdc++.h>
using namespace std;
int solve(string &s, int k)
{
    int n = s.size();
    if (n == 0)
        return 0;
    unordered_map<int, int> mp;
    int left = 0, totalCount = 0;
    for (int right = 0; right < n; right++)
    {
        mp[s[right]]++;
        while (mp.size() > k)
        {
            mp[s[left]]--;
            if (mp[s[left]] == 0)
                mp.erase(s[left]);
            left++;
        }
        totalCount += (right - left + 1);
    }
    return totalCount;
}
int countSubstr(string &s, int k)
{
    return solve(s, k) - solve(s, k - 1);
}
int main()
{
    string s = "abaaca";
    cout << countSubstr(s, 1) << endl;
    return 0;
}

/*
Problem: Count Number of Substrings with Exactly K Distinct Characters.
*/