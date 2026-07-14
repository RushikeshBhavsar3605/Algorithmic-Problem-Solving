#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int dx[4] = {-1, 1, -1, 1};
int dy[4] = {-1, -1, 1, 1};

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll kingX, kingY;
        cin >> kingX >> kingY;
        ll queenX, queenY;
        cin >> queenX >> queenY;

        set<pair<int, int>> kingHits, QueenHits;
        for (int i = 0; i < 4; i++) {
            kingHits.insert({kingX + dx[i] * a, kingY + dy[i] * b});
            kingHits.insert({kingX + dx[i] * b, kingY + dy[i] * a});

            QueenHits.insert({queenX + dx[i] * a, queenY + dy[i] * b});
            QueenHits.insert({queenX + dx[i] * b, queenY + dy[i] * a});
        }

        int res = 0;
        for (auto position : kingHits)
            if (QueenHits.count(position))
                res++;

        cout << res << endl;
    }

    return 0;
}