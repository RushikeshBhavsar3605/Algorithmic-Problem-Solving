#include "template.hpp"

/* Approach (Naive): */
class Solution {
  private:
    int helper(TreeNode *root, int &diameter) {
        if (!root)
            return 0;

        int left = helper(root->left, diameter);
        int right = helper(root->right, diameter);
        updateMax(diameter, left + right);

        return max(left, right) + 1;
    }

  public:
    int diameterOfBinaryTree(TreeNode *root) {
        int diameter = 0;
        helper(root, diameter);

        return diameter;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.solve();
    print(res);
    return 0;
}

/*
Problem: Diameter of Binary Tree
*/