#include "template.hpp"

/* Approach (Monotonic Stack): */
class Solution {
  public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        umap<int, int> mp;
        stack<int> st;

        iterate(num, nums2) {
            while (!st.empty() && st.top() < num) {
                mp[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        vi res;
        iterate(num, nums1)
            res.pb(mp.count(num) ? mp[num] : -1);

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v1 = {4, 1, 2};
    vi v2 = {1, 3, 4, 2};
    auto res = obj.nextGreaterElement(v1, v2);
    print(res);
    return 0;
}

/*
Problem: Next Greater Element I
*/