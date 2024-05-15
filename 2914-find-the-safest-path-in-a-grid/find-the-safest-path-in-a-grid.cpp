#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool isValidCell(vector<vector<int>> &grid, int x, int y)
    {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid.size() && grid[x][y] == -1;
    }

    bool isValidSafeness(vector<vector<int>> &grid, int minSafeness)
    {
        int n = grid.size();
        if (grid[0][0] < minSafeness || grid[n - 1][n - 1] < minSafeness)
        {
            return false;
        }

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty())
        {
            auto current = q.front();
            q.pop();
            if (current.first == n - 1 && current.second == n - 1)
            {
                return true;
            }
            for (auto &d : dir)
            {
                int x = current.first + d[0];
                int y = current.second + d[1];
                if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && grid[x][y] >= minSafeness)
                {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }

        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
                else
                {
                    grid[i][j] = -1;
                }
            }
        }

        while (!q.empty())
        {
            int currentSize = q.size();
            while (currentSize-- > 0)
            {
                auto current = q.front();
                q.pop();
                for (auto &d : dir)
                {
                    int x = current.first + d[0];
                    int y = current.second + d[1];
                    if (isValidCell(grid, x, y))
                    {
                        grid[x][y] = grid[current.first][current.second] + 1;
                        q.push({x, y});
                    }
                }
            }
        }

        int low = 0;
        int high = 0;
        int result = -1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                high = max(high, grid[i][j]);
            }
        }

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isValidSafeness(grid, mid))
            {
                result = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return result;
    }
};

// int main()
// {
//     Solution s;
//     vector<vector<int>> grid = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
//     cout << s.maximumSafenessFactor(grid) << endl;
//     return 0;
// }