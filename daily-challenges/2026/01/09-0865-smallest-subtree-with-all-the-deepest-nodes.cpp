#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long long>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>

// STL Shortcuts
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define uniq(v)                                                                                                        \
    sort(all(v));                                                                                                      \
    v.erase(unique(all(v)), v.end())

// Unordered Containers
#define umap unordered_map
#define uset unordered_set

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

// Min/Max Updaters (more explicit names)
#define updateMin(a, b) (a = min(a, b))
#define updateMax(a, b) (a = max(a, b))

// Debug Macros (OJ-safe: outputs to cerr)
#define dump(a)                                                                                                        \
    do {                                                                                                               \
        cerr << #a << " = ";                                                                                           \
        for (auto &x : a)                                                                                              \
            cerr << x << " ";                                                                                          \
        cerr << "\n";                                                                                                  \
    } while (0)
#define dump2D(a)                                                                                                      \
    do {                                                                                                               \
        cerr << #a << ":\n";                                                                                           \
        for (auto &row : a) {                                                                                          \
            for (auto &x : row)                                                                                        \
                cerr << x << " ";                                                                                      \
            cerr << "\n";                                                                                              \
        }                                                                                                              \
    } while (0)

// Printing to stdout (iostream)
#define print(x)                                                                                                       \
    do {                                                                                                               \
        std::cout << (x);                                                                                              \
    } while (0)
#define println(x)                                                                                                     \
    do {                                                                                                               \
        std::cout << (x) << '\n';                                                                                      \
    } while (0)

class TreeNode {
  public:
    int val;
    TreeNode *left, *right;
    TreeNode(int data) {
        val = data;
        left = right = nullptr;
    }
};

/* Approach 1 (BFS + DFS): */
class Solution {
  public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *leftNode = root;
        TreeNode *rightNode = root;

        while (!q.empty()) {
            int n = sz(q);

            loop(i, 0, n) {
                auto node = q.front();
                q.pop();
                if (i == 0)
                    leftNode = node;
                if (i == n - 1)
                    rightNode = node;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        TreeNode *result = nullptr;
        umap<TreeNode *, int> mp;

        function<bool(TreeNode *, TreeNode *)> findSubtree = [&](TreeNode *root, TreeNode *targetNode) {
            if (!root)
                return false;
            if (root == targetNode) {
                if (++mp[root] == 2 && !result)
                    result = root;
                return true;
            }

            if (findSubtree(root->left, targetNode) || findSubtree(root->right, targetNode)) {
                if (++mp[root] == 2 && !result)
                    result = root;
                return true;
            }

            return false;
        };
        findSubtree(root, leftNode);
        findSubtree(root, rightNode);

        return result;
    }
};

void preorder(TreeNode *root) {
    if (!root)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Solution obj;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root = obj.subtreeWithAllDeepest(root);
    preorder(root);
}

/*
Problem: Smallest Subtree with all the Deepest Nodes
*/