//  file:  240_search_a_2d_matrix2.cpp
//  author：lipcat
//  time：  2020-02-12 23:56


class Solution {
public:
    // 二分查找，缩小范围
    // 在left_up, right_donw二维区域查找，每次找出该区域中心的元素cv(center_value)
    // target和cv比较，每次可以排除掉1/4的区域，剩下4/3的区域可以分成两个小区域递归查找
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.front().empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix.front().size();
        return FindMatrix(matrix, 0, 0, m - 1, n - 1, target);
    }
    // lu: left_up,   rd: right_down
    bool FindMatrix(const vector<vector<int>>& mat, const int lu_x, const int lu_y,
                    const int rd_x, const int rd_y, const int target) {
        if (lu_x > rd_x || lu_y > rd_y) {
            return false;
        }
        int mx = lu_x + rd_x >> 1;
        int my = lu_y + rd_y >> 1;
        if (target == mat[mx][my]) {
            return true;
        } else if (target < mat[mx][my]) {
            return FindMatrix(mat, lu_x, lu_y, mx - 1, rd_y, target) ||
                FindMatrix(mat, mx, lu_y, rd_x, my - 1, target);
        } else {
            return FindMatrix(mat, lu_x, my + 1, rd_x, rd_y, target) ||
                FindMatrix(mat, mx + 1, lu_y, rd_x, my, target);
        }
    }
};
