#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
bool generateSequence(vector<int> &sequence, vector<bool> &vis, int index, int n)
{
    if (index == sequence.size())
        return true;
    if (sequence[index] != 0)
        return generateSequence(sequence, vis, index + 1, n);

    for (int num = n; num >= 1; num--)
    {
        int nextIndex = (num == 1) ? index : index + num;
        if (vis[num] || (num > 1 && (nextIndex >= sequence.size() || sequence[nextIndex] != 0)))
            continue;

        sequence[index] = sequence[nextIndex] = num;
        vis[num] = true;

        if (generateSequence(sequence, vis, index + 1, n))
            return true;

        sequence[index] = sequence[nextIndex] = 0;
        vis[num] = false;
    }
    return false;
}
vector<int> constructDistancedSequence(int n)
{
    vector<int> sequence(2 * n - 1, 0);
    vector<bool> vis(n + 1, false);
    generateSequence(sequence, vis, 0, n);
    return sequence;
}
int main()
{
    vector<int> result = constructDistancedSequence(5);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}

/*
Problem:
*/