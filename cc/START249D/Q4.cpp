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

        int left = INT_MIN;
        int right = INT_MAX;

        bool flag = true;
        int half = n / 2;

        for (int i = 0; i < half; i++) {
            int a = v[i];
            int b = v[n - i - 1];

            int d = abs(a - b);
            if (d == 0)
                continue;

            if (d != 2) {
                flag = false;
                break;
            }

            left = max(left, min(a, b));
            right = min(right, max(a, b) - 1);

            if (left > right) {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}