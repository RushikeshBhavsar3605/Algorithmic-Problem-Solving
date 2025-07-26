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
    // Recursively build the binary tree from postorder and inorder traversal
    TreeNode *buildTree(vi &postorder, vi &inorder, int &postStart, int inStart, int inEnd,
                        unordered_map<int, int> &inMap) {
        // Base case: no nodes to process
        if (postStart < 0 || inStart > inEnd)
            return NULL;

        // Create root node from current postorder element
        TreeNode *root = new TreeNode(postorder[postStart--]);

        // Find root index in inorder to divide left/right subtrees
        int inorderRoot = inMap[root->val];

        // Build right subtree first (postorder processes right before left)
        root->right = buildTree(postorder, inorder, postStart, inorderRoot + 1, inEnd, inMap);
        root->left = buildTree(postorder, inorder, postStart, inStart, inorderRoot - 1, inMap);

        return root;
    }

  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Map each inorder value to its index for O(1) splits
        unordered_map<int, int> inMap;
        loop(i, 0, inorder.size())
            inMap[inorder[i]] = i;

        // Start from last postorder element
        int postStart = postorder.size() - 1;
        return buildTree(postorder, inorder, postStart, 0, inorder.size() - 1, inMap);
    }
};

void postorder(TreeNode *root) {
    if (!root)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
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
    vi in = {9, 3, 15, 20, 7};
    vi post = {9, 15, 7, 20, 3};
    TreeNode *root = obj.buildTree(in, post);
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    return 0;
}

/*
Problem: Construct Binary Tree from Inorder and Postorder Traversal
*/