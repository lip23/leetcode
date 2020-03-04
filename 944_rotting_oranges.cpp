//  file:  944_rotting_oranges.cpp
//  author：lipcat
//  time：  2020-03-04 09:33


class Solution {
public:
    // 每个被腐烂的橘子都标记上其被腐烂的时间，初始为2，依腐烂时间递增
    // 从一个初始为腐烂的橘子开始计算周边橘子被腐烂的时间时，如果某个新鲜橘子被腐烂的时间小于被其它橘子腐烂的时间则更新时间
    // 否则不继续搜索
    int orangesRotting(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 2) {
                    dfs(i, j, 1, grid);
                }
            }
        }
        int ans = 0;
        for (const auto& row : grid) {
            for (const auto& ora : row) {
                if (ora == 1) {
                    return - 1;
                }
                if (ora - 2 > ans) {
                    ans = ora - 2;
                }
            }
        }
        return ans;
    }
    void dfs(const int i, const int j, int time, vector<vector<int>>& grid) {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() &&
            (grid[i][j] == 1 || grid[i][j] > time)) {
            grid[i][j] = ++time;
            dfs(i + 1, j, time, grid);
            dfs(i - 1, j, time, grid);
            dfs(i, j + 1, time, grid);
            dfs(i, j - 1, time, grid);
        }
    }
};
