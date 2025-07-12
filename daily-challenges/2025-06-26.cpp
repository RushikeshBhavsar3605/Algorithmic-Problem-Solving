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
    int longestSubsequence(string s, int k) {
        int length = 0, value = 0;
        int bits = 32 - __builtin_clz(k);

        revloop(i, s.size() - 1, 0)
            if (s[i] == '0')
                length++;
            else if (length < bits && value + (1 << length) <= k) {
                value += (1LL << length);
                length++;
            }

        return length;
    }
};

int main() {
    Solution obj;
    string s = "1001010";
    cout << obj.longestSubsequence(s, 5) << endl;
    s = "00101001";
    cout << obj.longestSubsequence(s, 1) << endl;
    s = "11110001000001110100111000111100000000101110111111111011100001111101100001010111010011011000111100100101100101"
        "0011010000011111101001101000000101101001110110000111101011000101";
    cout << obj.longestSubsequence(s, 11713332);
    return 0;
}

/*
Problem:
*/