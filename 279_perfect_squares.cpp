//  file:  279_perfect_squares.cpp
//  author：lipcat
//  time：  2019-12-16 23:53


class Solution {
public:
    // solution:
    // dp[i] : the least number of perfect square numbers which sum to i
    // dp[i] = min(dp[i - k * k] + 1, dp[i]), k = 1, 2, 3 ...
    //
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= sqrt(i); ++k) {
                // 每次循环之所以用dp[i - k*k]而不是dp[i - k]是因为这样
                // 可以假设k = 2
                // dp[i] = dp[i - 2] + dp[2] = dp[i - 2] + dp[1] + 1 * 1 >= dp[i - 1] + 1 * 1
                // 因为dp[i - 1] 已经是一个最优解
                dp[i] = dp[i] == 0 ? 1 + dp[i - k * k] : min(dp[i], 1 + dp[i - k * k]);
            }
        }
        return dp.back();
    }
};
