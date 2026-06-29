#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int input;
    bool flag = true;

    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input == 1) {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "easy" << endl;
    else
        cout << "hard" << endl;

    return 0;
}