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

/* Approach 1 (Heap): */
class Solution {
  public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
        // Priority queue stores {gain, pass, total}, ordered by max gain
        priority_queue<vector<double>> pq;

        iterate(cls, classes) {
            double pass = cls[0], total = cls[1];
            double currentRatio = pass / total;
            double newRatio = (pass + 1) / (total + 1);
            double gain = newRatio - currentRatio;

            pq.push({gain, pass + 1, total + 1});
        }

        // Distribute extra students greedily
        while (extraStudents--) {
            auto topClass = pq.top();
            pq.pop();

            double pass = topClass[1], total = topClass[2];
            double newRatio = (pass + 1) / (total + 1);
            double gain = newRatio - (pass / total);

            pq.push({gain, pass + 1, total + 1});
        }

        // Compute final average ratio
        double totalAvg = 0;
        while (!pq.empty()) {
            auto cls = pq.top();
            pq.pop();

            double pass = cls[1] - 1, total = cls[2] - 1; // undo earlier +1
            totalAvg += pass / total;
        }

        return totalAvg / sz(classes);
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 2}, {3, 5}, {2, 2}};
    cout << obj.maxAverageRatio(v, 2) << endl;
    v = {{2, 4}, {3, 9}, {4, 5}, {2, 10}};
    cout << obj.maxAverageRatio(v, 4) << endl;
}

/*
Problem: Maximum Average Pass Ratio
*/