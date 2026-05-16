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

template <typename Node> void print(Node *head) {
    Node *curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next)
            cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

/* Approach 1 (Binary Search on Recursion):
class Solution {
  private:
    int solve(int st, int en, vi &nums) {
        if (st == en)
            return nums[st];

        if (nums[st] < nums[en])
            return nums[st];

        int mid = st + ((en - st) >> 1);
        return min(solve(st, mid, nums), solve(mid + 1, en, nums));
    }

  public:
    int findMin(vector<int> &nums) {
        return solve(0, sz(nums) - 1, nums);
    }
};
*/

/* Approach 2 (Binary Search In Rotated Array):

Note: The previous approach works perfectly fine for this problem
As there are only three segments confusion:
- if nums[left] == nums[mid]
- if nums[mid] == nums[right]
- if nums[left] == nums[right] at initial stage
Our original approach covers first 2 segments, but just to cover there's no way but to discard equal elements in first
and last elements

class Solution {
  public:
    int findMin(vector<int> &nums) {
        int n = sz(nums);
        int left = 0, right = n - 1;

        while (left < n - 1 && nums[left] == nums[n - 1])
            left++;

        while (left < right) {
            int mid = left + ((right - left) >> 1);

            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }

        return nums[left];
    }
};
*/

/* Approach 3 (Optimal): */
class Solution {
  public:
    int findMin(vector<int> &nums) {
        int n = sz(nums);
        int left = 0, right = n - 1;

        while (left < right) {
            int mid = left + ((right - left) >> 1);

            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] < nums[right])
                right = mid;
            else
                right--;
        }

        return nums[left];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 3, 5};
    auto res = obj.findMin(v);
    print(res);
    v = {2, 2, 2, 0, 1};
    res = obj.findMin(v);
    print(res);
    v = {1, 1, 3};
    res = obj.findMin(v);
    print(res);
    return 0;
}

/*
Problem: Find Minimum in Rotated Sorted Array II
*/