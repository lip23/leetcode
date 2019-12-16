//  file:  322_coin_change.cpp
//  author：lipcat
//  time：  2019-12-16 23:05


class Solution {
public:
    // solution:
    // dp[i] : 兑换i元所需要的最少硬币
    // dp[i] = min(dp[i - k]) + 1   k = 1, 2, 5
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 0; i <= amount; ++i) {
            for (const auto c : coins) {
                if (i - c >= 0 && dp[i - c] >= 0) {
                    dp[i] = dp[i] == -1 ? 1 + dp[i - c] : min(dp[i], 1 + dp[i - c]);
                }
            }
        }
        return dp.back();
    }
};
