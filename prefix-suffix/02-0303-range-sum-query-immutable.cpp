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

/* Approach 1 (Naive):
class NumArray {
  private:
    vi data;

  public:
    NumArray(vector<int> &nums) {
        iterate(it, nums) data.pb(it);
    }

    int sumRange(int left, int right) {
        int sum = 0;
        loop(i, left, right + 1)
            sum += data[i];

        return sum;
    }
};
*/

/* Approach 2 (Prefix Sum): */
class NumArray {
  private:
    vi prefixSum;

  public:
    NumArray(vector<int> &nums) {
        prefixSum.resize(sz(nums) + 1, 0);
        loop(i, 0, sz(nums))
            prefixSum[i + 1] += prefixSum[i] + nums[i];
    }

    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};

int main() {
    vi v = {-2, 0, 3, -5, 2, -1};
    NumArray obj(v);
    cout << obj.sumRange(0, 2) << endl;
    cout << obj.sumRange(2, 5) << endl;
    cout << obj.sumRange(0, 5) << endl;
}

/*
Problem: Range Sum Query - Immutable
*/