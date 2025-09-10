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
    // Check if two users cannot communicate (no shared language)
    bool isSad(int u, int v, vvi &languages) {
        iterate(lang_u, languages[u])
            iterate(lang_v, languages[v])
                if (lang_u == lang_v)
                    return false; // Found common language

        return true; // No common language found
    }

  public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships) {
        set<int> sadUsers;

        // Find all users involved in friendships where they can't communicate
        iterate(friendship, friendships) {
            int u = friendship[0] - 1; // Convert to 0-indexed
            int v = friendship[1] - 1; // Convert to 0-indexed

            if (isSad(u, v, languages))
                sadUsers.insert({u, v}); // Fixed: insert individual users
        }

        // Count how many sad users already know each language
        map<int, int> languageCount;
        iterate(user, sadUsers)
            iterate(user, languages[user]) // Fixed: use different variable name
                languageCount[user]++;

        // Find language known by most sad users
        int maxKnown = 0;
        iterate(it, languageCount)
            updateMax(maxKnown, it.ss);

        // Answer: total sad users minus those who already know the best language
        return sz(sadUsers) - maxKnown;
    }
};

int main() {
    Solution obj;
    vvi v1 = {{1}, {2}, {1, 2}};
    vvi v2 = {{1, 2}, {1, 3}, {2, 3}};
    cout << obj.minimumTeachings(2, v1, v2) << endl;
    v1 = {{2}, {1, 3}, {1, 2}, {3}};
    v2 = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};
    cout << obj.minimumTeachings(3, v1, v2) << endl;
}

/*
Problem: Minimum Number of People to Teach
*/