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
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
*/

/* Approach 2 (Iterative): */
class Solution {
  public:
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;

        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            depth++;
            int levelSize = q.size();

            loop(i, 0, levelSize) {
                auto node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return depth;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution obj;
    cout << obj.maxDepth(root);
    return 0;
}

/*
Problem: Maximum Depth of Binary Tree
*/