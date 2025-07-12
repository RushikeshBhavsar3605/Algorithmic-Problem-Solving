#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
void solve(int index, vector<int> &arr, int &sum, vector<int> &result)
{
    if (index == arr.size())
    {
        result.push_back(sum);
        return;
    }
    sum += arr[index];
    solve(index + 1, arr, sum, result);
    sum -= arr[index];
    solve(index + 1, arr, sum, result);
}
vector<int> subsetSums(vector<int> &arr)
{
    vector<int> result;
    int sum = 0;
    solve(0, arr, sum, result);
    return result;
}
int main()
{
    vi v = {5, 6, 7};
    vi curr;
    vi result = subsetSums(v);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}

/*
Problem:
4  3  2  1

12 12 12 12
/   /  /  /
4   3  2  1
|   |  |  |
3   4  6  12
/   /  /  /
2   2  2  2
|   |  |  |
1   2  3  6
*/