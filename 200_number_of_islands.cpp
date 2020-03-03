//  file:  200_number_of_islands.cpp
//  author：lipcat
//  time：  2020-03-03 16:50


class Solution {
public:
    // 每次搜索时将遍历过的节点置为0
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++cnt;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
    void dfs(const int i, const int j, vector<vector<char>>& grid) {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() && grid[i][j] == '1') {
            grid[i][j] = '0';
            dfs(i + 1, j, grid);
            dfs(i - 1, j, grid);
            dfs(i, j + 1, grid);
            dfs(i, j - 1, grid);
        }
    }
};
