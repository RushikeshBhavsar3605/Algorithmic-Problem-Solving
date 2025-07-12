#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>

// STL shortcuts
#define all(x) begin(x), end(x)

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

class Solution {
  public:
    vector<string> partitionString(string s) {
        vector<string> result;
        map<string, int> mp;

        string curr = "";
        iterate(it, s) {
            curr += it;
            if (mp.find(curr) == mp.end()) {
                result.push_back(curr);
                mp[curr]++;
                curr = "";
            }
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<string> res = obj.partitionString("abbccccd");
    iterate(it, res) cout << it << " ";
    return 0;
}

/*
Problem:
*/