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
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int index = 0;

        while (index < s.size()) {
            string temp;
            int tempk = k;

            while (index < s.size() && tempk != 0) {
                temp.push_back(s[index++]);
                tempk--;
            }
            while (tempk != 0) {
                temp.push_back(fill);
                tempk--;
            }
            
            result.push_back(temp);
        }

        return result;
    }
};

int main() {
    Solution obj;
    string s = "abcdefghij";
    vector<string> result = obj.divideString(s, 3, 'x');
    iterate(it, result) cout << it << endl;
    return 0;
}

/*
Problem:
*/