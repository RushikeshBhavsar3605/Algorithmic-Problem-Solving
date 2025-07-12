#include <bits/stdc++.h>
using namespace std;
int countStudents(vector<int> &arr, int pages)
{
    int n = arr.size();
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages)
            pagesStudent += arr[i];
        else
        {
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}
int allocateBooks(vector<int> &arr, int m)
{
    int n = arr.size();
    if (m > n)
        return -1;
    int maxi = *max_element(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int low = maxi, high = sum;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int students = countStudents(arr, mid);
        if (students > m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int main()
{
    vector<int> v = {12, 34, 67, 90};
    cout << allocateBooks(v, 2) << endl;
    return 0;
}

/*
Problem: Allocate Books.
*/