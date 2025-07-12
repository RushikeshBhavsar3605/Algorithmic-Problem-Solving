#include <bits/stdc++.h>
using namespace std;
void reverse(int ind, vector<int> &v, int n)
{
    if (ind == n / 2)
        return;
    swap(v[ind], v[n - ind - 1]);
    reverse(ind + 1, v, n);
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    reverse(0, v, v.size());
    for (auto i : v)
        cout << i << " ";
    return 0;
}

/*
Problem: Reverse an array.
*/