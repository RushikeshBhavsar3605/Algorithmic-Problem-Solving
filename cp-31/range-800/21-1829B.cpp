#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, input;
        cin >> n;

        int maxi = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> input;
            if (input == 0)
                cnt++;
            else
                cnt = 0;

            maxi = max(maxi, cnt);
        }

        cout << maxi << endl;
    }

    return 0;
}