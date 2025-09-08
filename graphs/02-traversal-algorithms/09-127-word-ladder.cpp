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

/* Approach 1 (Graph Breadth First Search): */
class Solution {
  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        queue<pair<string, int>> q; // BFS queue: {current word, steps taken}
        q.push({beginWord, 1});

        unordered_set<string> st(all(wordList)); // store wordList for O(1) lookup
        st.erase(beginWord);                     // avoid revisiting start word

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endWord) // found target
                return steps;

            loop(i, 0, sz(word)) {
                char original = word[i]; // store original char

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;                    // try every possible letter
                    if (st.find(word) != st.end()) { // valid transformation
                        st.erase(word);              // mark as visited
                        q.push({word, steps + 1});   // push next state
                    }
                }

                word[i] = original; // restore word for next iteration
            }
        }

        return 0; // no transformation found
    }
};

int main() {
    Solution obj;
    vector<string> v = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << obj.ladderLength("hit", "cog", v);
    return 0;
}

/*
Problem: Word Ladder
*/