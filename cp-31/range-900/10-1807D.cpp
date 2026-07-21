#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + v[i];

        int l, r, k;
        for (int i = 0; i < q; i++) {
            cin >> l >> r >> k;

            long long sum = prefix[l - 1] + (prefix[n] - prefix[r]) + (r - l + 1) * k;

            if (sum & 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}