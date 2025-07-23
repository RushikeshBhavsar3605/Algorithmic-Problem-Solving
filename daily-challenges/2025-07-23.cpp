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
    // Removes all occurrences of the given pair in one pass,
    // adds up score for each removal, and rebuilds the leftover string.
    int removePairs(string &s, string pair, int score) {
        int result = 0;
        stack<char> st;

        // Scan through s, use stack to detect and remove matching pairs
        iterate(it, s)
            if (it == pair[1] && !st.empty() && st.top() == pair[0]) {
                st.pop();        // remove the matched opening char
                result += score; // accumulate score
            }
            else
                st.push(it);     // keep unmatched chars

        // Reconstruct s from any leftover chars in stack
        s.clear();
        while (!st.empty()) {
            s.push_back(st.top());
            st.pop();
        }

        return result;
    }

  public:
    int maximumGain(string s, int x, int y) {
        int result = 0;

        // Decide which pair to remove first based on higher score
        string firstPair = x > y ? "ab" : "ba";
        string secondPair = firstPair == "ab" ? "ba" : "ab";

        // First pass: remove the more valuable pair
        result += removePairs(s, firstPair, max(x, y));

        // Second pass: remove the other pair on the leftover string
        result += removePairs(s, secondPair, min(x, y));

        return result;
    }
};

int main() {
    Solution obj;
    cout << obj.maximumGain("cdbcbbaaabab", 4, 5);
    return 0;
}

/*
Problem: Maximum Score From Removing Substrings
*/