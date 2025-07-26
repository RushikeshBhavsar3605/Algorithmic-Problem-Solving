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

/* Approach 1 () */
class Solution {
  private:
    // Helper function returns max gain from current node to any leaf
    // while updating the global max path sum (sum) across the tree
    int helper(TreeNode *&root, int &sum) {
        if (!root)
            return 0;

        // Recursively get max gain from left and right subtrees
        // If the gain is negative, discard it by taking 0
        int left = max(helper(root->left, sum), 0);
        int right = max(helper(root->right, sum), 0);

        // Path passing through current node (could be a peak)
        int currentMaxPath = root->val + left + right;

        // Update global maximum if this path is better
        sum = max(sum, currentMaxPath);

        // Return max gain from current node to its parent
        return root->val + max(left, right);
    }

  public:
    int maxPathSum(TreeNode *root) {
        int sum = INT_MIN; // Initialize with lowest possible value
        helper(root, sum);

        return sum;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution obj;
    cout << obj.maxPathSum(root);
    return 0;
}

/*
Problem: Binary Tree Maximum Path Sum
*/