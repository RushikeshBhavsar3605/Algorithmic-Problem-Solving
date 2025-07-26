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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // Base case: if current node is null, return null
        if (!root)
            return NULL;

        // If current node matches either p or q, return it (potential LCA)
        if (root == p || root == q)
            return root;

        // Recurse on left and right subtrees
        TreeNode *leftResponse = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightResponse = lowestCommonAncestor(root->right, p, q);

        // If both sides return non-null, current node is the LCA
        if (leftResponse && rightResponse)
            return root;

        // Otherwise, return the non-null result (either LCA or a matching node)
        else if (leftResponse)
            return leftResponse;
        else
            return rightResponse;
    }
};
*/

/* Approach 2 (Iterative BFS): */
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root)
            return NULL;

        // Map each node to its parent
        unordered_map<TreeNode *, TreeNode *> parent;
        queue<TreeNode *> nodeQueue;

        parent[root] = NULL;
        nodeQueue.push(root);

        // Step 1: BFS to populate parent map until both p and q are found
        while (!nodeQueue.empty()) {
            auto node = nodeQueue.front();
            nodeQueue.pop();

            if (node->left) {
                parent[node->left] = node;
                nodeQueue.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                nodeQueue.push(node->right);
            }
        }

        // Step 2: Store all ancestors of p
        unordered_set<TreeNode *> ancestors;
        while (p) {
            ancestors.insert(p);
            p = parent[p];
        }

        // Step 3: The first q ancestor that is in p's ancestor set is LCA
        while (!ancestors.count(q))
            q = parent[q];

        return q;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution obj;
    cout << obj.lowestCommonAncestor(root, root->left, root->right)->val;
    return 0;
}

/*
Problem: Lowest Common Ancestor of a Binary Tree
*/