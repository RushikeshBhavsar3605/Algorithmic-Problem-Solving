#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int res = 0;
        int base = 1;

        while (base <= n) {
            for (int d = 1; d < 10; d++)
                if (d * base <= n)
                    res++;

            base *= 10;
        }

        cout << res << endl;
    }

    return 0;
}