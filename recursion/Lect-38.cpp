#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
bool isSafe(int node, vector<vector<int>> &graph, vector<int> &color, int v, int col)
{
    for (int i = 0; i < v; i++)
        if (i != node && graph[i][node] == 1 && color[i] == col)
            return false;
    return true;
}
bool solve(int node, vector<vector<int>> &graph, vector<int> &color, int v, int m)
{
    if (node == v)
        return true;
    for (int col = 1; col <= m; col++)
    {
        if (isSafe(node, graph, color, v, col))
        {
            color[node] = col;
            if (solve(node + 1, graph, color, v, m))
                return true;
            color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(int v, vector<pair<int, int>> &edges, int m)
{
    vector<vector<int>> graph(v, vector<int>(v, 0));
    for (auto it : edges)
        graph[it.first][it.second] = graph[it.second][it.first] = 1;
    vector<int> color(v, 0);
    if (solve(0, graph, color, v, m))
        return true;
    return false;
}
int main()
{
    vector<pair<int, int>> edges = {{0, 1}, {0, 0}};
    cout << graphColoring(2, edges, 1) << endl;
    return 0;
}

/*
Problem: M-Coloring Problem
*/