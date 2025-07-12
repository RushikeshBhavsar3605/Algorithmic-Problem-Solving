#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
class TrieNode
{
public:
    bool isWord;
    unordered_map<char, TrieNode *> children;
    TrieNode() : isWord(false), children(unordered_map<char, TrieNode *>()) {}
};
bool wordBreak(string s, vector<string> &wordDict)
{
    TrieNode *root = new TrieNode();
    for (auto word : wordDict)
    {
        TrieNode *curr = root;
        for (auto c : word)
        {
            if (curr->children.find(c) == curr->children.end())
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->isWord = true;
    }
    vector<bool> dp(s.size(), false);
    for (int i = 0; i < s.size(); i++)
    {
        if (i - 1 == -1 || dp[i - 1])
        {
            TrieNode *curr = root;
            for (int j = i; j < s.size(); j++)
            {
                char c = s[j];
                if (curr->children.find(c) == curr->children.end())
                    break;
                curr = curr->children[c];
                if (curr->isWord)
                    dp[j] = true;
            }
        }
    }
    return dp[s.size() - 1];
}
int main()
{
    vector<string> v = {"leet", "code"};
    cout << wordBreak("leetcode", v) << endl;
    return 0;
}

/*
Problem: Word Break
*/