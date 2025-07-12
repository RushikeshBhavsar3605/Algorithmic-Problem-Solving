#include <bits/stdc++.h>
using namespace std;
string frequencySort(string s)
{
    unordered_map<char, int> mp;
    priority_queue<pair<int, char>> maxHeap;
    for (auto &c : s)
        mp[c]++;
    for (auto &p : mp)
        maxHeap.push({p.second, p.first});
    s = "";
    for (; !maxHeap.empty(); maxHeap.pop())
        s.append(maxHeap.top().first, maxHeap.top().second);
    return s;
}
int main()
{
    cout << frequencySort("tree") << endl;
    return 0;
}

/*
Problem: Sort Characters By Frequency.
*/