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
  private:
    // Returns the count of the most frequent character in the current window
    int max_count(unordered_map<int, int> &mp) {
        int maxi = 0;
        iterate(it, mp)
            maxi = max(maxi, it.second);

        return maxi;
    }

  public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> mp; // frequency in current window
        int best = 0;
        int low = 0;

        loop(high, 0, s.size()) {
            mp[s[high]]++; // expand window

            while (high - low + 1 - max_count(mp) > k)
                if (mp[s[low]] == 1)
                    mp.erase(s[low++]); // remove char if count becomes 0
                else
                    mp[s[low++]]--; // decrement and move left pointer

            best = max(best, high - low + 1); // update max window size
        }

        return best;
    }
};

int main() {
    Solution obj;
    cout << obj.characterReplacement("ABAB", 2) << endl;
    cout << obj.characterReplacement("AABABBA", 1) << endl;
    return 0;
}

/*
Problem: Longest Repeating Character Replacement
*/