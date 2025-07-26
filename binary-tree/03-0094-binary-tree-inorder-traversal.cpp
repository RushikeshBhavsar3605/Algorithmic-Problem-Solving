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
    vi result;
    vector<int> inorderTraversal(TreeNode *root) {
        if (!root)
            return result;

        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);

        return result;
    }
};
*/

/* Approach 2 (Iterative):
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        vi result;
        if (!root)
            return result;

        stack<TreeNode *> st;
        TreeNode *curr = root;
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }

        return result;
    }
};
*/

/* Approach 3 (Morris Traversal Threaded Binary Tree): */
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        vi inorder;
        TreeNode *curr = root;

        while (curr) {
            if (!curr->left) {
                // If no left child, visit current and move right
                inorder.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find inorder predecessor (rightmost in left subtree)
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                    prev = prev->right;

                if (prev->right == curr) {
                    // Thread already exists → remove it and visit node
                    prev->right = nullptr;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                } else {
                    // Create thread to return after left subtree
                    prev->right = curr;
                    curr = curr->left;
                }
            }
        }

        return inorder;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution obj;
    vi v = obj.inorderTraversal(root);
    iterate(it, v) cout << it << " ";
    return 0;
}

/*
Problem: Binary Tree Inorder Traversal
*/