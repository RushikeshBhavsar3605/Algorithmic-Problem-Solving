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
  public:
    int widthOfBinaryTree(TreeNode *root) {
        if (!root)
            return 0;

        // Queue stores pair of TreeNode and its index in a virtual complete binary tree
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});
        int best = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            long long mini = q.front().second;      // Base index to normalize current level
            long long first = 0, last = 0;

            loop(i, 0, levelSize) {
                auto node = q.front().first;
                int idx = q.front().second - mini;  // Normalize index to prevent overflow
                q.pop();

                if (i == 0)
                    first = idx;    // First node index in current level
                if (i == levelSize - 1)
                    last = idx;     // Last node index in current level

                // Push left and right children with calculated virtual indices
                if (node->left)
                    q.push({node->left, 1LL * idx * 2});
                if (node->right)
                    q.push({node->right, 1LL * idx * 2 + 1});
            }

            // Calculate width of current level and update best
            best = max(best, (int)(last - first + 1));
        }

        return best;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution obj;
    cout << obj.widthOfBinaryTree(root);
    return 0;
}

/*
Problem: Maximum Width of Binary Tree
*/