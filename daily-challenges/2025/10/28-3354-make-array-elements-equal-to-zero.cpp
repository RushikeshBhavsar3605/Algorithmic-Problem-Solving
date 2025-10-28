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

// Printing to stdout (iostream)
#define print(x)                                                                                                       \
    do {                                                                                                               \
        std::cout << (x);                                                                                              \
    } while (0)
#define println(x)                                                                                                     \
    do {                                                                                                               \
        std::cout << (x) << '\n';                                                                                      \
    } while (0)

/* Approach 1 (Naive):
class Solution {
  private:
    bool isValid(int idx, vi nums, bool isLeftdirection) {
        int n = sz(nums);

        while (idx >= 0 && idx < n) {
            if (nums[idx] > 0)
                nums[idx]--, isLeftdirection = !isLeftdirection;

            isLeftdirection ? idx-- : idx++;
        }

        iterate(it, nums)
            if (it != 0)
                return false;

        return true;
    }

  public:
    int countValidSelections(vector<int> &nums) {
        int n = sz(nums);
        int result = 0;

        loop(i, 0, n)
            if (nums[i] == 0)
                result += isValid(i, nums, 0) + isValid(i, nums, 1);

        return result;
    }
};
*/

/* Approach 2 (Prefix Sum): */
class Solution {
  public:
    int countValidSelections(vector<int> &nums) {
        int n = sz(nums);
        int sum = accumulate(all(nums), 0);
        int leftSum = 0, rightSum = sum;
        int result = 0;

        loop(i, 0, n) {
            if (nums[i] == 0) {
                if (leftSum - rightSum == 0)
                    result += 2;
                else if (abs(leftSum - rightSum) == 1)
                    result++;
            } else {
                leftSum += nums[i];
                rightSum -= nums[i];
            }
        }

        return result;
    }
};

int main() {
    Solution obj;
    vi v = {1, 0, 2, 0, 3};
    println(obj.countValidSelections(v));
    v = {2, 3, 4, 0, 4, 1, 0};
    println(obj.countValidSelections(v));
}

/*
Problem: Make Array Elements Equal to Zero
*/