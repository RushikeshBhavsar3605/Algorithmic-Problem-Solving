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

struct LazyTag {
    int to_add = 0;

    LazyTag operator+=(const LazyTag &other) {
        this->to_add += other.to_add;
        return *this;
    }

    bool has_tag() const { return to_add != 0; }

    void clear() { to_add = 0; }
};

struct SegmentTreeNode {
    int min_value = 0;
    int max_value = 0;

    LazyTag lazy_tag;
};

class SegmentTree {
  private:
    inline void apply_tag(int i, const LazyTag &tag) {
        tree[i].min_value += tag.to_add;
        tree[i].max_value += tag.to_add;
        tree[i].lazy_tag += tag;
    }

    inline void pushdown(int i) {
        if (tree[i].lazy_tag.has_tag()) {
            LazyTag tag = tree[i].lazy_tag;
            apply_tag(i << 1, tag);
            apply_tag(i << 1 | 1, tag);
            tree[i].lazy_tag.clear();
        }
    }

    inline void pushup(int i) {
        tree[i].min_value = min(tree[i << 1].min_value, tree[i << 1 | 1].min_value);
        tree[i].max_value = max(tree[i << 1].max_value, tree[i << 1 | 1].max_value);
    }

    void build(const vec<int> &data, int l, int r, int i) {
        if (l == r) {
            tree[i].min_value = tree[i].max_value = data[l - 1];
            return;
        }

        int mid = l + ((r - l) >> 1);
        build(data, l, mid, i << 1);
        build(data, mid + 1, r, i << 1 | 1);

        pushup(i);
    }

    void update(int target_l, int target_r, const LazyTag &tag, int l, int r, int i) {
        if (target_l <= l && r <= target_r) {
            apply_tag(i, tag);
            return;
        }

        pushdown(i);
        int mid = l + ((r - l) >> 1);
        if (target_l <= mid)
            update(target_l, target_r, tag, l, mid, i << 1);
        if (target_r > mid)
            update(target_l, target_r, tag, mid + 1, r, i << 1 | 1);
        pushup(i);
    }

    int find(int target_l, int target_r, int val, int l, int r, int i) {
        if (tree[i].min_value > val || tree[i].max_value < val)
            return -1;

        if (l == r)
            return l;

        pushdown(i);
        int mid = l + ((r - l) >> 1);

        if (target_r >= mid + 1) {
            int res = find(target_l, target_r, val, mid + 1, r, i << 1 | 1);
            if (res != -1)
                return res;
        }

        if (l <= target_r && mid >= target_l)
            return find(target_l, target_r, val, l, mid, i << 1);

        return -1;
    }

  public:
    int n;
    vec<SegmentTreeNode> tree;

    SegmentTree(const vec<int> &data) : n(sz(data)) {
        tree.resize(n * 4 + 1);
        build(data, 1, n, 1);
    }

    void add(int l, int r, int val) {
        LazyTag tag{val};
        update(l, r, tag, 1, n, 1);
    }

    int find_last(int start, int val) {
        if (start > n)
            return -1;

        return find(start, n, val, 1, n, 1);
    }
};

class Solution {
  public:
    int longestBalanced(vector<int> &nums) {
        map<int, queue<int>> occurrences;
        auto sgn = [](int x) {
            return (x % 2) == 0 ? 1 : -1;
        };

        int len = 0;
        vec<int> prefix_sum(sz(nums), 0);

        prefix_sum[0] = sgn(nums[0]);
        occurrences[nums[0]].push(1);

        loop(i, 1, sz(nums)) {
            prefix_sum[i] = prefix_sum[i - 1];
            auto &occ = occurrences[nums[i]];
            if (occ.empty())
                prefix_sum[i] += sgn(nums[i]);

            occ.push(i + 1);
        }

        SegmentTree seg(prefix_sum);

        loop(i, 0, sz(nums)) {
            len = max(len, seg.find_last(i + len, 0) - i);

            auto next_pos = nums.size() + 1;
            occurrences[nums[i]].pop();
            if (!occurrences[nums[i]].empty())
                next_pos = occurrences[nums[i]].front();

            seg.add(i + 1, next_pos - 1, -sgn(nums[i]));
        }

        return len;
    }
};

int main() {
    Solution obj;
    vec<int> v = {2, 5, 4, 3};
    cout << obj.longestBalanced(v) << endl;
    v = {3, 2, 2, 5, 4};
    cout << obj.longestBalanced(v) << endl;
    v = {1, 2, 3, 2};
    cout << obj.longestBalanced(v) << endl;
    return 0;
}

/*
Problem: Longest Balanced Subarray II
*/