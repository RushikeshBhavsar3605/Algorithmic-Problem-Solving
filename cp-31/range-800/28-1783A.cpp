#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        sort(begin(v), end(v));
        int maxNum = v[n - 1];
        int minNum = v[0];

        if (maxNum != minNum) {
            cout << "YES" << endl;
            cout << maxNum << " ";
            for (int i = 0; i < n - 1; i++)
                cout << v[i] << " ";
            cout << endl;
        } else
            cout << "NO" << endl;
    }

    return 0;
}