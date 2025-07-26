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

/* Approach 1 (Recursive) */
class Solution {
  private:
    int checkHeight(TreeNode *&root) {
        if (!root)
            return 0;

        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1)
            return -1;

        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return max(leftHeight, rightHeight) + 1;
    }

  public:
    bool isBalanced(TreeNode *root) {
		return checkHeight(root) != -1;
	}
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution obj;
    cout << obj.isBalanced(root);
    return 0;
}

/*
Problem: Balanced Binary Tree
*/