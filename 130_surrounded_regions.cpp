//  file:  130_surrounded_regions.cpp
//  author：lipcat
//  time：  2020-03-03 16:41


class Solution {
public:
    // 从4个边上值为‘O'的点开始搜索，将能搜索到的’O‘点都置为’X‘，则最后的结果中值为’O‘的点都是被包围的点
    void solve(vector<vector<char>>& board) {
        vector<vector<char>> bod(board);
        for (int i = 0; i < bod.size(); ++i) {
            for (int j = 0; j < bod[i].size(); ++j) {
                if (i == 0 || i == bod.size() - 1 || j == 0 || j == bod[i].size() - 1) {
                    dfs(i, j, bod);
                }
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'O' && board[i][j] == bod[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs(int i, int j, vector<vector<char>>& board) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] == 'X') {
            return;
        }
        board[i][j] = 'X';
        dfs(i + 1, j, board);
        dfs(i - 1, j, board);
        dfs(i, j + 1, board);
        dfs(i, j - 1, board);
    }
};
