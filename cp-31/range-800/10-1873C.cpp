#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n = 10;
        char input;

        vector<int> horizontalScore({1, 2, 3, 4, 5, 5, 4, 3, 2, 1});
        vector<int> verticalScore({1, 2, 3, 4, 5, 5, 4, 3, 2, 1});

        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> input;
                if (input == 'X')
                    res += min(verticalScore[i], horizontalScore[j]);
            }

        cout << res << endl;
    }

    return 0;
}