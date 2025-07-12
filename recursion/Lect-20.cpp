#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &v, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (v[left] <= v[right])
            temp.push_back(v[left++]);
        else
            temp.push_back(v[right++]);
    }
    while (left <= mid)
        temp.push_back(v[left++]);
    while (right <= high)
        temp.push_back(v[right++]);
    for (int i = low; i <= high; i++)
        v[i] = temp[i - low];
}
void mergeSort(vector<int> &v, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
}
int main()
{
    int n = 6;
    vector<int> v = {2, 7, 3, 8, 1, 9};
    mergeSort(v, 0, n - 1);
    for (auto i : v)
        cout << i << " ";
    return 0;
}

/*
Problem: MergeSort.
*/