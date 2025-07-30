#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>

// STL shortcuts
#define all(x) begin(x), end(x)

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

class TreeNode {
  public:
    int val;
    TreeNode *left, *right;
    TreeNode(int data) {
        val = data;
        left = right = nullptr;
    }
};

/* Approach 1 (Recursive):
class Solution {
  private:
    TreeNode *insertNode(TreeNode *root, TreeNode *node) {
        if (!root)
            return node;

        if (root->val > node->val)
            root->left = insertNode(root->left, node);
        if (root->val < node->val)
            root->right = insertNode(root->right, node);

        return root;
    }

  public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        if (preorder.empty())
            return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);
        loop(i, 1, preorder.size())
            root = insertNode(root, new TreeNode(preorder[i]));

        return root;
    }
};
*/

/* Approach 2 (Iterative): */
class Solution {
  private:
    void insertNode(TreeNode *root, TreeNode *node) {
        while (root) {
            if (root->val > node->val) {
                if (!root->left) {
                    root->left = node;
                    return;
                }
                root = root->left;
            }
            if (root->val < node->val) {
                if (!root->right) {
                    root->right = node;
                    return;
                }
                root = root->right;
            }
        }
    }

  public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        if (preorder.empty())
            return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);
        loop(i, 1, preorder.size())
            insertNode(root, new TreeNode(preorder[i]));

        return root;
    }
};

void preorder(TreeNode *root) {
    if (!root)
        return;

    cout << root->val << ' ';
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Solution obj;
    vi v = {8, 5, 1, 7, 10, 12};
    TreeNode *root = obj.bstFromPreorder(v);
    preorder(root);
    return 0;
}

/*
Problem: Construct Binary Search Tree from Preorder Traversal
*/