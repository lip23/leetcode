//  file:  1277_count_square_submatrices_with_all_ones.cpp
//  author：lipcat
//  time：  2019-12-04 00:04


class Solution {
public:
    // solution: dp
    // dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]))
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix);
        int ans = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] && i > 0 && j > 0) {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
