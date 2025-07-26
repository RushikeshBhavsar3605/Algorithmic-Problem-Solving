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
        left = right = NULL;
    }
};

/* Approach 1 (Recursive):
class Solution {
  public:
    bool checkTree(TreeNode *root) {
        // empty or leaf node is trivially valid
        if (!root || (!root->left && !root->right))
            return true;

        // sum values of existing children
        int sum = 0;
        if (root->left)
            sum += root->left->val;
        if (root->right)
            sum += root->right->val;

        // current node must equal child-sum, and both subtrees valid
        return (sum == root->val)
            && checkTree(root->left)
            && checkTree(root->right);
    }
};
*/

/* Approach 2 (Iterative): */
class Solution {
  public:
    bool checkTree(TreeNode *root) {
        // empty tree is valid
        if (!root)
            return true;

        stack<TreeNode *> nodeStack;
        nodeStack.push(root); // start DFS from root

        while (!nodeStack.empty()) {
            auto node = nodeStack.top();
            nodeStack.pop();

            // skip leaves
            if (!node->left && !node->right)
                continue;

            // sum child values and push them for later checks
            int sum = 0;
            if (node->left) {
                nodeStack.push(node->left);
                sum += node->left->val;
            }
            if (node->right) {
                nodeStack.push(node->right);
                sum += node->right->val;
            }

            // internal node must equal sum of children
            if (sum != node->val)
                return false;
        }

        return true;
    }
};

int main() {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    Solution obj;
    cout << obj.checkTree(root);
    return 0;
}

/*
Problem: Root Equals Sum of Children
*/