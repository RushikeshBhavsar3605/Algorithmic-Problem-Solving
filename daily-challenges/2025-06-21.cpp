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
    vvi dp;

    int solve(int i, int j, vi &freq, int k) {
        if (i == j || freq[j] - freq[i] <= k)
            return 0;

        if (dp[i][j] != -1)
            return 0;

        return min(freq[i] + solve(i + 1, j, freq, k), freq[j] - freq[i] - k + solve(i, j - 1, freq, k));
    }

  public:
    int minimumDeletions(string word, int k) {
        vi freq(26, 0);
        iterate(c, word)
            freq[c - 'a']++;
        
        sort(all(freq));
        dp = vvi(26, vi(26, -1));
        return solve(0, 25, freq, k);
    }
};

int main() {
    Solution obj;
    string word = "aabcaba";
    cout << obj.minimumDeletions(word, 0);
    return 0;
}

/*
Problem:
*/