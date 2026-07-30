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

        priority_queue<pair<int, int>, vector<pair<int, int>>> maxHeap;
        for (int i = 1; i < n - 1; i++)
            if (v[i - 1] > v[i] && v[i] < v[i + 1])
                maxHeap.push({v[i], i});

        while (!maxHeap.empty()) {
            auto [ele, idx] = maxHeap.top();
            maxHeap.pop();

            v[idx - 1] = v[idx + 1] = ele;
        }

        int sum = 0;
        for (auto it : v)
            sum += it;

        cout << sum << endl;
    }

    return 0;
}