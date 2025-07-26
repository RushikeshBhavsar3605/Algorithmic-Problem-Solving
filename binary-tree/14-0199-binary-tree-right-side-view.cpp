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

/* Approach 1 (): */
class Solution {
  public:
    vector<int> rightSideView(TreeNode *root) {
        if (!root)
            return {}; // If the tree is empty, return an empty view

        vi rightView;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root); // Start BFS from the root node

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size(); // Number of nodes at current level

            loop(i, 0, levelSize) {
                auto node = nodeQueue.front();
                nodeQueue.pop();

                // If it's the last node in this level, add to right-side view
                if (i == levelSize - 1)
                    rightView.push_back(node->val);

                // Push left and right children to the queue for the next level
                if (node->left)
                    nodeQueue.push(node->left);
                if (node->right)
                    nodeQueue.push(node->right);
            }
        }

        return rightView; // Return the rightmost node from each level
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution obj;
    vi result = obj.rightSideView(root);
    iterate(it, result) cout << it << " ";
    return 0;
}

/*
Problem: Binary Tree Right Side View
*/