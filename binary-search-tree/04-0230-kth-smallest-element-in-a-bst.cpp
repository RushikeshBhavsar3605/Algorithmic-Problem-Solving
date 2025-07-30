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

/* Approach 1 (Recursive):
class Solution {
  private:
    int inorder(TreeNode *root, int &k) {
        if (!root)
            return -1;

        int left = inorder(root->left, k);

        if (--k == 0)
            return root->val;

        int right = inorder(root->right, k);

        return left != -1 ? left : right;
    }

  public:
    int kthSmallest(TreeNode *root, int k) {
        return inorder(root, k);
    }
};
*/

/* Approach 2 (Iterative):
class Solution {
  public:
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> st;
        TreeNode *curr = root;

        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();

            if (--k == 0)
                return curr->val;

            curr = curr->right;
        }

        return -1;
    }
};
*/

/* Approach 3 (Morris Traversal Threaded Binary Tree): */
class Solution {
  public:
    int kthSmallest(TreeNode *root, int k) {
        int result = -1;
        TreeNode *curr = root;

        while (curr) {
            if (!curr->left) {
                if (--k == 0)
                    result = curr->val;

                curr = curr->right;
            } else {
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                    prev = prev->right;

                if (prev->right == curr) {
                    prev->right = nullptr;
                    if (--k == 0)
                        result = curr->val;

                    curr = curr->right;
                } else {
                    prev->right = curr;
                    curr = curr->left;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution obj;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    cout << obj.kthSmallest(root, 3);
    return 0;
}

/*
Problem: Kth Smallest Element in a BST
*/