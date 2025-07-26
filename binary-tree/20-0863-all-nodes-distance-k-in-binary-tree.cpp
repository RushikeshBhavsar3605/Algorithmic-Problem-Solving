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
    // Builds a map from each node to its parent for upward traversal
    void mapParents(TreeNode *&root, unordered_map<TreeNode *, TreeNode *> &parentMap) {
        if (!root)
            return;

        if (root->left) {
            parentMap[root->left] = root;
            mapParents(root->left, parentMap);
        }
        if (root->right) {
            parentMap[root->right] = root;
            mapParents(root->right, parentMap);
        }
    }

    // DFS to collect all nodes at given distance from target
    void collectAtDistance(TreeNode *&node, int remainingDistance, unordered_map<TreeNode *, TreeNode *> &parent,
                           unordered_set<TreeNode *> &visitedNodes, vi &result) {
        if (!node || visitedNodes.count(node))
            return;
        visitedNodes.insert(node);

        if (remainingDistance == 0) {
            result.push_back(node->val); // Found a node at required distance
            return;
        }

        // Explore all three directions: left, right, and parent
        collectAtDistance(node->left, remainingDistance - 1, parent, visitedNodes, result);
        collectAtDistance(node->right, remainingDistance - 1, parent, visitedNodes, result);
        collectAtDistance(parent[node], remainingDistance - 1, parent, visitedNodes, result);
    }

  public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        unordered_map<TreeNode *, TreeNode *> parentMap;
        parentMap[root] = NULL;      // Root has no parent
        mapParents(root, parentMap); // Create parent mapping

        vi result;
        unordered_set<TreeNode *> visitedNodes;
        collectAtDistance(target, k, parentMap, visitedNodes, result); // DFS from target

        return result;
    }
};
*/

/* Approach 2 (Iterative): */
class Solution {
  private:
    // Build a mapping from each node to its parent using BFS
    void mapParents(TreeNode *&root, unordered_map<TreeNode *, TreeNode *> &parentMap) {
        if (!root)
            return;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            // Map left child to parent
            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }

            // Map right child to parent
            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }

  public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        unordered_map<TreeNode *, TreeNode *> parentMap;
        parentMap[root] = NULL;      // Root has no parent
        mapParents(root, parentMap); // Populate parent relationships

        unordered_set<TreeNode *> visited;
        queue<TreeNode *> q;
        q.push(target);         // Start BFS from the target node
        visited.insert(target); // Mark target as visited
        int currDistance = 0;

        // Perform level-order traversal (BFS) until reaching distance k
        while (!q.empty()) {
            int levelSize = q.size();
            if (currDistance == k)
                break;

            while (levelSize--) {
                auto node = q.front();
                q.pop();

                // Explore unvisited connected nodes: left, right, and parent
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parentMap[node] && !visited.count(parentMap[node])) {
                    visited.insert(parentMap[node]);
                    q.push(parentMap[node]);
                }
            }

            currDistance++;
        }

        // Collect all nodes remaining in the queue (i.e., at distance k)
        vi result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    Solution obj;
    vi result = obj.distanceK(root, root->left, 2);
    iterate(it, result) cout << it << " ";
    return 0;
}

/*
Problem: All Nodes Distance K in Binary Tree
*/