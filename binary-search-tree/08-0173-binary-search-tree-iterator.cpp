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

/* Approach 1 (Morris Traversal Threaded Binary Tree):
class BSTIterator {
  private:
    queue<int> inorder;

  public:
    BSTIterator(TreeNode *root) {
        TreeNode *curr = root;

        while (curr) {
            if (!curr->left) {
                inorder.push(curr->val);
                curr = curr->right;
            } else {
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                    prev = prev->right;

                if (prev->right == curr) {
                    prev->right = nullptr;
                    inorder.push(curr->val);
                    curr = curr->right;
                } else {
                    prev->right = curr;
                    curr = curr->left;
                }
            }
        }
    }

    int next() {
        if (inorder.empty())
            return -1;

        int result = inorder.front();
        inorder.pop();
        return result;
    }

    bool hasNext() {
        if (inorder.empty())
            return false;

        return true;
    }
};
*/

/* Approach 2 (Stack): */
class BSTIterator {
  private:
    stack<TreeNode *> st;

    void stackPush(TreeNode *node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

  public:
    BSTIterator(TreeNode *root) {
        stackPush(root);
    }

    int next() {
        TreeNode *node = st.top();
        st.pop();
        if (node->right)
            stackPush(node->right);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

int main() {
    TreeNode *root = new TreeNode(7);

    root->left = new TreeNode(3);
    root->right = new TreeNode(15);

    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    BSTIterator *obj = new BSTIterator(root);
    cout << obj->next() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    return 0;
}

/*
Problem: Binary Search Tree Iterator
*/