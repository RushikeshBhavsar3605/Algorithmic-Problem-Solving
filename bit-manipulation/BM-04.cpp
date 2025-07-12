#include <bits/stdc++.h>
using namespace std;
pair<int, int> get(int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;

    return {a, b};
}
int main()
{
    pair<int, int> result = get(13, 9);
    cout << result.first << " " << result.second << endl;
    return 0;
}

/*
Problem: Swap two numbers
*/