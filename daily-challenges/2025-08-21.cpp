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

/* Approach 1 (Naive): */
class Solution {
  public:
    int numSubmat(vector<vector<int>> &mat) {
        int n = sz(mat);
        int m = sz(mat[0]);

        int result = 0;
        loop(startRow, 0, n) {

            vi vec(m, 1);
            loop(endRow, startRow, n) {
                loop(col, 0, m)
                    vec[col] = vec[col] & mat[endRow][col];

                int count = 0;
                iterate(it, vec) {
                    if (it == 0)
                        count = 0;
                    else
                        count++;

                    result += count;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    cout << obj.numSubmat(v) << endl;
    v = {{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}};
    cout << obj.numSubmat(v) << endl;
    return 0;
}

/*
Problem: Count Submatrices With All Ones
*/