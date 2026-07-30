#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool flag = true;
    for (int i = 11; i <= 99; i += 11)
        if (i == n) {
            flag = false;
            break;
        }

    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}