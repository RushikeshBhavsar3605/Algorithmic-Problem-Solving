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

// Printing to stdout (iostream)
#define print(x)                                                                                                       \
    do {                                                                                                               \
        std::cout << (x);                                                                                              \
    } while (0)
#define println(x)                                                                                                     \
    do {                                                                                                               \
        std::cout << (x) << '\n';                                                                                      \
    } while (0)

class Solution {
  private:
    bool solve(int idx, string &s, string &target, string &result, bool prevGreater) {
        int n = sz(target);
        if (idx == n)
            return prevGreater;

        char mini = 'z' + 1;
        int index = -1;
        loop(j, 0, sz(s)) {
            if (prevGreater == true) {
                if (s[j] < mini) {
                    mini = s[j];
                    index = j;
                }
            } else {
                if (s[j] >= target[idx]) {
                    if (s[j] < mini) {
                        mini = s[j];
                        index = j;
                    }
                }
            }
        }

        if (index == -1)
            return false;

        result.pb(mini);
        char removed = s[index];
        s.erase(begin(s) + index);

        bool newPrevGreater = prevGreater || (mini > target[idx]);

        if (solve(idx + 1, s, target, result, newPrevGreater))
            return true;

        result.pop_back();
        s.insert(begin(s) + index, removed);

        vector<pii> candi;
        loop(j, 0, sz(s)) {
            char c = s[j];
            bool canUse = prevGreater || (c >= target[idx]);

            if (canUse && c > mini) {
                candi.pb({c, j});
            }
        }

        sort(all(candi));

        iterate(it, candi) {
            int c = it.ff;
            int j = it.ss;

            result.pb(c);
            s.erase(begin(s) + j);

            newPrevGreater = prevGreater || (c > target[idx]);
            if (solve(idx + 1, s, target, result, newPrevGreater)) {
                return true;
            }

            result.pop_back();
            s.insert(begin(s) + j, c);
        }

        return false;
    }

  public:
    string lexGreaterPermutation(string s, string target) {
        int n = sz(target);
        string result;

        return solve(0, s, target, result, false) ? result : "";
    }
};

int main() {
    Solution obj;
    println(obj.lexGreaterPermutation("ba", "ab"));
    println(obj.lexGreaterPermutation("abc", "bba"));
    println(obj.lexGreaterPermutation("leet", "code"));
    println(obj.lexGreaterPermutation("baba", "bbaa"));
    println(obj.lexGreaterPermutation("z", "a"));
}

/*
Problem:
*/