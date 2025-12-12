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
    vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events) {
        vi count(numberOfUsers);
        vi next_online_time(numberOfUsers);
        sort(all(events), [&](const vector<string> &lth, const vector<string> &rth) {
            int lth_timestamp = stoi(lth[1]);
            int rth_timestamp = stoi(rth[1]);

            if (lth_timestamp != rth_timestamp)
                return lth_timestamp < rth_timestamp;

            if (rth[0] == "OFFLINE")
                return false;

            return true;
        });

        iterate(event, events) {
            int curr_time = stoi(event[1]);
            if (event[0] == "MESSAGE") {
                if (event[2] == "ALL")
                    loop(i, 0, numberOfUsers)
                        count[i]++;
                else if (event[2] == "HERE") {
                    loop(i, 0, numberOfUsers)
                        if (next_online_time[i] <= curr_time)
                            count[i]++;
                } else {
                    int idx = 0;
                    loop(i, 0, sz(event[2])) {
                        if (isdigit(event[2][i]))
                            idx = idx * 10 + (event[2][i] - '0');

                        if (i + 1 == sz(event[2]) || event[2][i + 1] == ' ') {
                            count[idx]++;
                            idx = 0;
                        }
                    }
                }
            } else {
                int idx = stoi(event[2]);
                next_online_time[idx] = curr_time + 60;
            }
        }

        return count;
    }
};

int main() {
    Solution obj;
    vector<vector<string>> e = {{"MESSAGE", "10", "id1 id0"}, {"OFFLINE", "11", "0"}, {"MESSAGE", "71", "HERE"}};
    dump(obj.countMentions(2, e));
    e = {{"MESSAGE", "10", "id1 id0"}, {"OFFLINE", "11", "0"}, {"MESSAGE", "12", "ALL"}};
    dump(obj.countMentions(2, e));
    e = {{"OFFLINE", "10", "0"}, {"MESSAGE", "12", "HERE"}};
    dump(obj.countMentions(2, e));
}

/*
Problem: Count Mentions Per User
*/