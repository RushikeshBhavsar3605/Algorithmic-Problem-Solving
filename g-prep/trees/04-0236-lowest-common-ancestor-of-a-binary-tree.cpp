#include "template.hpp"

/* Approach 1 (Recursive):
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root)
            return nullptr;

        if (p == root || q == root)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;
        else if (left)
            return left;
        else
            return right;
    }
};
*/

/* Approach 2 (Iterative): */
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root)
            return nullptr;

        umap<TreeNode *, TreeNode *> parent;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();

            if (node->left) {
                nodeQueue.push(node->left);
                parent[node->left] = node;
            }

            if (node->right) {
                nodeQueue.push(node->right);
                parent[node->right] = node;
            }
        }

        uset<TreeNode *> ancestors;
        while (p) {
            ancestors.insert(p);
            p = parent[p];
        }

        while (!ancestors.count(q))
            q = parent[q];

        return q;
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
Problem: Lowest Common Ancestor of a Binary Tree
*/