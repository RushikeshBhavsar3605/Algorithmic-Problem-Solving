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

class SegmentTree {
  private:
    vi count;
    vi covered;
    vi xs;
    int n;

    void modify(int qleft, int qright, int qval, int left, int right, int pos) {
        if (xs[right + 1] <= qleft || xs[left] >= qright)
            return;
        if (qleft <= xs[left] && xs[right + 1] <= qright)
            count[pos] += qval;
        else {
            int mid = left + (right - left) / 2;
            modify(qleft, qright, qval, left, mid, pos * 2 + 1);
            modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
        }

        if (count[pos] > 0)
            covered[pos] = xs[right + 1] - xs[left];
        else {
            if (left == right)
                covered[pos] = 0;
            else
                covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
        }
    }

  public:
    SegmentTree(vi &xs_) : xs(xs_) {
        n = sz(xs) - 1;
        count.resize(4 * n, 0);
        covered.resize(4 * n, 0);
    }

    void update(int qleft, int qright, int qval) {
        modify(qleft, qright, qval, 0, n - 1, 0);
    }

    int query() {
        return covered[0];
    }
};

/* Approach 1 (Segment Tree): */
class Solution {
  public:
    double separateSquares(vector<vector<int>> &squares) {
        vector<tuple<int, int, int, int>> events;
        set<int> xsSet;

        iterate(sq, squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            int xr = x + l;
            events.emplace_back(y, 1, x, xr);
            events.emplace_back(y + l, -1, x, xr);
            xsSet.insert(x);
            xsSet.insert(xr);
        }

        sort(all(events));
        vi xs(all(xsSet));
        SegmentTree segTree(xs);

        vector<double> psum;
        vi widths;
        double totalArea = 0.0;
        int prev = get<0>(events[0]);

        iterate(it, events) {
            int y = get<0>(it);
            int delta = get<1>(it);
            int xl = get<2>(it);
            int xr = get<3>(it);

            int len = segTree.query();
            totalArea += 1LL * len * (y - prev);
            segTree.update(xl, xr, delta);

            psum.pb(totalArea);
            widths.pb(segTree.query());
            prev = y;
        }

        ll target = (ll)(totalArea + 1) / 2;
        int i = lower_bound(all(psum), target) - psum.begin() - 1;

        double area = psum[i];
        int width = widths[i], height = get<0>(events[i]);

        return height + (totalArea - area * 2) / (width * 2.0);
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 0, 1}, {2, 2, 1}};
    println(obj.separateSquares(v));
    v = {{0, 0, 2}, {1, 1, 1}};
    println(obj.separateSquares(v));
}

/*
Problem: Separate Squares II
*/