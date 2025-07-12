#include <bits/stdc++.h>
using namespace std;
int beautySum(string s)
{
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        map<int, int> mp;
        multiset<int> st;
        for (int j = i; j < n; j++)
        {
            if (mp.find(s[j]) != mp.end())
                st.erase(st.find(mp[s[j]]));
            mp[s[j]]++;
            st.insert(mp[s[j]]);
            ans += (*st.rbegin() - *st.begin());
        }
    }
    return ans;
}
int main()
{
    cout << beautySum("aabcb") << endl;
    return 0;
}

/*
Problem: Sum of Beauty of all Substrings.
*/