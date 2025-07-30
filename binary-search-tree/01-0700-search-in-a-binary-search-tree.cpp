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
    TreeNode *searchBST(TreeNode *root, int val) {
        if (!root)
            return nullptr;

        if (root->val == val)
            return root;

        if (root->val < val)
            return searchBST(root->right, val);
        else
            return searchBST(root->left, val);
    }
};
*/

/* Approach 2 (Iterative): */
class Solution {
  public:
    TreeNode *searchBST(TreeNode *root, int val) {
        if (!root)
            return nullptr;

        while (root && root->val != val)
            if (root->val < val)
                root = root->right;
            else
                root = root->left;

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
    cout << obj.searchBST(root, 2)->val;
    return 0;
}

/*
Problem: Search in a Binary Search Tree
*/