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

void preorder(TreeNode *root) {
    if (!root)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(TreeNode *root) {
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void levelorder(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        cout << curr->val << " ";
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    cout << "Level order: ";
    levelorder(root);
    return 0;
}

/*
Problem:
*/