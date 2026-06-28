#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    reverse(begin(s), end(s));

    if (s == t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}