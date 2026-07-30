#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;

        if (y >= z)
            cout << -1 << endl;
        else {
            int price = x;
            int coins = 0;

            int ops = 0;
            while (coins < price) {
                price += y;
                coins += z;
                ops++;
            }

            cout << ops << endl;
        }
    }

    return 0;
}