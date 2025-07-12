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
    string removeKdigits(string num, int k) {
        string result = "";

        loop(i, 0, num.size()) {
            // Remove digits from result if they are larger than current digit
            // and we still have digits to remove (greedy to keep number minimal)
            while (!result.empty() && k && result.back() > num[i]) {
                result.pop_back();
                k--;
            }

            // Skip leading zeros
            if (result.empty() && num[i] == '0')
                continue;

            result.push_back(num[i]);
        }

        // If we still have digits to remove, remove from the end
        while (!result.empty() && k) {
            result.pop_back();
            k--;
        }

        // Return result or "0" if empty
        return !result.empty() ? result : "0";
    }
};

int main() {
    Solution obj;
    string s = "1432219";
    cout << obj.removeKdigits(s, 3) << endl;
    s = "10200";
    cout << obj.removeKdigits(s, 1) << endl;
    s = "10";
    cout << obj.removeKdigits(s, 2) << endl;
    s = "123456";
    cout << obj.removeKdigits(s, 3) << endl;
    return 0;
}

/*
Problem: Remove K Digits
*/