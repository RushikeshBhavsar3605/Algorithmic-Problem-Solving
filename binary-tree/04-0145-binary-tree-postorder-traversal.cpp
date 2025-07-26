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
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root)
            return result;

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        result.push_back(root->val);

        return result;
    }
};
*/

/* Approach 2 (Stack):
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root)
            return {};

        stack<TreeNode *> st1;
        stack<TreeNode *> st2;
        st1.push(root);

        while (!st1.empty()) {
            auto curr = st1.top();
            st1.pop();
            st2.push(curr);

            if (curr->left)
                st1.push(curr->left);
            if (curr->right)
                st1.push(curr->right);
        }

        vi result;
        while (!st2.empty()) {
            result.push_back(st2.top()->val);
            st2.pop();
        }

        return result;
    }
};
*/

/* Approach 2 (Stack Optimized):
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root)
            return {};

        stack<TreeNode *> st;
        TreeNode *curr = root;
        TreeNode *lastVisited = NULL;
        vi result;

        while (!st.empty() || curr) {
            if (curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                auto peekNode = st.top();
                if (peekNode->right && lastVisited != peekNode->right)
                    curr = peekNode->right;
                else {
                    result.push_back(peekNode->val);
                    lastVisited = peekNode;
                    st.pop();
                }
            }
        }

        return result;
    }
};
*/

/* Approach 3 (Morris Traversal Threaded Binary Tree): */
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        vi postorder;
        TreeNode *curr = root;

        while (curr) {
            if (!curr->right) {
                // No right child: visit current and move left
                postorder.push_back(curr->val);
                curr = curr->left;
            } else {
                // Find the inorder predecessor in the right subtree
                TreeNode *prev = curr->right;
                while (prev->left && prev->left != curr)
                    prev = prev->left;

                if (prev->left == curr) {
                    // Thread exists: remove it and move to left child
                    prev->left = nullptr;
                    curr = curr->left;
                } else {
                    // Create thread and visit current
                    prev->left = curr;
                    postorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        // Reverse modified root-right-left order to get left-right-root
        reverse(all(postorder));
        return postorder;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution obj;
    vi v = obj.postorderTraversal(root);
    iterate(it, v) cout << it << " ";
    return 0;
}

/*
Problem: Binary Tree Postorder Traversal
*/