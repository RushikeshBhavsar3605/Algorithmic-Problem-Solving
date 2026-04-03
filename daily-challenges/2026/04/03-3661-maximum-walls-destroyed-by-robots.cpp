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

class Solution {
  public:
    int maxWalls(vector<int> &robots, vector<int> &distance, vector<int> &walls) {
        int n = sz(robots);
        vec<int> left(n, 0);
        vec<int> right(n, 0);
        vec<int> num(n, 0);
        umap<int, int> robotsToDistance;

        loop(i, 0, n)
            robotsToDistance[robots[i]] = distance[i];

        sort(all(robots));
        sort(all(walls));

        int m = sz(walls);
        int rightPtr = 0, leftPtr = 0, currPtr = 0, robotPtr = 0;

        loop(i, 0, n) {
            while (rightPtr < m && walls[rightPtr] <= robots[i])
                rightPtr++;
            int pos1 = rightPtr;

            while (currPtr < m && walls[currPtr] < robots[i])
                currPtr++;
            int pos2 = currPtr;

            int leftBound = (i >= 1)
                                ? max(robots[i] - robotsToDistance[robots[i]], robots[i - 1] + 1)
                                : robots[i] - robotsToDistance[robots[i]];
            while (leftPtr < m && walls[leftPtr] < leftBound)
                leftPtr++;
            int leftPos = leftPtr;
            left[i] = pos1 - leftPos;

            int rightBound = (i < n - 1)
                                ? min(robots[i] + robotsToDistance[robots[i]], robots[i + 1] - 1)
                                : robots[i] + robotsToDistance[robots[i]];
            while (rightPtr < m && walls[rightPtr] <= rightBound)
                rightPtr++;
            int rightPos = rightPtr;
            right[i] = rightPos - pos2;

            if (i == 0)
                continue;

            while (robotPtr < m && walls[robotPtr] < robots[i - 1])
                robotPtr++;
            int pos3 = robotPtr;
            num[i] = pos1 - pos3;
        }

        int subLeft = left[0], subRight = right[0];
        loop(i, 1, n) {
            int currLeft = max(subLeft + left[i], subRight - right[i - 1] + min(left[i] + right[i - 1], num[i]));
            int currRight = max(subLeft + right[i], subRight + right[i]);
            subLeft = currLeft;
            subRight = currRight;
        }

        return max(subLeft, subRight);
    }
};

int main() {
    Solution obj;
    vec<int> robots = {4};
    vec<int> distance = {3};
    vec<int> walls = {1, 10};
    auto res = obj.maxWalls(robots, distance, walls);
    print(res);
    robots = {10, 2};
    distance = {5, 1};
    walls = {5, 2, 7};
    res = obj.maxWalls(robots, distance, walls);
    print(res);
    robots = {1, 2};
    distance = {100, 1};
    walls = {10};
    res = obj.maxWalls(robots, distance, walls);
    print(res);
    return 0;
}

/*
Problem: Maximum Walls Destroyed by Robots
*/