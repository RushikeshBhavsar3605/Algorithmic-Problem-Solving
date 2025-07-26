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

/* Approach 1 (Recursive Reverse Postorder):
class Solution {
  private:
    TreeNode *prev = nullptr; // Tracks previously visited node in reverse postorder

  public:
    void flatten(TreeNode *root) {
        if (!root)
            return;

        // Recurse right before left (reverse of preorder)
        flatten(root->right);
        flatten(root->left);

        // Rewire current node's pointers
        root->right = prev;   // Point right to previously processed node
        root->left = nullptr; // Nullify left pointer
        prev = root;          // Update prev to current node
    }
};
*/

/* Approach 2 (Iterative):
class Solution {
  public:
    void flatten(TreeNode *root) {
        if (!root)
            return;

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode *curr = st.top();
            st.pop();

            // Push right child first so left is processed first (preorder)
            if (curr->right)
                st.push(curr->right);
            if (curr->left)
                st.push(curr->left);

            // Set current node's right to next node in preorder
            if (!st.empty())
                curr->right = st.top();

            // Left should always be null in the flattened list
            curr->left = nullptr;
        }
    }
};
*/

/* Approach 3 (Morris Traversal Threaded Binary Tree): */
class Solution {
  public:
    void flatten(TreeNode *root) {
        TreeNode *curr = root;
        while (curr) {
            if (curr->left) {
                // Find the rightmost node in the left subtree
                TreeNode *prev = curr->left;
                while (prev->right)
                    prev = prev->right;

                // Connect the original right subtree to the rightmost node
                prev->right = curr->right;

                // Move the left subtree to the right
                curr->right = curr->left;
                curr->left = nullptr;
            }
            // Move to the next node in the right chain
            curr = curr->right;
        }
    }
};

void display(TreeNode *root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
}

int main() {
    Solution obj;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    obj.flatten(root);
    display(root);
    return 0;
}

/*
Problem: Flatten Binary Tree to Linked List
*/