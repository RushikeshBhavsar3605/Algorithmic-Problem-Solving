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
    vi splitString(string &s, char delimeter) {
        vi result;
        int start = 0;
        int end = s.find(delimeter, start);

        while (end != string::npos) {
            string temp = s.substr(start, end - start);
            result.pb(stoi(temp));
            start = end + 1;
            end = s.find(delimeter, start);
        }

        string temp = s.substr(start, end - start);
        result.pb(stoi(temp));
        return result;
    }

  public:
    int compareVersion(string version1, string version2) {
        vi v1 = splitString(version1, '.');
        vi v2 = splitString(version2, '.');

        int val1, val2;
        loop(i, 0, max(sz(v1), sz(v2))) {
            val1 = i < sz(v1) ? v1[i] : 0;
            val2 = i < sz(v2) ? v2[i] : 0;

            if (val1 < val2)
                return -1;
            else if (val1 > val2)
                return 1;
        }

        return 0;
    }
};

int main() {
    Solution obj;
    cout << obj.compareVersion("1.2", "1.10") << endl;
    cout << obj.compareVersion("1.01", "1.001") << endl;
    cout << obj.compareVersion("1.0", "1.0.0.0") << endl;
}

/*
Problem: Compare Version Numbers
*/