#include "template.hpp"

/* Approach (Prefix + Binary Search): */
class Solution {
  public:
    vector<int> countTasks(vector<int> &tasks, vector<int> &shifts) {
        int n = sz(tasks);
        vl pre(n + 1, 0);

        loop(i, 0, n) pre[i + 1] = pre[i] + tasks[i];

        ll total = pre[n];
        ll done = 0;
        vi res;

        iterate(t, shifts) {
            done += t;

            if (done >= total) {
                res.pb(0);
                done = 0;
            } else {
                int completed = upper_bound(all(pre), done) - begin(pre) - 1;
                res.pb(n - completed);
            }
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi t = {1, 4, 4};
    vi s = {9, 1, 4};
    auto res = obj.countTasks(t, s);
    print(res);
    t = {2, 3, 4};
    s = {20, 4, 5};
    res = obj.countTasks(t, s);
    print(res);
    t = {4, 2};
    s = {3, 6, 1};
    res = obj.countTasks(t, s);
    print(res);
    return 0;
}

/*
Problem: Count of Unfinished Tasks After Each Shift
*/