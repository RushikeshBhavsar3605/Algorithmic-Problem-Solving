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

void oneTraversal(TreeNode *&root) {
    if (!root)
        return;

    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});
    vi preorder, inorder, postorder;

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // this is part of preorder
        // increment 1 to 2
        // push the left side of the tree
        if (it.second == 1) {
            preorder.push_back(it.first->val);
            it.second++;
            st.push(it);

            if (it.first->left)
                st.push({it.first->left, 1});
        }

        // this is a part of inorder
        // increment 2 to 3
        // push right
        else if (it.second == 2) {
            inorder.push_back(it.first->val);
            it.second++;
            st.push(it);

            if (it.first->right)
                st.push({it.first->right, 1});
        }

        // don't push it back again
        else
            postorder.push_back(it.first->val);
    }

    cout << "preorder: ";
    iterate(it, preorder) cout << it << " ";
    cout << endl;
    cout << "Inorder: ";
    iterate(it, inorder) cout << it << " ";
    cout << endl;
    cout << "Postorder: ";
    iterate(it, postorder) cout << it << " ";
    cout << endl;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    oneTraversal(root);
    return 0;
}

/*
Problem:
*/