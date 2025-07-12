#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() < nums2[i])
                st.pop();
            if (st.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        vector<int> result;
        for (int i = 0; i < nums1.size(); i++)
            result.push_back(mp[nums1[i]]);

        return result;
    }
};
int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    Solution obj;
    vector<int> result = obj.nextGreaterElement(nums1, nums2);
    for (int it : result)
        cout << it << " ";
    cout << endl;
    return 0;
}

/*
Problem: Next Greater Element - I
*/