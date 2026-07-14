#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        char input;
        int n, k;
        cin >> n >> k;

        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            cin >> input;
            if (!freq[input - 'a'])
                freq[input - 'a']++;
            else
                freq[input - 'a']--;
        }

        int sum = accumulate(begin(freq), end(freq), 0);
        sum -= k;

        if (sum <= 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}