#include <bits/stdc++.h>
using namespace std;

// =====================
// Type Aliases
// =====================
using ll = long long;

template <typename T> using vec = vector<T>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

// =====================
// STL Helpers
// =====================
#define pb push_back
#define all(x) begin(x), end(x)

template <typename T> inline int sz(const T &x) { return static_cast<int>(x.size()); }

// =====================
// Unordered Containers
// =====================
template <typename K, typename V> using umap = unordered_map<K, V>;

template <typename T> using uset = unordered_set<T>;

// =====================
// Loop Macros
// =====================
#define loop(i, a, b) for (auto i = (a); i < (b); i++)
#define loop_le(i, a, b) for (auto i = (a); i <= (b); i++)
#define revloop(i, a, b) for (auto i = (a); i >= (b); i--)
#define iterate(x, a) for (auto &x : (a))

// =====================
// Min / Max Updaters
// =====================
template <typename T> inline void updateMin(T &a, const T &b) {
    if (b < a)
        a = b;
}

template <typename T> inline void updateMax(T &a, const T &b) {
    if (b > a)
        a = b;
}

// =====================
// Unique (sort + dedup)
// =====================
template <typename T> inline void uniq(T &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

// =====================
// Debug Utilities (OJ-safe)
// =====================
#define LOCAL
#ifdef LOCAL

template <typename T> void dump(const T &a, const char *name) {
    cerr << name << " = ";
    for (const auto &x : a)
        cerr << x << ' ';
    cerr << '\n';
}

template <typename T> void dump2D(const T &a, const char *name) {
    cerr << name << ":\n";
    for (const auto &row : a) {
        for (const auto &x : row)
            cerr << x << ' ';
        cerr << '\n';
    }
}

#define DUMP(x) dump(x, #x)
#define DUMP2D(x) dump2D(x, #x)

#else
#define DUMP(x)
#define DUMP2D(x)
#endif

class TreeNode {
  public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        left = right = nullptr;
    }
};

/* Approach 1 (Inorder Divide & Conquer): */
class Solution {
  private:
    // inorder traversal: store BST values in sorted order
    void inorder(TreeNode *&root, vec<int> &in) {
        // base case: null node
        if (!root)
            return;

        // traverse left subtree
        inorder(root->left, in);
        // visit current node
        in.pb(root->val);
        // traverse right subtree
        inorder(root->right, in);
    }

    // build balanced BST from sorted inorder array
    TreeNode *makeBST(int st, int en, vec<int> &in) {
        // base case: invalid range
        if (st > en)
            return nullptr;

        // pick middle element as root
        int mid = st + ((en - st) >> 1);
        TreeNode *root = new TreeNode(in[mid]);
        // recursively build left subtree
        root->left = makeBST(st, mid - 1, in);
        // recursively build right subtree
        root->right = makeBST(mid + 1, en, in);

        // return constructed subtree
        return root;
    }

  public:
    TreeNode *balanceBST(TreeNode *root) {
        // init: store inorder traversal
        vec<int> in;
        // step 1: get sorted values from BST
        inorder(root, in);

        // step 2: build balanced BST from sorted array
        return makeBST(0, sz(in) - 1, in);
    }
};

void inorder(TreeNode *&root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution obj;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(5);
    inorder(root);
    return 0;
}

/*
Problem: Balance a Binary Search Tree
*/