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

/* Approach 1 (Recursive): */
class Solution {
  private:
    // Recursively build the binary tree from preorder and inorder traversal
    TreeNode *buildTree(vi &preorder, vi &inorder, int &preStart, int inStart, int inEnd,
                        unordered_map<int, int> &inMap) {
        // Base case: no nodes left to process
        if (preStart == preorder.size() || inStart > inEnd)
            return NULL;

        // Create root node from current preorder element
        TreeNode *root = new TreeNode(preorder[preStart++]);

        // Find root index in inorder to split left and right subtrees
        int inorderRoot = inMap[root->val];

        // Recursively build left and right subtrees
        root->left = buildTree(preorder, inorder, preStart, inStart, inorderRoot - 1, inMap);
        root->right = buildTree(preorder, inorder, preStart, inorderRoot + 1, inEnd, inMap);

        return root;
    }

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Map each value to its index in inorder for O(1) access
        unordered_map<int, int> inMap;
        loop(i, 0, inorder.size())
            inMap[inorder[i]] = i;

        // Start building from full inorder range
        int preStart = 0;
        return buildTree(preorder, inorder, preStart, 0, inorder.size() - 1, inMap);
    }
};

void preorder(TreeNode *root) {
    if (!root)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution obj;
    vi pre = {3, 9, 20, 15, 7};
    vi in = {9, 3, 15, 20, 7};
    TreeNode *root = obj.buildTree(pre, in);
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    return 0;
}

/*
Problem: Construct Binary Tree from Preorder and Inorder Traversal
*/