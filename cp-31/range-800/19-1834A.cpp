#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int input;
        int pos = 0, neg = 0;
        for (int i = 0; i < n; i++) {
            cin >> input;
            if (input == 1)
                pos++;
            else
                neg++;
        }

        int ops = 0;
        while (pos < neg || neg % 2 == 1) {
            ops++;
            pos++;
            neg--;
        }

        cout << ops << endl;
    }

    return 0;
}