#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int maxi = 1, cnt = 1;

        for (int i = 1; i < n; i++) {
            if (s[i - 1] == s[i])
                cnt++;
            else
                cnt = 1;

            maxi = max(maxi, cnt);
        }

        cout << maxi + 1 << endl;
    }

    return 0;
}