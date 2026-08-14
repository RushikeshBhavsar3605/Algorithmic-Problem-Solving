#include "template.hpp"

class SegTree {
  public:
    struct Node {
        char leftChar = 0, rightChar = 0;
        int pre = 0, suf = 0;
        int maxLen = 0;
    };

    int n;
    vector<Node> tree;

    Node merge(Node leftNode, Node rightNode, int leftLen, int rightLen) {
        Node res;
        res.leftChar = leftNode.leftChar;
        res.rightChar = rightNode.rightChar;

        if (leftNode.pre == leftLen && leftNode.rightChar == rightNode.leftChar)
            res.pre = leftNode.pre + rightNode.pre;
        else
            res.pre = leftNode.pre;

        if (rightNode.suf == rightLen && leftNode.rightChar == rightNode.leftChar)
            res.suf = leftNode.suf + rightNode.suf;
        else
            res.suf = rightNode.suf;

        res.maxLen = max(leftNode.maxLen, rightNode.maxLen);
        if (leftNode.rightChar == rightNode.leftChar)
            res.maxLen = max(res.maxLen, leftNode.suf + rightNode.pre);

        return res;
    }

    void build(int i, int l, int r, const string &s) {
        if (l == r) {
            tree[i] = {s[l], s[l], 1, 1, 1};
            return;
        }

        int mid = l + ((r - l) >> 1);

        build(2 * i + 1, l, mid, s);
        build(2 * i + 2, mid + 1, r, s);

        tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2], mid - l + 1, r - mid);
    }

    void update(int i, int l, int r, int pos, char ch) {
        if (l == r) {
            tree[i] = {ch, ch, 1, 1, 1};
            return;
        }

        int mid = l + ((r - l) >> 1);
        if (pos <= mid)
            update(2 * i + 1, l, mid, pos, ch);
        else
            update(2 * i + 2, mid + 1, r, pos, ch);

        tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2], mid - l + 1, r - mid);
    }

    SegTree(string &s) {
        n = sz(s);
        tree.resize(4 * n);
        build(0, 0, n - 1, s);
    }
};

/* Approach (Segment Tree): */
class Solution {
  public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int> &queryIndices) {
        vi res;
        SegTree tree(s);

        loop(i, 0, sz(queryIndices)) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            tree.update(0, 0, sz(s) - 1, pos, ch);

            res.pb(tree.tree[0].maxLen);
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 3, 3};
    auto res = obj.longestRepeating("babacc", "bcb", v);
    print(res);
    v = {2, 1};
    res = obj.longestRepeating("abyzz", "aa", v);
    print(res);
    return 0;
}

/*
Problem: Longest Substring of One Repeating Character
*/