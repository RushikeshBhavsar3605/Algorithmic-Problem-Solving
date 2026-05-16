#include <bits/stdc++.h>
using namespace std;

// ==========================================
// Type Aliases
// ==========================================
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

// N-dimensional vector
template <typename T, int N> struct nvec {
    using type = vector<typename nvec<T, N - 1>::type>;
};

template <typename T> struct nvec<T, 1> {
    using type = vector<T>;
};

template <typename T, int N> using nvec_t = typename nvec<T, N>::type;

// ==========================================
// Pair Helpers
// ==========================================
#define ff first
#define ss second

// ==========================================
// STL Helpers
// ==========================================
#define pb push_back
#define all(x) begin(x), end(x)

template <typename T> inline int sz(const T &x) { return static_cast<int>(x.size()); }

// ==========================================
// Unordered Containers
// ==========================================
template <typename K, typename V> using umap = unordered_map<K, V>;

template <typename T> using uset = unordered_set<T>;

// ==========================================
// Loop Macros
// ==========================================
#define loop(i, a, b) for (auto i = (a); i < (b); i++)
#define loop_le(i, a, b) for (auto i = (a); i <= (b); i++)
#define revloop(i, a, b) for (auto i = (a); i >= (b); i--)
#define iterate(x, a) for (auto &x : (a))

// ==========================================
// Min / Max Updaters
// ==========================================
template <typename T> inline void updateMin(T &a, const T &b) {
    if (b < a)
        a = b;
}

template <typename T> inline void updateMax(T &a, const T &b) {
    if (b > a)
        a = b;
}

// ==========================================
// Unique (sort + dedup)
// ==========================================
template <typename T> inline void uniq(T &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

// ==========================================
// Debug Utilities (OJ-safe)
// ==========================================
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

// ==========================================
// Universal Printers
// ==========================================
template <typename T> void print(T x) { cout << x << endl; }

template <typename T> void print(vector<T> &v) {
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}

template <typename T> void print(vector<vector<T>> &vv) {
    for (auto &v : vv) {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
}

/* Approach (String Manipulation + Simulation): */
class Solution {
  public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        vector<string> line; // words collected for the current line
        int length = 0;      // total length of words in `line` (no spaces)
        int i = 0;

        while (i < sz(words)) {
            // If adding this word would overflow, finalize the current line first
            if (length + sz(line) + sz(words[i]) > maxWidth) {
                int gaps = sz(line) - 1;
                string currLine;

                // Single-word line: left-justify and pad the rest with spaces
                if (gaps == 0)
                    currLine = line[0] + string(maxWidth - length, ' ');
                else {
                    // Distribute spaces as evenly as possible across gaps
                    int totalSpaces = maxWidth - length;
                    int base = totalSpaces / max(1, sz(line) - 1);
                    int extra = totalSpaces % max(1, sz(line) - 1);

                    loop(j, 0, sz(line) - 1) {
                        currLine += line[j];
                        currLine += string(base, ' ');

                        // Put one extra space on the leftmost gaps
                        if (extra) {
                            currLine += string(1, ' ');
                            extra--;
                        }
                    }
                    currLine += line.back();
                }

                res.pb(currLine);
                line.clear();
                length = 0;
            }

            // Add current word to the active line
            line.pb(words[i]);
            length += sz(words[i]);
            i++;
        }

        // Last line: left-justified with single spaces between words
        string currLine;
        loop(j, 0, sz(line)) {
            currLine += line[j];
            if (j != line.size() - 1)
                currLine += " ";
        }
        currLine += string(maxWidth - sz(currLine), ' ');
        res.pb(currLine);

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vector<string> w = {"This", "is", "an", "example", "of", "text", "justification."};
    auto res = obj.fullJustify(w, 16);
    iterate(it, res) cout << it << endl;
    cout << endl;
    w = {"What", "must", "be", "acknowledgment", "shall", "be"};
    res = obj.fullJustify(w, 16);
    iterate(it, res) cout << it << endl;
    cout << endl;
    w = {"Science", "is", "what",      "we",  "understand", "well",       "enough", "to", "explain",
         "to",      "a",  "computer.", "Art", "is",         "everything", "else",   "we", "do"};
    res = obj.fullJustify(w, 20);
    iterate(it, res) cout << it << endl;
    cout << endl;
    return 0;
}

/*
Problem: Text Justification
*/