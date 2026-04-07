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

/* Approach 1 (Simulation): */
class Robot {
  private:
    bool moved = false;
    int idx = 0;
    vec<pii> pos;
    vec<int> dir;
    umap<int, string> to_dir = {{0, "East"}, {1, "North"}, {2, "West"}, {3, "South"}};

  public:
    Robot(int width, int height) {
        loop(i, 0, width) {
            pos.pb({i, 0});
            dir.pb(0);
        }
        loop(i, 1, height) {
            pos.pb({width - 1, i});
            dir.pb(1);
        }
        revloop(i, width - 2, 0) {
            pos.pb({i, height - 1});
            dir.pb(2);
        }
        revloop(i, height - 2, 1) {
            pos.pb({0, i});
            dir.pb(3);
        }
        dir[0] = 3;
    }

    void step(int num) {
        moved = true;
        idx = (idx + num) % sz(pos);
    }

    vector<int> getPos() {
        return {pos[idx].first, pos[idx].second};
    }

    string getDir() {
        if (!moved)
            return "East";

        return to_dir[dir[idx]];
    }
};

int main() {
    Robot *obj = new Robot(6, 3);
    obj->step(2);
    obj->step(2);
    auto resPos = obj->getPos();
    print(resPos);
    auto resDir = obj->getDir();
    print(resDir);
    obj->step(2);
    obj->step(1);
    obj->step(4);
    resPos = obj->getPos();
    print(resPos);
    resDir = obj->getDir();
    print(resDir);
    return 0;
}

/*
Problem: Walking Robot Simulation II
*/