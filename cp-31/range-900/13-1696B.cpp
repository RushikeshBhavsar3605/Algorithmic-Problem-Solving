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

        int countZero = 0;
        for (int i = 0; i < n; i++)
            if (v[i] == 0)
                countZero++;

        int left = 0, right = n - 1;
        while (v[left++] == 0)
            ;
        while (v[right--] == 0)
            ;

        bool hasZero = 0;
        for (int i = left; i <= right; i++)
            if (v[i] == 0)
                hasZero = 1;

        if (countZero == n)
            cout << 0 << endl;
        else if (hasZero)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }

    return 0;
}