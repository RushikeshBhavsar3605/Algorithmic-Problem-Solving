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
    string makeFancyString(string s) {
        string result;
        result.push_back(s[0]);
        int freq = 1;

        loop(i, 1, s.size()) {
            if (s[i] == s[i - 1])
                freq++;
            else
                freq = 1;

            if (freq < 3)
                result.push_back(s[i]);
        }

        return result;
    }
};

int main() {
    Solution obj;
    cout << obj.makeFancyString("leeetcode");
    return 0;
}

/*
Problem: Delete Characters to Make Fancy String
*/