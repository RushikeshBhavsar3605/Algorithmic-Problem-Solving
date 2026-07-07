#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int srcX, srcY, destX, destY;
        cin >> srcX >> srcY >> destX >> destY;

        if (destY < srcY) {
            cout << -1 << endl;
            continue;
        }

        int moves = destY - srcY;
        srcX += moves;

        if (srcX < destX) {
            cout << -1 << endl;
            continue;
        }

        moves += srcX - destX;
        cout << moves << endl;
    }

    return 0;
}