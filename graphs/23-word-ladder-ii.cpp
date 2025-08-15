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

class Solution {
  public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        uset<string> st(all(wordList));

        queue<vector<string>> q;
        q.push({beginWord});

        vector<string> usedOnLevel;
        usedOnLevel.pb(beginWord);

        int level = 0;
        vector<vector<string>> result;

        while (!q.empty()) {
            vector<string> vec = q.front();
            q.pop();

            if (vec.size() > level) {
                level++;
                iterate(it, usedOnLevel)
                    st.erase(it);
                usedOnLevel.clear();
            }

            string word = vec.back();

            if (word == endWord)
                if (sz(result) == 0)
                    result.pb(vec);
                else if (sz(result[0]) == sz(vec))
                    result.pb(vec);

            loop(i, 0, sz(word)) {
                char original = word[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.count(word) > 0) {
                        vec.pb(word);
                        q.push(vec);
                        usedOnLevel.pb(word);
                        vec.pop_back();
                    }
                }

                word[i] = original;
            }
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