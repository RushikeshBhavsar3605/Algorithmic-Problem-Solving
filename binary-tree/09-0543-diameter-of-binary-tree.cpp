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

class Solution {
  private:
    int height(TreeNode *&root, int &diameter) {
        if (!root)
            return 0;

        int left = height(root->left, diameter);
        int right = height(root->right, diameter);
        diameter = max(diameter, left + right);

        return max(left, right) + 1;
    }

  public:
    int diameterOfBinaryTree(TreeNode *root) {
        int diameter = 0;
        height(root, diameter);

        return diameter;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution obj;
    cout << obj.diameterOfBinaryTree(root);
    return 0;
}

/*
Problem: Diameter of Binary Tree
*/