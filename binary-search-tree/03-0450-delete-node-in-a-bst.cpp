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

class Solution {
  private:
    // Find the leftmost (smallest) node in a subtree
    TreeNode *findLastLeft(TreeNode *root) {
        while (root->left)
            root = root->left;

        return root;
    }

    // Handle deletion when current node matches the key
    TreeNode *helper(TreeNode *root) {
        // Only right child or no child
        if (!root->left)
            return root->right;

        // Only left child
        else if (!root->right)
            return root->left;

        // Both children exist
        TreeNode *leftChild = findLastLeft(root->right); // Inorder successor
        leftChild->left = root->left;                    // Reattach left subtree

        return root->right; // Promote right subtree
    }

  public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root)
            return nullptr;

        // Root node is the one to delete
        if (root->val == key)
            return helper(root);

        TreeNode *node = root;
        while (node) {
            if (node->val < key) {
                // Check if right child is the node to delete
                if (node->right && node->right->val == key) {
                    node->right = helper(node->right);
                    break;
                }
                node = node->right;
            } else {
                // Check if left child is the node to delete
                if (node->left && node->left->val == key) {
                    node->left = helper(node->left);
                    break;
                }
                node = node->left;
            }
        }

        return root;
    }
};

void preorder(TreeNode *root) {
    if (!root)
        return;

    cout << root->val << ' ';
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}

int main() {
    Solution obj;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    TreeNode *newNode = obj.deleteNode(root, 3);
    preorder(root);
    cout << endl;
    inorder(root);
    return 0;
}

/*
Problem: Delete Node in a BST
*/