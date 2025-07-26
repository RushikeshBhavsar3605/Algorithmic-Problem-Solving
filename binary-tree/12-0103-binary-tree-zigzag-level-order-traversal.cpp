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

/* Approach 1 (Queue): */
class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root)
            return {}; // Empty tree case

        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        vvi result;

        bool leftToRight = true; // Direction toggle for zigzag order
        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            vi currentLevel(levelSize, 0); // Placeholder for current level nodes

            loop(i, 0, levelSize) {
                auto curr = nodeQueue.front();
                nodeQueue.pop();

                // Choose index based on direction
                int index = leftToRight ? i : (levelSize - i - 1);
                currentLevel[index] = curr->val;

                // Enqueue children for next level
                if (curr->left)
                    nodeQueue.push(curr->left);
                if (curr->right)
                    nodeQueue.push(curr->right);
            }

            result.push_back(currentLevel); // Add completed level
            leftToRight = !leftToRight;     // Toggle direction
        }

        return result;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution obj;
    vvi result = obj.zigzagLevelOrder(root);
    iterate(it, result) {
        iterate(i, it) cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem: Binary Tree Zigzag Level Order Traversal
*/