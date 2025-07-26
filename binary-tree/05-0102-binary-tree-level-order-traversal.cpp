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
    vvi result;
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root)
            return {{}};

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vi temp;

            loop(i, 0, size) {
                auto curr = q.front();
                q.pop();

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);

                temp.push_back(curr->val);
            }

            result.push_back(temp);
        }

        return result;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution obj;
    vvi v = obj.levelOrder(root);
    iterate(it, v) {
        iterate(i, it) cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem:
*/