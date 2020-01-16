//  file:  62_unique_paths.cpp
//  author：lipcat
//  time：  2020-01-16 23:02


class Solution {
public:
    // solution
    // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                dp[c] += dp[c - 1];
            }
        }
        return dp.back();
    }
};
