#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    int input;

    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input > h)
            res += 2;
        else
            res += 1;
    }

    cout << res << endl;

    return 0;
}