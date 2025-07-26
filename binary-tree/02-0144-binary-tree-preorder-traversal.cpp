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
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root)
            return result;

        result.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return result;
    }
};
*/

/* Approach 2 (Iterative):
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
        vi result;
        if (!root)
            return result;

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty()) {
            auto curr = st.top();
            st.pop();
            result.push_back(curr->val);

            if (curr->right)
                st.push(curr->right);
            if (curr->left)
                st.push(curr->left);
        }

        return result;
    }
};
*/

/* Approach 3 (Morris Traversal Threaded Binary Tree): */
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
        vi preorder;
        TreeNode *curr = root;

        while (curr) {
            if (!curr->left) {
                // No left child → visit and move right
                preorder.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find inorder predecessor (rightmost in left subtree)
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                    prev = prev->right;

                if (prev->right == curr) {
                    // Thread exists → remove it and move right
                    prev->right = nullptr;
                    curr = curr->right;
                } else {
                    // Create thread and visit before going left
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
            }
        }

        return preorder;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution obj;
    vi v = obj.preorderTraversal(root);
    iterate(it, v) cout << it << " ";
    return 0;
}

/*
Problem: Binary Tree Preorder Traversal
*/