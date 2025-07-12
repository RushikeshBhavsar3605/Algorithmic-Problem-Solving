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
    string longestSubsequenceRepeatedK(string s, int k) {
        auto isSubsequence = [&](string sub) -> bool {
            string target = "";
            loop(i, 0, k)
                target += sub;

            int it = 0;
            loop(i, 0, s.size()) {
                if (s[i] == target[it])
                    it++;
                if (it == target.size())
                    break;
            }

            return it == target.size();
        };

        // 1. Filter to characters that appear at least k times
        unordered_map<char, int> mp;
        iterate(it, s) mp[it]++;

        string hotChars = "";
        iterate(it, mp)
            if (it.second >= k)
                hotChars.push_back(it.first);

        sort(all(hotChars));

        // 2. BFS to find the longest, lexicographically largest subsequence
        string best = "";
        queue<string> q;
        q.push(""); // Start with an empty string

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            // Try appending each hot character to the current candidate
            iterate(ch, hotChars) {
                string next = curr + ch;

                // If this new candidate is valid...
                if (isSubsequence(next)) {
                    // It's oue new best answer
                    best = next;
                    // Add it to the queue to see if we can extend it further
                    q.push(next);
                }
            }
        }

        return best;
    }
};

int main() {
    Solution obj;
    string s = "letsleetcode";
    cout << obj.longestSubsequenceRepeatedK(s, 2) << endl;
    s = "bb";
    cout << obj.longestSubsequenceRepeatedK(s, 2) << endl;
    s = "ab";
    cout << obj.longestSubsequenceRepeatedK(s, 2) << endl;
    return 0;
}

/*
Problem: Longest Subsequence Repeated k Times
*/