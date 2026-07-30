#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        bool res = false;

        long long newA = 2 * b - c;
        if (newA / a > 0 && newA % a == 0)
            res = true;

        long long newB = (a + c) / 2;
        if (newB / b > 0 && newB % b == 0 && (c - a) % 2 == 0)
            res = true;

        long long newC = 2 * b - a;
        if (newC / c > 0 && newC % c == 0)
            res = true;

        if (res)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}