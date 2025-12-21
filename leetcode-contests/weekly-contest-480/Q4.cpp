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

class SegmentTree {
  private:
    vi tree;
    int size;

    void buildTree(int idx, int left, int right, vi &nums) {
        if (left == right) {
            tree[idx] = nums[left];
            return;
        }

        int mid = left + ((right - left) >> 1);
        buildTree(2 * idx + 1, left, mid, nums);
        buildTree(2 * idx + 2, mid + 1, right, nums);

        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    void update(int i, int val, int idx, int left, int right) {
        if (left == right) {
            tree[idx] = val;
            return;
        }

        int mid = left + ((right - left) >> 1);
        if (i <= mid)
            update(i, val, 2 * idx + 1, left, mid);
        else
            update(i, val, 2 * idx + 2, mid + 1, right);

        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    int query(int start, int end, int idx, int left, int right) {
        if (right < start || end < left)
            return 0;
        if (start <= left && right <= end)
            return tree[idx];

        int mid = left + ((right - left) >> 1);
        return query(start, end, 2 * idx + 1, left, mid) + query(start, end, 2 * idx + 2, mid + 1, right);
    }

  public:
    SegmentTree(vi &nums) {
        size = sz(nums);
        tree.resize(4 * size);
        buildTree(0, 0, size - 1, nums);
    }

    void update(int index, int val) {
        update(index, val, 0, 0, size - 1);
    }

    int query(int left, int right) {
        return query(left, right, 0, 0, size - 1);
    }
};

/* Approach 1 (Segment Tree): */
class Solution {
  public:
    vector<int> minDeletions(string s, vector<vector<int>> &queries) {
        int n = sz(s);
        vi val(n, 0);
        loop(i, 1, n)
            if (s[i - 1] == s[i])
                val[i] = 1;

        SegmentTree seg(val);
        vi result;

        iterate(query, queries) {
            int type = query[0];

            if (type == 1) {
                int index = query[1];
                s[index] = s[index] == 'A' ? 'B' : 'A';

                if (index) {
                    if (s[index - 1] == s[index])
                        seg.update(index, 1);
                    else
                        seg.update(index, 0);
                }
                if (index < n - 1) {
                    if (s[index] == s[index + 1])
                        seg.update(index + 1, 1);
                    else
                        seg.update(index + 1, 0);
                }
            } else {
                int left = query[1], right = query[2];
                if (left == right)
                    result.pb(0);
                else
                    result.pb(seg.query(left + 1, right));
            }
        }

        return result;
    }
};

int main() {
    Solution obj;
    vvi v = {{2, 1, 2}, {1, 1}, {2, 0, 2}};
    dump(obj.minDeletions("ABA", v));
    v = {{2, 0, 2}, {1, 2}, {2, 0, 2}};
    dump(obj.minDeletions("ABB", v));
    v = {{2, 0, 3}, {1, 1}, {2, 1, 3}};
    dump(obj.minDeletions("BABA", v));
}

/*
Problem: Minimum Deletions to Make Alternating Substring
*/