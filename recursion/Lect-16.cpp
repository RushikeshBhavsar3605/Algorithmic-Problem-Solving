#include <bits/stdc++.h>
using namespace std;
bool isSafe(int node, vector<int> &color, vector<vector<int>> &graph, int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && graph[k][node] == 1 && color[k] == col)
            return false;
    }
    return true;
}
bool solve(int node, vector<int> &color, int m, int n, vector<vector<int>> &graph)
{
    if (node == n)
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, graph, n, i))
        {
            color[node] = i;
            if (solve(node + 1, color, m, n, graph))
                return true;
            color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(vector<vector<int>> &graph, int m, int n)
{
    vector<int> color(n, 0);
    if (solve(0, color, m, n, graph))
        return true;
    return false;
}
int main()
{
    int n = 4, m = 3, e = 5;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    graph[0][1] = 1, graph[1][0] = 1;
    graph[1][2] = 1, graph[2][1] = 1;
    graph[2][3] = 1, graph[3][2] = 1;
    graph[3][0] = 1, graph[0][3] = 1;
    graph[0][2] = 1, graph[2][0] = 1;
    cout << graphColoring(graph, m, n);
    return 0;
}

/*
Problem: M-Coloring Graph.
*/