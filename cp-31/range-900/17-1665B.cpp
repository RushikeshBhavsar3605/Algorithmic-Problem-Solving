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

        map<int, int> mp;
        for (auto it : v)
            mp[it]++;

        int maxFreq = 0;
        for (auto it : mp)
            maxFreq = max(maxFreq, it.second);

        int rem = n - maxFreq;

        int ops = 0;
        while (rem > 0) {
            int add = min(rem, maxFreq);
            ops += 1 + add;
            maxFreq += add;
            rem -= add;
        }

        cout << ops << endl;
    }

    return 0;
}