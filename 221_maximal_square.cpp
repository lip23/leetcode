//  file:  221_maximal_square.cpp
//  author：lipcat
//  time：  2019-12-04 00:29

class Solution {
public:
    // solution: dp
    // dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]))
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return 0;
        }
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.front().size(), 0));
        int ans = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                } else if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};
