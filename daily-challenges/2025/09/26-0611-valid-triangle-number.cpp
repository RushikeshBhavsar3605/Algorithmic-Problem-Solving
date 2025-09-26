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

/* Approach 1 (Naive) (TLE):
class Solution {
  public:
    int triangleNumber(vector<int> &nums) {
        int n = sz(nums);
        int count = 0;

        loop(i, 0, n)
            loop(j, i + 1, n)
                loop(k, j + 1, n)
                    if (nums[i] + nums[j] > nums[k] &&
                        nums[i] + nums[k] > nums[j] &&
                        nums[j] + nums[k] > nums[i])
                        count++;

        return count;
    }
};
*/

/* Approach 2 (Binary Search): */
class Solution {
  private:
    int binarySearch(vi &nums, int left, int right, int x) {
        while (right >= left && right < sz(nums)) {
            int mid = (left + right) / 2;
            if (nums[mid] >= x)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }

  public:
    int triangleNumber(vector<int> &nums) {
        int count = 0;
        sort(all(nums));
        loop(i, 0, sz(nums) - 2) {
            int k = i + 2;
            for (int j = i + 1; j < sz(nums) - 1 && nums[i] != 0; j++) {
                k = binarySearch(nums, k, sz(nums) - 1, nums[i] + nums[j]);
                count += k - j - 1;
            }
        }

        return count;
    }
};

int main() {
    Solution obj;
    vi v = {2, 2, 3, 4};
    cout << obj.triangleNumber(v) << endl;
    v = {4, 2, 3, 4};
    cout << obj.triangleNumber(v) << endl;
}

/*
Problem: Valid Triangle Number
*/