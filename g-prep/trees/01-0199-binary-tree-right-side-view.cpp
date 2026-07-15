#include "template.hpp"

/* Approach (Queue): */
class Solution {
  public:
    vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr)
            return {};

        vi res;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = sz(q);

            loop(i, 0, levelSize) {
                TreeNode *node = q.front();
                q.pop();

                if (i == levelSize - 1)
                    res.pb(node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return res;
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
Problem: Binary Tree Right Side View
*/