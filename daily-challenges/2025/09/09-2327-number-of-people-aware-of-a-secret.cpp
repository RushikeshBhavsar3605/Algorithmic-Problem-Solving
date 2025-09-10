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

/* Approach 1 (Queue):
class Solution {
  public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        queue<vi> peopleQueue;
        peopleQueue.push({1, delay, forget}); // {personId, daysUntilCanShare, daysUntilForget}
        int newPerson = 2;

        int nextPersonId = 2;
        int daysRemaining = n - 1;

        // Simulate each day
        while (daysRemaining--) {
            int currentQueueSize = sz(peopleQueue);

            // Process all people for current day
            while (currentQueueSize--) {
                int personId = peopleQueue.front()[0];
                int daysUntilCanShare = peopleQueue.front()[1];
                int daysUntilForget = peopleQueue.front()[2];
                peopleQueue.pop();

                // Skip people who forget today
                if (daysUntilForget == 1)
                    continue;

                // Person can share today - create new person and continue existing person
                if (daysUntilCanShare == 1) {
                    peopleQueue.push({personId, daysUntilCanShare, daysUntilForget - 1});
                    peopleQueue.push({nextPersonId, delay, forget});
                    nextPersonId++;
                }
                // Person still waiting to share - just update counters
                else
                    peopleQueue.push({personId, daysUntilCanShare - 1, daysUntilForget - 1});
            }
        }

        return sz(peopleQueue);
    }
};
*/

/* Approach 2 (Dynamic Programming): */
class Solution {
  public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        ll aware = 0, MOD = 1e9 + 7;
        vector<ll> dp(n);
        dp[0] = 1;

        loop(i, 1, n) {
            if (i - delay >= 0)
                aware = (aware + dp[i - delay]) % MOD;
            if (i - forget >= 0)
                aware = (aware - dp[i - forget] + MOD) % MOD;
            dp[i] = aware;
        }

        ll result = 0;
        loop(i, n - forget, n) result = (result + dp[i]) % MOD;

        return result;
    }
};

int main() {
    Solution obj;
    cout << obj.peopleAwareOfSecret(6, 2, 4) << endl;
    cout << obj.peopleAwareOfSecret(4, 1, 3) << endl;
}

/*
Problem: Number of People Aware of a Secret
*/