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

        int ops = 0;

        for (int i = n - 2; i >= 0; i--) {
            if (v[i + 1] == 0) {
                ops = -1;
                break;
            }
            while (v[i] >= v[i + 1]) {
                v[i] /= 2;
                ops++;
            }
        }

        cout << ops << endl;
    }

    return 0;
}