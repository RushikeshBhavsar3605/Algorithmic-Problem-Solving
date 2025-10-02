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

// Debug Macros (OJ-safe: outputs to cerr)
#define dump(a)                                                                                                        \
    do {                                                                                                               \
        cerr << #a << " = ";                                                                                           \
        for (auto &x : a)                                                                                              \
            cerr << x << " ";                                                                                          \
        cerr << "\n";                                                                                                  \
    } while (0)
#define dump2D(a)                                                                                                      \
    do {                                                                                                               \
        cerr << #a << ":\n";                                                                                           \
        for (auto &row : a) {                                                                                          \
            for (auto &x : row)                                                                                        \
                cerr << x << " ";                                                                                      \
            cerr << "\n";                                                                                              \
        }                                                                                                              \
    } while (0)

/* Approach 1 (Naive): */
class Solution {
  private:
    bool isSubstringOf(string &sub, string &main) {
        loop(stIdx, 0, sz(main)) {
            bool subFits = true;

            loop(subIdx, 0, sz(sub))
                if (stIdx + subIdx >= sz(main) || main[stIdx + subIdx] != sub[subIdx]) {
                    subFits = false;
                    break;
                }

            if (subFits)
                return true;
        }

        return false;
    }

  public:
    vector<string> stringMatching(vector<string> &words) {
        vector<string> result;

        loop(i, 0, sz(words))
            loop(j, 0, sz(words)) {
                if (i == j)
                    continue;

                if (isSubstringOf(words[i], words[j])) {
                    result.pb(words[i]);
                    break;
                }
            }

        return result;
    }
};

int main() {
    Solution obj;
    vector<string> v = {"mass", "as", "hero", "superhero"};
    dump(obj.stringMatching(v));
    v = {"leetcode", "et", "code"};
    dump(obj.stringMatching(v));
    v = {"blue", "green", "bu"};
    dump(obj.stringMatching(v));
}

/*
Problem: String Matching in an Array
*/