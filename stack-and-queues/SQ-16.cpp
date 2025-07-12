#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
                st.pop();

            if (!st.empty())
                result[i % n] = st.top();

            st.push(nums[i % n]);
        }

        return result;
    }
};
int main()
{
    vector<int> nums = {1, 2, 1};
    Solution obj;
    vector<int> result = obj.nextGreaterElements(nums);
    for (int it : result)
        cout << it << " ";
    cout << endl;
    return 0;
}

/*
Problem: Next Greater Element - II
*/