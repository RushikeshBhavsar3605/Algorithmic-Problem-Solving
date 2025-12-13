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

/* Approach 1 (Naive): */
class Solution {
  private:
    bool isValidCode(string code) {
        if (sz(code) == 0)
            return false;

        iterate(it, code)
            if (('a' <= it && it <= 'z') || ('A' <= it && it <= 'Z') || ('0' <= it && it <= '9') || (it == '_'));
        else return false;

        return true;
    }

    bool isValidBusinessLine(string businessLine) {
        if (businessLine == "electronics" || businessLine == "grocery" || businessLine == "pharmacy" || businessLine == "restaurant")
            return true;

        return false;
    }

  public:
    vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive) {
        vector<pair<string, string>> mp;

        loop(i, 0, sz(code))
            if (isValidCode(code[i]) && isValidBusinessLine(businessLine[i]) && isActive[i])
                mp.pb({businessLine[i], code[i]});

        sort(all(mp));
        vector<string> result;
        iterate(it, mp)
            result.pb(it.ss);

        return result;
    }
};

int main() {
    Solution obj;
    vector<string> code = {"SAVE20", "", "PHARMA5", "SAVE@20"};
    vector<string> businessLine = {"restaurant", "grocery", "pharmacy", "restaurant"};
    vector<bool> isActive = {true, true, true, true};
    dump(obj.validateCoupons(code, businessLine, isActive));
    code = {"GROCERY15", "ELECTRONICS_50", "DISCOUNT10"};
    businessLine = {"grocery", "electronics", "invalid"};
    isActive = {false, true, true};
    dump(obj.validateCoupons(code, businessLine, isActive));
}

/*
Problem: Coupon Code Validator
*/