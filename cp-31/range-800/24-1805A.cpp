#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, input;
        cin >> n;

        int totalXOR = 0;
        for (int i = 0; i < n; i++) {
            cin >> input;
            totalXOR ^= input;
        }

        if (n & 1)
            cout << totalXOR << endl;
        else {
            if (totalXOR == 0)
                cout << totalXOR << endl;
            else
                cout << -1 << endl;
        }
    }

    return 0;
}