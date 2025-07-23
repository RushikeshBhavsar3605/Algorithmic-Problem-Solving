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
    int removePairs(string &s, string pair, int score) {
        int result = 0;
        stack<char> st;

        iterate(it, s)
            if (it == pair[1] && !st.empty() && st.top() == pair[0]) {
                st.pop();
                result += score;
            }
            else
                st.push(it);

        s = "";
        while (!st.empty()) {
            s.push_back(st.top());
            st.pop();
        }

        return result;
    }

  public:
    int maximumGain(string s, int x, int y) {
        int result = 0;

        string pair = x > y ? "ab" : "ba";
        result += removePairs(s, pair, max(x, y));
        result += removePairs(s, pair == "ab" ? "ab" : "ba", min(x, y));

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