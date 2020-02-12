//  file:  74_search_a_2d_matrix.cpp
//  author：lipcat
//  time：  2020-02-12 15:39


class Solution {
public:
    // solution
    // 将二维数组当作一维数组处理, index ---> r = index / n, c = index % n
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.front().empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix.front().size();
        int beg = 0;
        int end = m * n - 1;
        while (beg < end) {
            int mid = beg + end >> 1;
            if (target < matrix[mid / n][mid % n]) {
                end = mid - 1;
            } else if (target > matrix[mid / n][mid % n]){
                beg = mid + 1;
            } else {
                return true;
            }
        }
        return beg == end && matrix[beg / n][beg % n] == target;
    }
};
