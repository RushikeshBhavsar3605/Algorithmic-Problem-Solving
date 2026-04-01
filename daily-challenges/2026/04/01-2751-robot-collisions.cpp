#include <bits/stdc++.h>
using namespace std;

// =====================
// Type Aliases
// =====================
using ll = long long;

template <typename T> using vec = vector<T>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

// =====================
// STL Helpers
// =====================
#define pb push_back
#define all(x) begin(x), end(x)

template <typename T> inline int sz(const T &x) { return static_cast<int>(x.size()); }

// =====================
// Unordered Containers
// =====================
template <typename K, typename V> using umap = unordered_map<K, V>;

template <typename T> using uset = unordered_set<T>;

// =====================
// Loop Macros
// =====================
#define loop(i, a, b) for (auto i = (a); i < (b); i++)
#define loop_le(i, a, b) for (auto i = (a); i <= (b); i++)
#define revloop(i, a, b) for (auto i = (a); i >= (b); i--)
#define iterate(x, a) for (auto &x : (a))

// =====================
// Min / Max Updaters
// =====================
template <typename T> inline void updateMin(T &a, const T &b) {
    if (b < a)
        a = b;
}

template <typename T> inline void updateMax(T &a, const T &b) {
    if (b > a)
        a = b;
}

// =====================
// Unique (sort + dedup)
// =====================
template <typename T> inline void uniq(T &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

// =====================
// Debug Utilities (OJ-safe)
// =====================
#define LOCAL
#ifdef LOCAL

template <typename T> void dump(const T &a, const char *name) {
    cerr << name << " = ";
    for (const auto &x : a)
        cerr << x << ' ';
    cerr << '\n';
}

template <typename T> void dump2D(const T &a, const char *name) {
    cerr << name << ":\n";
    for (const auto &row : a) {
        for (const auto &x : row)
            cerr << x << ' ';
        cerr << '\n';
    }
}

#define DUMP(x) dump(x, #x)
#define DUMP2D(x) dump2D(x, #x)

#else
#define DUMP(x)
#define DUMP2D(x)
#endif

// =====================
// Universal Printers
// =====================
template <typename T> void print(T x) { cout << x << endl; }

template <typename T> void print(vec<T> &v) {
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}

template <typename T> void print(vec<vec<T>> &vv) {
    for (auto &v : vv) {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
}

/* Approach 1 (Greedy + Stack): */
class Solution {
  public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions) {
        int n = sz(positions);

        vec<int> actualIdx(n);
        iota(all(actualIdx), 0);

        sort(all(actualIdx), [&](int &i, int &j) {
            return positions[i] < positions[j];
        });

        stack<int> st;
        iterate(currIdx, actualIdx) {
            if (directions[currIdx] == 'R')
                st.push(currIdx);
            else {
                while (!st.empty() && healths[currIdx] > 0) {
                    int topIdx = st.top();
                    st.pop();

                    if (healths[topIdx] > healths[currIdx]) {
                        healths[topIdx] -= 1;
                        healths[currIdx] = 0;
                        st.push(topIdx);
                    } else if (healths[topIdx] < healths[currIdx]) {
                        healths[currIdx] -= 1;
                        healths[topIdx] = 0;
                    } else {
                        healths[currIdx] = 0;
                        healths[topIdx] = 0;
                    }
                }
            }
        }

        vec<int> res;
        loop(i, 0, n)
            if (healths[i] > 0)
                res.pb(healths[i]);

        return res;
    }
};

int main() {
    Solution obj;
    vec<int> positions = {5, 4, 3, 2, 1};
    vec<int> healths = {2, 17, 9, 15, 10};
    auto res = obj.survivedRobotsHealths(positions, healths, "RRRRR");
    print(res);
    positions = {3, 5, 2, 6};
    healths = {10, 10, 15, 12};
    res = obj.survivedRobotsHealths(positions, healths, "RLRL");
    print(res);
    positions = {1, 2, 5, 6};
    healths = {10, 10, 11, 11};
    res = obj.survivedRobotsHealths(positions, healths, "RLRL");
    print(res);
    return 0;
}

/*
Problem: Robot Collisions
*/