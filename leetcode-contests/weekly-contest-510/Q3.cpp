#include "template.hpp"

void print(vector<string> &s) {
    iterate(it, s) cout << it << endl;

    cout << endl;
}

/* Approach (Memoization): */
class Solution {
  private:
    int rows, cols, targetWays;

    bool isEndpoint(int r, int c) {
        return (r == 0 && c == 0) || (r == rows - 1 && c == cols - 1);
    }

    void updateDP(int r, int c, vvi &memo) {
        if (r == 0 && c == 0)
            return;

        int left = c > 0 ? memo[r][c - 1] : 0;
        int top = r > 0 ? memo[r - 1][c] : 0;

        memo[r][c] = left + top;
    }

    bool dfs(int r, int c, vector<string> &grid, vvi &memo) {
        if (c == cols)
            r = r + 1, c = 0;

        if (r == rows)
            return memo[rows - 1][cols - 1] == targetWays;

        grid[r][c] = '.';
        updateDP(r, c, memo);

        if (memo[r][c] <= targetWays && dfs(r, c + 1, grid, memo))
            return true;

        if (!isEndpoint(r, c)) {
            grid[r][c] = '#';
            memo[r][c] = 0;
            if (dfs(r, c + 1, grid, memo))
                return true;
        }

        return false;
    }

  public:
    vector<string> createGrid(int m, int n, int k) {
        rows = m;
        cols = n;
        targetWays = k;

        vector<string> grid(m, string(n, '.'));
        vvi memo(m, vi(n, 0));

        memo[0][0] = 1;

        return dfs(0, 0, grid, memo) ? grid : vector<string>{};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.createGrid(2, 3, 2);
    print(res);
    cout << endl;
    res = obj.createGrid(3, 3, 4);
    print(res);
    cout << endl;
    res = obj.createGrid(1, 4, 2);
    print(res);
    return 0;
}

/*
Problem: Create Grid With Exactly K Paths I
*/