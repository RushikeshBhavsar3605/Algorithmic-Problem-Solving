#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k, x;
        cin >> n >> k >> x;

        long long minSum = (k * (k + 1)) / 2;
        long long maxSum = (k * (2LL * n - k + 1)) / 2;

        if (minSum <= x && x <= maxSum)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}