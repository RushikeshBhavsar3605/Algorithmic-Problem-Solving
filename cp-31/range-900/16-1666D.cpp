#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string s, t;
        cin >> s >> t;

        vector<int> freq(26, 0);
        for (auto it : t)
            freq[it - 'A']++;

        for (int i = s.size() - 1; i >= 0; i--)
            if (freq[s[i] - 'A'] > 0)
                freq[s[i] - 'A']--;
            else
                s[i] = '.';

        string finalString;
        for (int i = 0; i < s.size(); i++)
            if (s[i] != '.')
                finalString += s[i];

        if (finalString == t)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}