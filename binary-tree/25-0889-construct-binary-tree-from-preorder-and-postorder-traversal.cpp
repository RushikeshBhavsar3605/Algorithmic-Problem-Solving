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
    // Recursively build tree from preorder stream + fixed preorder end + postorder start
    TreeNode *buildTree(vi &preorder, vi &postorder, int &preStart, int preEnd, int postStart,
                        unordered_map<int, int> &postMap) {
        // No nodes left in this subtree
        if (preStart > preEnd || postStart == postorder.size())
            return NULL;

        // Current root from preorder, advance stream
        TreeNode *root = new TreeNode(preorder[preStart++]);

        // If this was the only node, return it
        if (preStart - 1 == preEnd)
            return root;

        // Next preorder value is left child root: find its index in postorder
        int leftSubtreeRoot = postMap[preorder[preStart]];
        // Compute size of left subtree from postorder span
        int leftSubtreeSize = leftSubtreeRoot - postStart + 1;

        // Build left subtree over next leftSize nodes in preorder
        root->left = buildTree(preorder, postorder, preStart, preStart + leftSubtreeSize - 1, postStart, postMap);
        // Build right subtree from remaining preorder nodes
        root->right = buildTree(preorder, postorder, preStart, preEnd, postStart + leftSubtreeSize, postMap);

        return root;
    }

  public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
        // Build value→index map for quick postorder lookups
        unordered_map<int, int> postMap;
        loop(i, 0, postorder.size())
            postMap[postorder[i]] = i;

        // Kick off recursion with full ranges
        int preStart = 0;
        return buildTree(preorder, postorder, preStart, preorder.size() - 1, 0, postMap);
    }
};

void preorder(TreeNode *root) {
    if (!root)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode *root) {
    if (!root)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    Solution obj;
    vi pre = {1, 2, 4, 5, 3, 6, 7};
    vi post = {4, 5, 2, 6, 7, 3, 1};
    TreeNode *root = obj.constructFromPrePost(pre, post);
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    return 0;
}

/*
Problem: Construct Binary Tree from Preorder and Postorder Traversal
*/