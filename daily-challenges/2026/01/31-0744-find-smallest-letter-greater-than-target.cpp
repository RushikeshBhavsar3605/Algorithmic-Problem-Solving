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

// Printing to stdout (iostream)
#define print(x)                                                                                                       \
    do {                                                                                                               \
        std::cout << (x);                                                                                              \
    } while (0)
#define println(x)                                                                                                     \
    do {                                                                                                               \
        std::cout << (x) << '\n';                                                                                      \
    } while (0)

/* Approach 1 (Brute Force):
class Solution {
  public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        char mini = '{';
        iterate(ch, letters)
            if (ch > target && ch < mini)
                mini = ch;

        return mini != '{' ? mini : letters[0];
    }
};
*/

/* Approach 2 (Binary Search): */
class Solution {
  public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int n = sz(letters);
        if (letters[n - 1] <= target)
            return letters[0];

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (letters[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return letters[left];
    }
};

int main() {
    Solution obj;
    vector<char> v = {'c', 'f', 'j'};
    println(obj.nextGreatestLetter(v, 'a'));
    v = {'c', 'f', 'j'};
    println(obj.nextGreatestLetter(v, 'c'));
    v = {'x', 'x', 'y', 'y'};
    println(obj.nextGreatestLetter(v, 'z'));
}

/*
Problem: Minimum Cost to Convert String I
*/