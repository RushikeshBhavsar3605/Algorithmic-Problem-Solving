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

/* Approach 1 (Recursive): */
class Solution {
  private:
    // Builds a map of each node to its parent to allow upward traversal
    void buildParentMap(TreeNode *&root, unordered_map<TreeNode *, TreeNode *> &parentMap) {
        if (!root)
            return;

        if (root->left) {
            parentMap[root->left] = root;
            buildParentMap(root->left, parentMap);
        }

        if (root->right) {
            parentMap[root->right] = root;
            buildParentMap(root->right, parentMap);
        }
    }

    // Finds the node with the given target value
    TreeNode *getTargetNode(TreeNode *&root, int targetVal) {
        if (!root)
            return NULL;

        if (root->val == targetVal)
            return root;

        TreeNode *left = getTargetNode(root->left, targetVal);
        if (left)
            return left;

        return getTargetNode(root->right, targetVal);
    }

    // Computes the maximum time to reach the farthest node using DFS (including parents)
    int getMaxInfectionTime(TreeNode *&node, unordered_map<TreeNode *, TreeNode *> &parentMap,
                            unordered_set<TreeNode *> &visited) {
        if (!node)
            return 0;

        int maxTime = 0;

        if (node->left && !visited.count(node->left)) {
            visited.insert(node->left);
            maxTime = max(maxTime, getMaxInfectionTime(node->left, parentMap, visited));
        }

        if (node->right && !visited.count(node->right)) {
            visited.insert(node->right);
            maxTime = max(maxTime, getMaxInfectionTime(node->right, parentMap, visited));
        }

        if (parentMap[node] && !visited.count(parentMap[node])) {
            visited.insert(parentMap[node]);
            maxTime = max(maxTime, getMaxInfectionTime(parentMap[node], parentMap, visited));
        }

        return maxTime + 1;
    }

  public:
    // Main function to calculate the total time to infect the entire tree
    int amountOfTime(TreeNode *root, int start) {
        unordered_map<TreeNode *, TreeNode *> parentMap;
        parentMap[root] = NULL;
        buildParentMap(root, parentMap);

        unordered_set<TreeNode *> visited;
        TreeNode *startNode = getTargetNode(root, start);
        visited.insert(startNode);

        return getMaxInfectionTime(startNode, parentMap, visited) - 1;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(2);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);
    Solution obj;
    cout << obj.amountOfTime(root, 3);
    return 0;
}

/*
Problem: Amount of Time for Binary Tree to Be Infected
*/