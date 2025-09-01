#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long long>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>

// STL Shortcuts
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define uniq(v)                                                                                                        \
    sort(all(v));                                                                                                      \
    v.erase(unique(all(v)), v.end())

// Unordered Containers
#define umap unordered_map
#define uset unordered_set

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

// Min/Max Updaters (more explicit names)
#define updateMin(a, b) (a = min(a, b))
#define updateMax(a, b) (a = max(a, b))

/* Approach 1 (Naive): */
class Solution {
  private:
    bool isValid(double a, double b) {
        if (abs(a + b - 24) <= 1e-5 || abs(a - b - 24) <= 1e-5 || abs(a * b - 24) <= 1e-5 || abs(a / b - 24) <= 1e-5)
            return true;

        return false;
    }

    bool isValid(double a, double b, double c) {
        if (isValid(a + b, c) || isValid(a - b, c) || isValid(a * b, c) || isValid(a / b, c))
            return true;
        if (isValid(a, b + c) || isValid(a, b - c) || isValid(a, b * c) || isValid(a, b / c))
            return true;

        return false;
    }

    bool isValid(vi &cards) {
        double a = cards[0], b = cards[1], c = cards[2], d = cards[3];
        if (isValid(a + b, c, d) || isValid(a - b, c, d) || isValid(a * b, c, d) || isValid(a / b, c, d))
            return true;
        if (isValid(a, b + c, d) || isValid(a, b - c, d) || isValid(a, b * c, d) || isValid(a, b / c, d))
            return true;
        if (isValid(a, b, c + d) || isValid(a, b, c - d) || isValid(a, b, c * d) || isValid(a, b, c / d))
            return true;

        return false;
    }

  public:
    bool judgePoint24(vector<int> &cards) {
        sort(all(cards));
        if (isValid(cards))
            return true;

        while (next_permutation(all(cards)))
            if (isValid(cards))
                return true;

        return false;
    }
};

int main() {
    Solution obj;
    vi v = {4, 1, 8, 7};
    cout << obj.judgePoint24(v) << endl;
    return 0;
}

/*
Problem: 24 Game
*/