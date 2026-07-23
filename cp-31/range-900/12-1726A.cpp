#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        int res = 0;
        int mini = INT_MAX, maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            res = max(res, v[i] - v[(i + 1) % n]);
            mini = min(mini, v[i]);
            maxi = max(maxi, v[i]);
        }

        res = max(res, v[n - 1] - mini);
        res = max(res, maxi - v[0]);

        cout << res << endl;
    }

    return 0;
}