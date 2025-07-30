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

/* Approach 1 (Recursive Inorder Traversal):
class Solution {
  private:
    TreeNode *first;
    TreeNode *prev;
    TreeNode *middle;
    TreeNode *last;
    void inorder(TreeNode *root) {
        if (!root)
            return;

        inorder(root->left);

        if (prev && root->val < prev->val)
            if (!first) {
                first = prev;
                middle = root;
            } else
                last = root;
        prev = root;

        inorder(root->right);
    }

  public:
    void recoverTree(TreeNode *root) {
        first = prev = middle = last = nullptr;
        inorder(root);

        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};
*/

/* Approach 2 (Morris Traversal Threaded Binary Tree): */
class Solution {
  private:
    TreeNode *first;
    TreeNode *prevVal;
    TreeNode *middle;
    TreeNode *last;
    void inorder(TreeNode *root) {
        TreeNode *curr = root;

        while (curr) {
            if (!curr->left) {
                if (prevVal && curr->val < prevVal->val)
                    if (!first) {
                        first = prevVal;
                        middle = curr;
                    } else
                        last = curr;
                prevVal = curr;

                curr = curr->right;
            } else {
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                    prev = prev->right;

                if (prev->right == curr) {
                    prev->right = nullptr;

                    if (prevVal && curr->val < prevVal->val)
                        if (!first) {
                            first = prevVal;
                            middle = curr;
                        } else
                            last = curr;
                    prevVal = curr;

                    curr = curr->right;
                } else {
                    prev->right = curr;
                    curr = curr->left;
                }
            }
        }
    }

  public:
    void recoverTree(TreeNode *root) {
        first = prevVal = middle = last = nullptr;
        inorder(root);

        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};

void inorder(TreeNode *root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}

int main() {
    Solution obj;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    inorder(root);
    cout << endl;
    obj.recoverTree(root);
    inorder(root);
    return 0;
}

/*
Problem: Recover Binary Search Tree
*/