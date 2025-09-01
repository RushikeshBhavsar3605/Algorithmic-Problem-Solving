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

class Solution {
  public:
    vector<int> productQueries(int n, vector<vector<int>> &queries) {
        int maxPower = 0;
        revloop(i, 30, 0)
            if ((1 << i) <= n) {
                maxPower = i;
                break;
            }

        vi powers;
        revloop(bitIndex, maxPower, 0) {
            int powerOfTwo = (1 << bitIndex);
            powers.pb(powerOfTwo);
        }
        dump(powers);

        reverse(all(powers));

        vi result;
        iterate(query, queries) {
            int product = 1;
            loop(i, query[0], query[1] + 1){
cout<<"["<<powers[i]<<", "<<i<<"]"<<" ";
                product *= powers[i];
            }
            cout<<endl;

            result.pb(product);
        }

        cout<<endl;
        return result;
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 1}, {2, 2}, {0, 3}};
    vi result = obj.productQueries(15, v);
    iterate(it, result) cout << it << " ";
    cout<<endl;
    v = {{2,3},{0,1},{0,1},{0,1},{0,0},{0,3},{3,3},{2,3},{1,1},{2,3}};
    result = obj.productQueries(53, v);
    iterate(it, result) cout << it << " ";
    return 0;
}

/*
Problem: Range Product Queries of Powers
*/