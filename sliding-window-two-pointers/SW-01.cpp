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
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> mp;
        int best = 0;
        int low = 0;

        loop(high, 0, s.size()) { // Expand window with 'high' pointer
            mp[s[high]]++;        // Include current character in map

            // If duplicate found, shrink window from the left
            while (mp[s[high]] == 2 && low < s.size())
                mp[s[low++]]--;

            best = max(best, high - low + 1); // Update max length if window is valid
        }

        return best;
    }
};

int main() {
    Solution obj;
    cout << obj.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << obj.lengthOfLongestSubstring("bbbbb") << endl;
    cout << obj.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}

/*
Problem: Longest Substring Without Repeating Characters
*/