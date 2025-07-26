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
        left = right = nullptr;
    }
};

/* Approach 1 (Depth First Search):
class Codec {
  private:
    // Recursively builds tree from serialized data tokens
    TreeNode *build(const string &data, int &index) {
        // Stop if we've consumed all characters
        if (index >= data.size())
            return nullptr;

        // Find next comma (or end) to isolate current token
        auto comma = data.find(',', index);
        if (comma == string::npos)
            comma = data.size();

        // Extract the token and advance index past it
        string token = data.substr(index, comma - index);
        index = comma + 1;

        // Null‑marker?
        if (token == "#")
            return nullptr;

        // Create node from integer token
        int val = stoi(token);
        TreeNode *root = new TreeNode(val);

        // Build left and right subtrees in preorder
        root->left = build(data, index);
        root->right = build(data, index);

        return root;
    }

  public:
    // Encodes a tree to a single string.
    // Encodes a tree to a single comma‑separated string ("#,1,2,#,#,...")
    string serialize(TreeNode *root) {
        if (!root)
            return "#"; // null marker

        // Preorder: root, left, right
        string encode = to_string(root->val);
        encode += "," + serialize(root->left);
        encode += "," + serialize(root->right);

        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        int index = 0; // current parse position in the serialized string
        return build(data, index);
    }
};
*/

/* Approach 1 (Breadth First Search): */
class Codec {
  public:
    // Encodes a tree to a single string.
    // Encodes a binary tree to a single string using level-order (BFS) traversal.
    string serialize(TreeNode *root) {
        if (!root)
            return "#"; // Null tree represented by a single "#"

        string encode = to_string(root->val);
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            // Process left child
            if (node->left) {
                encode += "," + to_string(node->left->val);
                q.push(node->left);
            } else
                encode += ",#"; // Use "#" to represent null

            // Process right child
            if (node->right) {
                encode += "," + to_string(node->right->val);
                q.push(node->right);
            } else
                encode += ",#"; // Use "#" to represent null
        }

        return encode;
    }

    // Decodes your encoded data to tree.
    // Decodes the string back to the binary tree structure using BFS.
    TreeNode *deserialize(string data) {
        if (data == "#")
            return nullptr; // Empty tree

        int index = 0;

        // Lambda to extract the next comma-separated token from the data string
        auto nextToken = [&]() -> string {
            auto comma = data.find(',', index);
            if (comma == string::npos)
                comma = data.size();
            string token = data.substr(index, comma - index);
            index = comma + 1;
            return token;
        };

        TreeNode *root = new TreeNode(stoi(nextToken()));
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            // Process left child
            string leftVal = nextToken();
            if (leftVal != "#") {
                TreeNode *leftNode = new TreeNode(stoi(leftVal));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Process right child
            string rightVal = nextToken();
            if (rightVal != "#") {
                TreeNode *rightNode = new TreeNode(stoi(rightVal));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

void preorder(TreeNode *root) {
    if (!root)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Codec obj;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(555);
    string s = obj.serialize(root);
    TreeNode *newNode = obj.deserialize(s);
    cout << "Preorder: ";
    preorder(newNode);
    cout << endl;
    cout << "Inorder: ";
    inorder(newNode);
    cout << endl;
    return 0;
}

/*
Problem: Serialize and Deserialize Binary Tree
*/