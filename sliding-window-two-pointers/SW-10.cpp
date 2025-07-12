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
    string minWindow(string s, string t) {
        unordered_map<int, int> mpt;
        iterate(it, t)
            mpt[it]++; // Map elements of t

        unordered_map<int, int> mps;
        int start = 0;
        int low = 0, cnt = 0, length = -1;

        loop(high, 0, s.size()) {
            mps[s[high]]++; // Expand window my mapping element in mps

            // Increase valid length if element matches, by including duplicates
            if (mpt.find(s[high]) != mpt.end() && mpt[s[high]] == mps[s[high]])
                cnt += mpt[s[high]];

            // Shrink window if excluding lower element is valid
            while ((mpt.find(s[low]) == mpt.end() || mpt[s[low]] < mps[s[low]]) && low < s.size())
                mps[s[low++]]--;

            // Update constraints if current length matches actual t string length
            if (cnt == t.size() && (length == -1 || high - low + 1 < length)) {
                start = low;
                length = (high - low + 1);
            }
        }

        if (length == -1)
            return "";
        else
            return s.substr(start, length);
    }
};

int main() {
    Solution obj;
    cout << obj.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << obj.minWindow("a", "a") << endl;
    cout << obj.minWindow("aa", "aa") << endl;
    cout << obj.minWindow("a", "aa") << endl;
    return 0;
}

/*
Problem: Minimum Window Substring
*/