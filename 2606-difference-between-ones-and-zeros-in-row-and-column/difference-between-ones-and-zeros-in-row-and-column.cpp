class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> onesRow(m);
        vector<int> onesCol(n);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                onesRow[i] += (grid[i][j] == 1);
                onesCol[j] += (grid[i][j] == 1);
            }
        }

        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans[i][j] = onesRow[i] + onesCol[j] - (n - onesRow[i]) - (m - onesCol[j]);

        return ans;
    }
};