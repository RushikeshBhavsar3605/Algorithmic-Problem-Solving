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

/* Approach 1 (Prefix Sum (Cumulative Frequency)): */
class Solution {
  private:
    // helper: longest contiguous run of same character
    int longestUniformRun(string s) {
        // init: track max length and current streak
        int maxLength = 1;
        int count = 1;

        // loop: traverse string from second character
        loop(i, 1, sz(s)) {
            // condition: extend streak if same as previous
            if (s[i - 1] == s[i])
                count++;
            else
                count = 1; // reset streak

            // update: maintain maximum streak found
            updateMax(maxLength, count);
        }

        return maxLength;
    }

    // helper: longest substring where count(char1) == count(char2)
    int longestBalancedPair(string s, int char1, int char2) {
        // map: diff (count1 - count2) → first index seen
        umap<int, int> firstIndex;

        // init: frequency counters and answer
        int count1 = 0, count2 = 0, count3 = 0;
        int maxLength = 0;

        // loop: traverse string
        loop(i, 0, sz(s)) {
            // update: count only char1 and char2
            if (s[i] == char1)
                count1++;
            else if (s[i] == char2)
                count2++;
            else {
                // reset: invalid character breaks segment
                firstIndex.clear();
                count1 = count2 = count3 = 0;
                continue;
            }

            // compute difference
            int diff = count1 - count2;

            // condition: balanced from start
            if (diff == 0)
                updateMax(maxLength, count1 + count2);
            else {
                // condition: same diff seen before → balanced segment exists
                if (firstIndex.count(diff))
                    updateMax(maxLength, i - firstIndex[diff]);
                else
                    firstIndex[diff] = i; // store first occurrence
            }
        }

        return maxLength;
    }

    // helper: longest substring where count(a) == count(b) == count(c)
    int longestBalancedTriple(string s) {
        // map: (count1-count2, count1-count3) → first index
        umap<string, int> firstIndex;

        // init: frequency counters and answer
        int count1 = 0, count2 = 0, count3 = 0;
        int maxLength = 0;

        // loop: traverse string
        loop(i, 0, sz(s)) {
            // update: increment respective counters
            if (s[i] == 'a')
                count1++;
            if (s[i] == 'b')
                count2++;
            if (s[i] == 'c')
                count3++;

            // compute pairwise differences
            int diff1 = count1 - count2;
            int diff2 = count1 - count3;

            // create unique state key
            string key = to_string(diff1) + ":" + to_string(diff2);

            // condition: perfectly balanced from start
            if (count1 == count2 && count2 == count3)
                updateMax(maxLength, count1 * 3);
            else {
                // condition: same state seen before → balanced segment exists
                if (firstIndex.count(key))
                    updateMax(maxLength, i - firstIndex[key]);
                else
                    firstIndex[key] = i; // store first occurrence
            }
        }

        return maxLength;
    }

  public:
    int longestBalanced(string s) {
        // init: final answer
        int maxLength = 0;

        // case 1: single character runs
        updateMax(maxLength, longestUniformRun(s));

        // case 2: balanced pairs
        updateMax(maxLength, longestBalancedPair(s, 'a', 'b'));
        updateMax(maxLength, longestBalancedPair(s, 'a', 'c'));
        updateMax(maxLength, longestBalancedPair(s, 'b', 'c'));

        // case 3: balanced triple
        updateMax(maxLength, longestBalancedTriple(s));

        return maxLength;
    }
};

int main() {
    Solution obj;
    cout << obj.longestBalanced("abbac") << endl;
    cout << obj.longestBalanced("aabcc") << endl;
    cout << obj.longestBalanced("aba") << endl;
    return 0;
}

/*
Problem: Longest Balanced Substring II
*/