class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        iterate(it, grid)
            iterate(i, it)
                if (i < 0)
                    count++;

        return count;
    }
};