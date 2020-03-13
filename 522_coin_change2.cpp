//  file:  522_coin_change2.cpp
//  author：lipcat
//  time：  2020-03-13 23:05


class Solution {
public:
    // 完全背包
    // dp[i][j]: 从coin[0 : i]中选择硬币，使amount=j，共有组合总数
    // dp[i][j] = dp[i - 1][j] + dp[i][j - coint[i]]
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1 , 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                if (dp[j - coins[i]] > 0) {
                    dp[j] += dp[j - coins[i]];
                }
            }
        }
        return dp.back();
    }
};
