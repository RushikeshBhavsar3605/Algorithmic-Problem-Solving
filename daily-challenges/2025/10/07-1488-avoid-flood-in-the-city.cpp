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

class Solution {
  public:
    vector<int> avoidFlood(vector<int> &rains) {
        int n = sz(rains);

        umap<int, int> mp; // lake -> last day it rained on this lake (full since then)
        set<int> st;       // indices of dry days available to use

        vi result(n, 1); // default: 1 for dry days; set to -1 on rain days; set to lake id when drying

        loop(i, 0, n) {
            int lake = rains[i];

            if (lake == 0)
                st.insert(i);   // record this dry day for future use
            else {
                result[i] = -1; // raining today, cannot dry on a rain day

                if (mp.count(lake)) {
                    // find the earliest dry day index > last rain of this lake
                    auto it = st.lower_bound(mp[lake]);
                    if (it == st.end())
                        return {}; // no available dry day after last rain -> impossible

                    int day = *it;
                    result[day] = lake; // dry this lake on that dry day
                    st.erase(it);       // consume the dry day
                }

                mp[lake] = i; // update last rain day for this lake
            }
        }

        return result;
    }
};

int main() {
    Solution obj;
    vi v = {1, 2, 3, 4};
    dump(obj.avoidFlood(v));
    v = {1, 2, 0, 0, 2, 1};
    dump(obj.avoidFlood(v));
    v = {1, 2, 0, 1, 2};
    dump(obj.avoidFlood(v));
}

/*
Problem: Avoid Flood in The City
*/