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
    // DFS traversal to populate verticalMap with nodes at each vertical index
    void helper(TreeNode *&root, int level, int index, map<int, vector<pii>> &verticalMap) {
        if (!root)
            return;

        // Store the node's level and value at the current vertical index
        verticalMap[index].push_back({level, root->val});

        // Traverse left subtree with level+1 and index-1 (move left)
        helper(root->left, level + 1, index - 1, verticalMap);

        // Traverse right subtree with level+1 and index+1 (move right)
        helper(root->right, level + 1, index + 1, verticalMap);
    }

  public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        map<int, vector<pii>> verticalMap; // Map: vertical index -> list of (level, value)
        helper(root, 0, 0, verticalMap);   // Start DFS from root at level 0, index 0
        vvi result;

        iterate(it, verticalMap) {
            vi temp;
            sort(all(it.second));           // Sort by level first, then value (default pair sort)
            iterate(i, it.second)
                temp.push_back(i.second);   // Extract only node values in sorted order

            result.push_back(temp);         // Add to final vertical traversal result
        }

        return result;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    Solution obj;
    vvi result = obj.verticalTraversal(root);
    iterate(it, result) {
        iterate(i, it) cout << i << " ";
        cout << endl;
    }

    vi nums = {1, 2, 3};
    int target = 0;
    return 0;
}

/*
Problem: Vertical Order Traversal of a Binary Tree
*/