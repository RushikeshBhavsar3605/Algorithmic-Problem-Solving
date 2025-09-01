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

/* Approach 1 (Naive):
class Solution {
  private:
    string getSortedStr(int n) {
        string s = to_string(n);
        sort(all(s));

        return s;
    }

  public:
    bool reorderedPowerOf2(int n) {
        string s = getSortedStr(n);

        loop(power, 0, 30)
            if (s == getSortedStr(1 << power))
                return true;

        return false;
    }
};
*/

/* Approach 2 (Precompute):
class Solution {
  private:
    unordered_set<string> st;
    void buildSet() {
        loop(power, 0, 30) {
            string s = to_string(1 << power);
            sort(all(s));
            st.insert(s);
        }
    }

  public:
    bool reorderedPowerOf2(int n) {
        if (st.empty())
            buildSet();

        string s = to_string(n);
        sort(all(s));

        return st.count(s);
    }
};
*/

/* Approach 3 (Hashing):
class Solution {
  private:
    vector<int> getVectorCountFormat(int n) {
        vi v(10, 0);

        while (n) {
            v[n % 10]++;
            n /= 10;
        }

        return v;
    }

  public:
    bool reorderedPowerOf2(int n) {
        vi input = getVectorCountFormat(n);

        loop(power, 0, 30)
            if (input == getVectorCountFormat(1 << power))
                return true;

        return false;
    }
};
*/

/* Approach 4 (Hashing Optimized): */
class Solution {
  private:
    int getCountFormat(int n) {
        int num = 0;

        while (n) {
            num += pow(10, n % 10);
            n /= 10;
        }

        return num;
    }

  public:
    bool reorderedPowerOf2(int n) {
        int input = getCountFormat(n);

        loop(power, 0, 30)
            if (input == getCountFormat(1 << power))
                return true;

        return false;
    }
};

int main() {
    Solution obj;
    cout << obj.reorderedPowerOf2(1) << endl;
    cout << obj.reorderedPowerOf2(10) << endl;
    return 0;
}

/*
Problem: Reordered Power of 2
*/