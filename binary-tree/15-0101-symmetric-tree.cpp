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

/* Approach 1 (): */
class Solution {
  private:
    bool isMirror(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true; // Both nodes are null → symmetric at this level

        else if (!p || !q)
            return false; // One is null, the other isn't → asymmetric

        if (p->val != q->val)
            return false; // Node values differ → asymmetric

        // Recursively check mirror symmetry:
        // Left child of p vs right child of q, and right child of p vs left child of q
        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }

  public:
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true; // Empty tree is symmetric

        // Check if left and right subtrees are mirror images
        return isMirror(root->left, root->right);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    Solution obj;
    cout << obj.isSymmetric(root);
    return 0;
}

/*
Problem: Symmetric Tree
*/