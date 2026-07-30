#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y, p;
        cin >> x >> y >> p;

        int ops = 0;
        while (x * y < p) {
            if (y < x)
                swap(x, y);
            x++;
            ops++;
        }

        cout << ops << endl;
    }

    return 0;
}