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
    long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs) {
        vvi lefts(n + 1);
        iterate(pair, conflictingPairs) {
            int a = min(pair[0], pair[1]), b = max(pair[0], pair[1]);
            lefts[b].push_back(a);
        }

        ll result = 0, top1 = 0, top2 = 0;
        vector<ll> bonus(n + 1);
        loop(b, 1, n + 1) {
            iterate(a, lefts[b])
                if (a > top1) {
                    top2 = top1;
                    top1 = a;
                } else if (a > top2)
                    top2 = a;

            result += (b - top1);
            if (top1 > 0)
                bonus[top1] += (top1 - top2);
        }

        ll mx = 0;
        iterate(x, bonus)
            mx = max(mx, x);

        return result + mx;
    }
};

int main() {
    Solution obj;
    vvi v = {{2, 3}, {1, 4}};
    cout << obj.maxSubarrays(4, v);
    return 0;
}

/*
Problem: Maximize Subarrays After Removing One Conflicting Pair
*/