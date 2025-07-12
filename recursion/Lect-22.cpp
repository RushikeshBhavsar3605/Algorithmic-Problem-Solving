#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> &v, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int cnt = 0;
    while (left <= mid && right <= high)
    {
        if (v[left] <= v[right])
            temp.push_back(v[left++]);
        else
        {
            temp.push_back(v[right++]);
            cnt += (mid - left + 1);
        }
    }
    while (left <= mid)
        temp.push_back(v[left++]);
    while (right <= high)
        temp.push_back(v[right++]);
    for (int i = low; i <= high; i++)
        v[i] = temp[i - low];
    return cnt;
}
int mergeSort(vector<int> &v, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = low + (high - low) / 2;
    cnt += mergeSort(v, low, mid);
    cnt += mergeSort(v, mid + 1, high);
    cnt += merge(v, low, mid, high);
    return cnt;
}
int numberOfInversions(vector<int> &v, int n)
{
    return mergeSort(v, 0, n - 1);
}
int main()
{
    vector<int> v = {5, 3, 2, 1, 4};
    cout << numberOfInversions(v, v.size()) << endl;
    return 0;
}

/*
Problem: Count Inversion.
*/