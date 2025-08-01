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
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)
            return {};

        vvi result;
        result.push_back({1});

        while (--numRows) {
            vi row = result.back();
            if (row.size() == 1) {
                result.push_back({1, 1});
                continue;
            }

            vi curr = {row.front()};
            loop(i, 1, row.size())
                curr.push_back(row[i - 1] + row[i]);

            curr.push_back(row.back());

            result.push_back(curr);
        }

        return result;
    }
};

int main() {
    Solution obj;
    vvi result = obj.generate(5);
    iterate(it, result) {
        iterate(i, it) cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem: Pascal's Triangle
*/