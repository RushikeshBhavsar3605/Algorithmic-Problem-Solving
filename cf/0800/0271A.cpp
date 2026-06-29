#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    auto isValid = [&](int year) {
        vector<int> used(10, 0);
        while (year) {
            if (used[year % 10])
                return false;

            used[year % 10] = 1;
            year /= 10;
        }

        return true;
    };

    for (int i = n + 1; i <= 9012; i++)
        if (isValid(i)) {
            cout << i << endl;
            return 0;
        }

    return 0;
}