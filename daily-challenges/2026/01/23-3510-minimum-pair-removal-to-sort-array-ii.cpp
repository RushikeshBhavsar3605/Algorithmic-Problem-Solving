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

/* Approach 1 (Greedy + LL Simulation): */
class Solution {
  public:
    int minimumPairRemoval(vector<int> &nums) {
        int n = sz(nums);

        vector<ll> temp(n);
        loop(i, 0, n) temp[i] = nums[i];

        set<pair<ll, int>> minPairSet;

        vi nextIdx(n);
        vi prevIdx(n);
        loop(i, 0, n) {
            nextIdx[i] = i + 1;
            prevIdx[i] = i - 1;
        }

        int badPairs = 0;
        loop(i, 0, n - 1) {
            if (temp[i] > temp[i + 1])
                badPairs++;

            minPairSet.insert({temp[i] + temp[i + 1], i});
        }

        int ops = 0;

        while (badPairs) {
            int first = minPairSet.begin()->ss;
            int second = nextIdx[first];

            int firstLeft = prevIdx[first];
            int secondRight = nextIdx[second];

            minPairSet.erase(begin(minPairSet));

            if (temp[first] > temp[second])
                badPairs--;

            // {d, (a, b)}
            if (firstLeft >= 0) {
                if (temp[firstLeft] > temp[first] &&
                    temp[firstLeft] <= temp[first] + temp[second])
                        badPairs--;
                else if (temp[firstLeft] <= temp[first] &&
                    temp[firstLeft] > temp[first] + temp[second])
                        badPairs++;
            }

            // {(a, b), d}
            if (secondRight < n) {
                if (temp[secondRight] >= temp[second] &&
                    temp[secondRight] < temp[first] + temp[second])
                        badPairs++;
                else if (temp[secondRight] < temp[second] &&
                    temp[secondRight] >= temp[first] + temp[second])
                        badPairs--;
            }

            if (firstLeft >= 0) {
                minPairSet.erase({temp[firstLeft] + temp[first], firstLeft});
                minPairSet.insert({temp[firstLeft] + temp[first] + temp[second], firstLeft});
            }

            if (secondRight < n) {
                minPairSet.erase({temp[second] + temp[secondRight], second});
                minPairSet.insert({temp[first] + temp[second] + temp[secondRight], first});
                prevIdx[secondRight] = first;
            }

            nextIdx[first] = secondRight;
            temp[first] += temp[second];

            ops++;
        }

        return ops;
    }
};

int main() {
    Solution obj;
    vi v = {5, 2, 3, 1};
    println(obj.minimumPairRemoval(v));
    v = {1, 2, 2};
    println(obj.minimumPairRemoval(v));
}

/*
Problem: Minimum Pair Removal to Sort Array II
*/