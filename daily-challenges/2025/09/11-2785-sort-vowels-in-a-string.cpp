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
  public:
    string sortVowels(string s) {
        // Define set of all vowels (lowercase and uppercase)
        set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        // Min heap to store vowels in sorted order
        priority_queue<char, vector<char>, greater<char>> max_Heap;

        // Store indices where vowels are found
        set<int> vowelsIdx;

        // Extract vowels and their positions
        loop(i, 0, sz(s))
            if (st.count(s[i])) {
                max_Heap.push(s[i]);
                vowelsIdx.insert(i);
            }

        // Rebuild string: replace vowels with sorted ones, keep consonants unchanged
        string result;
        loop(i, 0, sz(s))
            if (vowelsIdx.count(i)) {
                result.pb(max_Heap.top());
                max_Heap.pop();
            }
            else
                result.pb(s[i]);

        return result;
    }
};

int main() {
    Solution obj;
    cout << obj.sortVowels("lEetcOde") << endl;
    cout << obj.sortVowels("lYmpH") << endl;
}

/*
Problem: Sort Vowels in a String
*/