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

/* Approach 1 (Naive): */
class Solution {
  private:
    unordered_set<string> exactSet;
    umap<string, string> caseMp;
    umap<string, string> vowelMp;

    string toLower(string &s) {
        string result = s;
        iterate(ch, result) ch = tolower(ch);

        return result;
    }

    string replaceVowel(string &s) {
        string result = s;
        iterate(ch, result) if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ch = '*';

        return result;
    }

    string checkForMatch(string &query) {
        if (exactSet.count(query))
            return query;

        string lowerCase = toLower(query);
        if (caseMp.count(lowerCase))
            return caseMp[lowerCase];

        string vowelCase = replaceVowel(lowerCase);
        if (vowelMp.count(vowelCase))
            return vowelMp[vowelCase];

        return "";
    }

  public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries) {
        exactSet.clear();
        caseMp.clear();
        vowelMp.clear();

        iterate(word, wordlist) {
            exactSet.insert(word);

            string lowerCase = toLower(word);
            if (caseMp.find(lowerCase) == caseMp.end())
                caseMp[lowerCase] = word;

            string vowelCase = replaceVowel(lowerCase);
            if (vowelMp.find(vowelCase) == vowelMp.end())
                vowelMp[vowelCase] = word;
        }

        vector<string> result;
        iterate(query, queries) result.pb(checkForMatch(query));

        return result;
    }
};

int main() {
    Solution obj;
    vector<string> v1 = {"KiTe", "kite", "hare", "Hare"};
    vector<string> v2 = {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"};
    vector<string> result = obj.spellchecker(v1, v2);
    dump(result);
}

/*
Problem: Vowel Spellchecker
*/