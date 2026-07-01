#include <bits/stdc++.h>
using namespace std;

bool check(string &s, string &x) {
    int n = s.size();
    int m = x.size();
    vector<int> lps(n);

    int pre = 0;
    for (int suf = 1; suf < n; suf++) {
        while (pre > 0 && s[pre] != s[suf])
            pre = lps[pre - 1];

        if (s[pre] == s[suf])
            pre++;

        lps[suf] = pre;
    }

    pre = 0;
    for (int suf = 0; suf < m; suf++) {
        while (pre > 0 && s[pre] != x[suf])
            pre = lps[pre - 1];

        if (s[pre] == x[suf])
            pre++;

        if (pre == n)
            return true;
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string x, s;
        cin >> x >> s;

        int res = -1;
        for (int i = 0; i <= 5; i++) {
            if (check(s, x)) {
                res = i;
                break;
            }

            x += x;
        }

        cout << res << endl;
    }

    return 0;
}