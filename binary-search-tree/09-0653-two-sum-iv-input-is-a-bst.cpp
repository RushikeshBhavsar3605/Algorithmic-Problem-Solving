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

/* Approach 1 (Naive):
class Solution {
  private:
    vector<int> inorderTraversal(TreeNode *root) {
        vi inorder;
        TreeNode *curr = root;

        while (curr) {
            if (!curr->left) {
                inorder.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                    prev = prev->right;

                if (prev->right == curr) {
                    prev->right = nullptr;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                } else {
                    prev->right = curr;
                    curr = curr->left;
                }
            }
        }

        return inorder;
    }

  public:
    bool findTarget(TreeNode *root, int k) {
        vi inorder = inorderTraversal(root);
        int start = 0, end = inorder.size() - 1;

        while (start < end)
            if (inorder[start] + inorder[end] < k)
                start++;
            else if (inorder[start] + inorder[end] > k)
                end--;
            else
                return true;

        return false;
    }
};
*/

/* Approach 2 (BST Iterator): */
class BSTIterator {
  private:
    bool isReverse;
    stack<TreeNode *> st;

    void stackPush(TreeNode *node) {
        while (node) {
            st.push(node);
            if (isReverse)
                node = node->right;
            else
                node = node->left;
        }
    }

  public:
    BSTIterator(TreeNode *root, bool isReverse) {
        this->isReverse = isReverse;
        stackPush(root);
    }

    int next() {
        TreeNode *node = st.top();
        st.pop();
        if (!isReverse)
            stackPush(node->right);
        else
            stackPush(node->left);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
  public:
    bool findTarget(TreeNode *root, int k) {
        if (!root)
            return false;

        BSTIterator leftIterator(root, false);
        BSTIterator rightIterator(root, true);

        int left = leftIterator.next();
        int right = rightIterator.next();
        while (left < right)
            if (left + right == k)
                return true;
            else if (left + right < k)
                left = leftIterator.next();
            else
                right = rightIterator.next();

        return false;
    }
};

int main() {
    Solution obj;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(7);
    cout << obj.findTarget(root, 9) << endl;
    TreeNode *root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    cout << obj.findTarget(root1, 3) << endl;

    // preorder(root);
    return 0;
}

/*
Problem: Two Sum IV - Input is a BST
*/