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

/* Approach 1 (Recursive): */
class Solution {
  public:
    bool isValidBST(TreeNode *root, ll leftRange = LLONG_MIN, ll rightRange = LLONG_MAX) {
        if (!root)
            return true;

        if (root->val <= leftRange || root->val >= rightRange)
            return false;

        return isValidBST(root->left, leftRange, root->val) && isValidBST(root->right, root->val, rightRange);
    }
};

int main() {
    Solution obj;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << obj.isValidBST(root);
    return 0;
}

/*
Problem: Validate Binary Search Tree
*/