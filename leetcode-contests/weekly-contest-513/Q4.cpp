#include "template.hpp"

class SegTree {
  private:
    int n;
    vl tree;

    void build(int idx, int low, int high, const vector<int> &nums) {
        if (low == high) {
            tree[idx] = nums[low];
            return;
        }

        int mid = low + ((high - low) >> 1);

        build(2 * idx + 1, low, mid, nums);
        build(2 * idx + 2, mid + 1, high, nums);

        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    ll query(int idx, int low, int high, int l, int r) {
        if (high < l || low > r)
            return 0;

        if (l <= low && high <= r)
            return tree[idx];

        int mid = low + ((high - low) >> 1);

        return query(2 * idx + 1, low, mid, l, r) + query(2 * idx + 2, mid + 1, high, l, r);
    }

    void update(int idx, int low, int high, int pos, int val) {
        if (low == high) {
            tree[idx] = val;
            return;
        }

        int mid = low + ((high - low) >> 1);

        if (pos <= mid)
            update(2 * idx + 1, low, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, high, pos, val);

        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

  public:
    SegTree(const vector<int> &nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(0, 0, n - 1, nums);
    }

    ll query(int l, int r) { return query(0, 0, n - 1, l, r); }

    void update(int pos, int val) { update(0, 0, n - 1, pos, val); }
};

/* Approach (Prefix Sum):
Derivation:
x = even count, y = odd count

Given:
      x / y <= a / b

Since y > 0:
      b * x <= a * y

Rearranging:
      b * x - a * y <= 0

Assign contribution per element:
      even -> +b
      odd  -> -a

Then,
      subarraySum = b * x - a * y

Define prefix sum:
      pre[i] = transformed sum of first i elements

For subarray [l...r]:
      pre[r + 1] - pre[l] <= 0

Rearranging:
      pre[l] >= pre[r + 1]

Therefore, for every current prefix, count how many previous
prefix sums are >= current prefix.
*/
class Solution {
  public:
    long long countRatioSubarrays(vector<int> &nums, int a, int b) {
        int n = sz(nums);
        vl pre(n + 1, 0);

        loop(i, 0, n) pre[i + 1] = pre[i] + ((nums[i] % 2 == 0) ? b : -a);

        vl vals = pre;
        uniq(vals);

        int m = sz(vals);
        vi freq(m, 0);
        SegTree st(freq);

        ll res = 0;

        iterate(it, pre) {
            int id = lower_bound(all(vals), it) - begin(vals);

            res += st.query(id, m - 1);

            ll curr = st.query(id, id);
            st.update(id, (int)(curr + 1));
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 1, 2};
    auto res = obj.countRatioSubarrays(v, 3, 2);
    print(res);
    v = {2, 2, 1};
    res = obj.countRatioSubarrays(v, 2, 1);
    print(res);
    v = {2, 2, 2};
    res = obj.countRatioSubarrays(v, 1, 1);
    print(res);
    return 0;
}

/*
Problem: Count Subarrays With Even Odd Ratio II
*/