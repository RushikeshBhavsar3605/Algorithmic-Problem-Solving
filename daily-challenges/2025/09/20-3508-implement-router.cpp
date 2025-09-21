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

/* Approach 1 (Naive) (MLE):
class Router {
  private:
    int limit;
    queue<vi> q;
    set<vi> st;
    map<int, vi> mp;

    void removePacket() {
        auto packet = q.front();
        q.pop();
        st.erase(packet);
        *lower_bound(all(mp[packet[1]]), packet[2]) = 0;
    }

  public:
    Router(int memoryLimit) {
        limit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        if (st.count({source, destination, timestamp}))
            return false;

        q.push({source, destination, timestamp});
        st.insert({source, destination, timestamp});
        mp[destination].pb(timestamp);

        if (sz(q) > limit)
            removePacket();

        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty())
            return {};

        vi v = q.front();
        removePacket();
        return v;
    }

    int getCount(int destination, int startTime, int endTime) {
        vi v = mp[destination];
        return upper_bound(all(v), endTime) - lower_bound(all(v), startTime);
    }
};
*/

/* Approach 2 (): */
class Router {
  private:
    int memoryLimit;
    deque<tuple<int, int, int>> q;
    unordered_set<string> seen;
    umap<int, vi> destMap;

    string makeKey(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

    void removeFromDestMap(int dest, int timestamp) {
        auto &v = destMap[dest];
        auto it = lower_bound(all(v), timestamp);
        if (it != v.end() && *it == timestamp)
            v.erase(it);
    }

  public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);
        if (seen.count(key))
            return false;

        if (sz(q) >= memoryLimit) {
            auto [os, od, ot] = q.front();
            q.pop_front();
            seen.erase(makeKey(os, od, ot));
            removeFromDestMap(od, ot);
        }

        q.pb({source, destination, timestamp});
        seen.insert(key);
        destMap[destination].pb(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty())
            return {};

        auto [s, d, t] = q.front();
        q.pop_front();
        seen.erase(makeKey(s, d, t));
        removeFromDestMap(d, t);

        return {s, d, t};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto &v = destMap[destination];
        auto l = lower_bound(all(v), startTime);
        auto r = upper_bound(all(v), endTime);

        return r - l;
    }
};

int main() {
    Router obj(3);
    obj.addPacket(1, 4, 90);
    obj.addPacket(2, 5, 90);
    obj.addPacket(1, 4, 90);
    obj.addPacket(3, 5, 95);
    obj.addPacket(4, 5, 105);
    dump(obj.forwardPacket());
    obj.addPacket(5, 2, 110);
    cout << obj.getCount(5, 100, 110) << endl;
}

/*
Problem: Implement Router
*/