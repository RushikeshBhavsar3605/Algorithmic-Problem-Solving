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

class Fancy {
  private:
    static constexpr int mod = 1e9 + 7;
    vec<int> v, a, b;

    int quickmul(int x, int y) {
        int ret = 1;
        int curr = x;
        while (y) {
            if (y & 1)
                ret = (ll)ret * curr % mod;
            curr = (ll)curr * curr % mod;
            y >>= 1;
        }

        return ret;
    }

    int inv(int x) {
        return quickmul(x, mod - 2);
    }

  public:
    Fancy() {
        a.pb(1);
        b.pb(0);
    }

    void append(int val) {
        v.pb(val);
        a.pb(a.back());
        b.pb(b.back());
    }

    void addAll(int inc) {
        b.back() = (b.back() + inc) % mod;
    }

    void multAll(int m) {
        a.back() = (ll)a.back() * m % mod;
        b.back() = (ll)b.back() * m % mod;
    }

    int getIndex(int idx) {
        if (idx >= sz(v))
            return -1;

        int ao = (ll)inv(a[idx]) * a.back() % mod;
        int bo = (b.back() - (ll)b[idx] * ao % mod + mod) % mod;
        int res = ((ll)ao * v[idx] % mod + bo) % mod;

        return res;
    }
};

int main() {
    Fancy *obj = new Fancy();
    obj->append(2);
    obj->addAll(3);
    obj->append(7);
    obj->multAll(2);
    print(obj->getIndex(0));
    obj->addAll(3);
    obj->append(10);
    obj->multAll(2);
    print(obj->getIndex(0));
    print(obj->getIndex(1));
    print(obj->getIndex(2));
    return 0;
}

/*
Problem: Fancy Sequence
*/