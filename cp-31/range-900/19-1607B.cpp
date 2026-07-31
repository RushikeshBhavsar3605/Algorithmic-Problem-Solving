#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long x, n;
        cin >> x >> n;

        long long pos;

        if (n % 4 == 0)
            pos = 0;
        else if (n % 4 == 1)
            pos = -n;
        else if (n % 4 == 2)
            pos = 1;
        else
            pos = n + 1;

        if (x % 2 == 0)
            pos = x + pos;
        else
            pos = x - pos;

        cout << pos << endl;
    }

    return 0;
}