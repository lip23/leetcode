//  file:  1269_numbers_of_ways_to_stay_in_the_same_place_after_some_steps.cpp
//  author：lipcat
//  time：  2019-12-19 00:22

class Solution {
public:
    // solution:
    // dp[i][j] : 走i步到达index j处所有可能数
    // dp[i][j] = dp[i - 1][j] + dp[i - 1][j -1] + dp[i - 1][j + 1]
    int numWays(int steps, int arrLen) {
        int max_index = min(arrLen - 1, steps);
        vector<vector<long>> dp(steps + 1, vector<long>(max_index + 1, 0));
        dp[0][0] = 1;
        for (int step = 1; step <= steps; ++step) {
            for (int index = 0; index <= step && index < arrLen; ++index) {
                dp[step][index] = dp[step - 1][index];
                if (index > 0) {
                    dp[step][index] += dp[step - 1][index - 1];
                }
                if (index < max_index) {
                    dp[step][index] += dp[step - 1][index + 1];
                }
                dp[step][index] %= static_cast<int>(1e9 + 7);
            }
        }
        return dp[steps][0];
    }
};
