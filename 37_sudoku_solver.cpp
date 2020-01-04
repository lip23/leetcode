//  file:  37_sudoku_solver.cpp
//  author：lipcat
//  time：  2020-01-05 00:05


class Solution {
public:
    // solution
    // dfs, 依次填入每个空白位置
    void solveSudoku(vector<vector<char>>& board) {
        dfs(0, board);
    }
    bool dfs(int ind, vector<vector<char>>& board) {
        //cout << "ind= " << ind << endl;
        while( ind < 81 && board[ind / 9][ind % 9] != '.') {
            ++ind;
        }
        if (ind == 81) {
            return true;
        }
        int r = ind / 9;
        int c = ind % 9;
        for (int num = 1; num <= 9; ++num) {
            bool valid = true;
            for (int i = 0; i < 9; ++i) {
                if (board[r][i] - '0' == num || board[i][c] - '0' == num ||
                    board[r / 3 * 3 + i / 3][c / 3 * 3 + i % 3] - '0' == num) {
                    valid = false;
                    break;
                }
            }
            board[r][c] = '0' + num;
            if (valid && dfs(ind + 1, board)) {
                return true;
            }
        }
        board[r][c] = '.';
        return false;
    }
};
