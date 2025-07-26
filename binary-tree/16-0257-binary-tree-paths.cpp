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
  private:
    void collectPaths(TreeNode *&root, vector<string> &resultPaths, string currPath) {
        if (!root)
            return;

        // Append current node value to the path
        currPath += to_string(root->val);

        // If it's a leaf node, store the complete path
        if (!root->left && !root->right) {
            resultPaths.push_back(currPath);
            return;
        }

        // If not a leaf, continue traversing
        currPath += "->";
        collectPaths(root->left, resultPaths, currPath);
        collectPaths(root->right, resultPaths, currPath);
    }

  public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> resultPaths;
        collectPaths(root, resultPaths, "");
        return resultPaths;
    }
};
*/

/* Approach 2 (Iterative): */
class Solution {
  public:
    vector<string> binaryTreePaths(TreeNode *root) {
        if (!root)
            return {}; // Empty tree → no paths

        queue<pair<TreeNode *, string>> nodeQueue;
        nodeQueue.push({root, to_string(root->val)}); // Start BFS with root and its value as initial path
        vector<string> resultPaths;

        while (!nodeQueue.empty()) {
            auto node = nodeQueue.front().first;
            auto currPath = nodeQueue.front().second;
            nodeQueue.pop();

            // If leaf node → complete path found
            if (!node->left && !node->right)
                resultPaths.push_back(currPath);

            // Add left child to queue with updated path
            if (node->left) {
                nodeQueue.push({
                    node->left,
                    currPath + "->" + to_string(node->left->val)
                });
            }

            // Add right child to queue with updated path
            if (node->right) {
                nodeQueue.push({
                    node->right,
                    currPath + "->" + to_string(node->right->val)
                });
            }
        }

        return resultPaths; // All root-to-leaf paths
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution obj;
    vector<string> result = obj.binaryTreePaths(root);
    iterate(it, result) cout << it << " ";
    return 0;
}

/*
Problem: Binary Tree Paths
*/