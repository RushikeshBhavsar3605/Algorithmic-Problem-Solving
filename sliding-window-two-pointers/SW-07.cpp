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
    int helper(string &s, int k) {
        unordered_map<int, int> mp; // frequency in current window
        int result = 0;
        int low = 0;

        loop(high, 0, s.size()) {
            mp[s[high]]++; // expand window size

            // Shrink window size if mp size exceeds k
            while (mp.size() > k) {
                if (mp[s[low]] == 1)
                    mp.erase(s[low++]); // Remove char if count becomes 0
                else
                    mp[s[low++]]--; // Decrement and move left pointer
            }

            // All subarrays in length (high-low+1) with mp size <= k
            result += (high - low + 1);
        }

        return result;
    }

  public:
    int numberOfSubstrings(string s) {
        // use inclusion-exclusion: <= 3 minus <= 2
        return helper(s, 3) - helper(s, 2);
    }
};

int main() {
    Solution obj;
    cout << obj.numberOfSubstrings("abcabc") << endl;
    cout << obj.numberOfSubstrings("aaacb") << endl;
    cout << obj.numberOfSubstrings("abc") << endl;
    return 0;
}

/*
Problem: Number of Substrings Containing All Three Characters
*/