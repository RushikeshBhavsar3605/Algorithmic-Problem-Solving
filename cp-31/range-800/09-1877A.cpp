#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int input;
        int res = 0;

        for (int i = 0; i < n - 1; i++) {
            cin >> input;
            res += input;
        }

        cout << -1 * res << endl;
    }

    return 0;
}