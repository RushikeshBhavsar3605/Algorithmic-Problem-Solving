#include "template.hpp"

/* Approach (Queue): */
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr)
            return {};

        vvi res;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = sz(q);
            vi curr;

            loop(i, 0, levelSize) {
                TreeNode *node = q.front();
                q.pop();

                curr.pb(node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            res.pb(curr);
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
Problem: Binary Tree Level Order Traversal
*/