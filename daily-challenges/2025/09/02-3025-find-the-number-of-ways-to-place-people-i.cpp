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
  public:
    int numberOfPairs(vector<vector<int>> &points) {
        int n = sz(points);
        int count = 0;

        loop(i, 0, n) {
            pii pointA = {points[i][0], points[i][1]};

            loop(j, 0, n) {
                pii pointB = {points[j][0], points[j][1]};

                if (i == j || !(pointA.ff <= pointB.ff && pointA.ss >= pointB.ss))
                    continue;

                bool illegal = false;
                loop(k, 0, n) {
                    if (k == i || k == j)
                        continue;

                    pii pointTmp = {points[k][0], points[k][1]};
                    bool isXContained = (pointA.ff <= pointTmp.ff) && (pointTmp.ff <= pointB.ff);
                    bool isYContained = (pointB.ss <= pointTmp.ss) && (pointTmp.ss <= pointA.ss);

                    if (isXContained && isYContained) {
                        illegal = true;
                        break;
                    }
                }

                if (!illegal)
                    count++;
            }
        }

        return count;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 1}, {2, 2}, {3, 3}};
    cout << obj.numberOfPairs(v) << endl;
    v = {{6, 2}, {4, 4}, {2, 6}};
    cout << obj.numberOfPairs(v) << endl;
}

/*
Problem: Find the Number of Ways to Place People I
*/