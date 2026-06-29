#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a, b;
    int maxi = 0;
    int curr = 0;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        curr += b - a;
        maxi = max(maxi, curr);
    }

    cout << maxi << endl;

    return 0;
}