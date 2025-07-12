#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &v, int low, int high)
{
    int pivot = v[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (v[i] <= pivot && i <= high)
            i++;
        while (v[j] > pivot && j >= low + 1)
            j--;
        if (i < j)
            swap(v[i], v[j]);
    }
    swap(v[low], v[j]);
    return j;
}
void quickSort(vector<int> &v, int low, int high)
{
    if (low >= high)
        return;
    int pInd = partition(v, low, high);
    quickSort(v, low, pInd - 1);
    quickSort(v, pInd + 1, high);
}
int main()
{
    int n = 6;
    vector<int> v = {2, 8, 3, 7, 1, 9};
    quickSort(v, 0, n - 1);
    for (auto i : v)
        cout << i << " ";
    return 0;
}

/*
Problem: QuickSort.
*/