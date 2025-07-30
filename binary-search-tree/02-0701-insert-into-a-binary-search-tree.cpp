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
  public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root)
            return new TreeNode(val);

        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);

        return root;
    }
};
*/

/* Approach 2 (Iterative): */
class Solution {
  public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root)
            return new TreeNode(val);

        TreeNode *curr = root;
        while (curr)
            if (curr->val < val) {
                if (!curr->right) {
                    curr->right = new TreeNode(val);
                    break;
                }
                curr = curr->right;
            } else {
                if (!curr->left) {
                    curr->left = new TreeNode(val);
                    break;
                }
                curr = curr->left;
            }

        return root;
    }
};

int main() {
    Solution obj;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    cout << obj.insertIntoBST(root, 5)->val;
    return 0;
}

/*
Problem: Insert into a Binary Search Tree
*/