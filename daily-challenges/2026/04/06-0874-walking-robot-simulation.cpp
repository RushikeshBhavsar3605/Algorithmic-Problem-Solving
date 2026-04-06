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
class Solution {
  private:
    const ll HASH_MULTIPLIER = 60013;

    ll hashCoordinate(ll x, ll y) {
        return x + HASH_MULTIPLIER * y;
    }

  public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
        uset<ll> obstacleSet;
        iterate(obstacle, obstacles)
            obstacleSet.insert(hashCoordinate(obstacle[0], obstacle[1]));

        vec<pii> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // N, E, S, W
        pii currPosition = {0, 0};
        int currDirection = 0;
        int maxDistanceSquared = 0;

        iterate(command, commands) {
            if (command == -1) {
                currDirection = (currDirection + 1) % 4;
                continue;
            }
            if (command == -2) {
                currDirection = (currDirection + 3) % 4; // In C++ (-1 % 4) = -1
                continue;
            }

            auto [newDirectionX, newDirectionY] = directions[currDirection];
            loop(i, 0, command) {
                int newPositionX = newDirectionX + currPosition.first;
                int newPositionY = newDirectionY + currPosition.second;

                if (obstacleSet.count(hashCoordinate(newPositionX, newPositionY)))
                    break;

                currPosition.first = newPositionX;
                currPosition.second = newPositionY;
            }

            updateMax(maxDistanceSquared,
                      (currPosition.first * currPosition.first) + (currPosition.second * currPosition.second));
        }

        return maxDistanceSquared;
    }
};

int main() {
    Solution obj;
    vec<int> commands = {4, -1, 3};
    vec<vec<int>> obstacles = {};
    auto res = obj.robotSim(commands, obstacles);
    print(res);
    commands = {4, -1, 4, -2, 4};
    obstacles = {{2, 4}};
    res = obj.robotSim(commands, obstacles);
    print(res);
    commands = {6, -1, -1, 6};
    obstacles = {{0, 0}};
    res = obj.robotSim(commands, obstacles);
    print(res);
    return 0;
}

/*
Problem: Walking Robot Simulation
*/