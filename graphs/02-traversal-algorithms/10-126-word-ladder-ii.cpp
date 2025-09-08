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

/* Approach 1 (Breadth First Search) (Interview Ready):
class Solution {
  public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        uset<string> st(all(wordList)); // store all words for quick lookup

        queue<vector<string>> q;
        q.push({beginWord}); // BFS queue, stores paths instead of single words

        vector<string> usedOnLevel;
        usedOnLevel.pb(beginWord); // track words used at current BFS level

        int level = 0;
        vector<vector<string>> result; // stores final shortest transformation sequences

        while (!q.empty()) {
            vector<string> vec = q.front();
            q.pop();

            if (vec.size() > level) { // moved to next BFS level
                level++;
                iterate(it, usedOnLevel) // remove words used in previous level
                    st.erase(it);
                usedOnLevel.clear();
            }

            string word = vec.back(); // current word

            if (word == endWord)     // found transformation
                if (sz(result) == 0) // first valid sequence
                    result.pb(vec);
                else if (sz(result[0]) == sz(vec)) // only store shortest sequences
                    result.pb(vec);

            loop(i, 0, sz(word)) {
                char original = word[i];

                for (char c = 'a'; c <= 'z'; c++) { // try all possible one-letter transformations
                    word[i] = c;
                    if (st.count(word) > 0) { // if new word exists in wordList
                        vec.pb(word);
                        q.push(vec);          // push new path
                        usedOnLevel.pb(word); // mark word used at this level
                        vec.pop_back();       // backtrack path
                    }
                }

                word[i] = original; // restore original char
            }
        }

        return result; // return all shortest sequences
    }
};
*/

/* Approach 2 (BFS + DFS Optimized): */
class Solution {
  private:
    void dfs(string word, string &beginWord, vector<string> &seq, umap<string, int> &mp,
             vector<vector<string>> &result) {
        if (word == beginWord) { // reached start word, sequence complete
            reverse(all(seq));   // reverse to get correct order (begin → end)
            result.pb(seq);
            reverse(all(seq)); // restore order for backtracking
            return;
        }

        int steps = mp[word]; // current BFS depth of word
        loop(i, 0, sz(beginWord)) {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) { // try all single-letter changes
                word[i] = ch;
                if (mp.find(word) != mp.end() && mp[word] < steps) {
                    // only move to previous BFS level (shortest path guarantee)
                    seq.pb(word);
                    dfs(word, beginWord, seq, mp, result); // backtrack DFS
                    seq.pop_back();
                }
            }

            word[i] = original; // restore original char
        }
    }

  public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        int n = sz(beginWord);
        vector<vector<string>> result;

        queue<string> q;
        q.push(beginWord);

        umap<string, int> mp; // stores shortest distance (steps) from beginWord
        mp[beginWord] = 1;

        unordered_set<string> st(all(wordList)); // word lookup set
        st.erase(beginWord);

        // BFS to compute shortest distance of each word from beginWord
        while (!q.empty()) {
            string word = q.front();
            int steps = mp[word];
            q.pop();

            if (word == endWord) // stop BFS when endWord is reached
                break;

            loop(i, 0, n) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) { // word exists in dictionary
                        q.push(word);
                        st.erase(word); // ensure shortest path only
                        mp[word] = steps + 1;
                    }
                }

                word[i] = original;
            }
        }

        // If endWord is reachable, reconstruct all shortest paths using DFS
        if (mp.find(endWord) != mp.end()) {
            vector<string> seq;
            seq.pb(endWord);
            dfs(endWord, beginWord, seq, mp, result);
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<string> v = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> result = obj.findLadders("hit", "cog", v);
    iterate(it, result) {
        iterate(i, it) cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem: Word Ladder II
*/