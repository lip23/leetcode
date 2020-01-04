//  file:  36_valid_sudoku.cpp
//  author：lipcat
//  time：  2020-01-04 16:08


class Solution {
public:
    // solution:
    // 分别记录每一行，每一列和每个box中各个数出现的次数
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9, 0);
        vector<int> col(9, 0);
        vector<int> box(9, 0);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                int bit = 1 << board[i][j] - '1';
                if ((row[i] & bit) || (col[j] & bit) || (box[i / 3 * 3 + j / 3] & bit)) {
                    return false;
                }
                row[i] |= bit;
                col[j] |= bit;
                box[i / 3 * 3 + j / 3] |= bit;
            }
        }
        return true;
    }
};
