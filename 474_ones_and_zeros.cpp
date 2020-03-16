//  file:  474_ones_and_zeros.cpp
//  author：lipcat
//  time：  2020-03-16 21:53


class Solution {
public:
    // 两个约束条件的0-1背包
    // dp[k][i][j]：当两个背包容量为i和j，在nums[0:k]中选择元素，背包所能装下的最多元素
    // dp[k][i][j] = max(dp[k - 1][i][j], 1 + dp[k - 1][i - nums[k].first][j - nums[k].second])  当 i - nums[k].first >= 0 j - nums[k].second >= 0
    // 该地推公式的实质是判断取nums[k]还是不取nums[k]是最优解
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const auto& str : strs) {
            int cnt0 = count(str.begin(), str.end(), '0');
            int cnt1 = str.length() - cnt0;
            for (int i = m; i >= cnt0; --i) {
                for (int j = n; j >= cnt1; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - cnt0][j - cnt1]);
                }
            }
        }
        return dp.back().back();
    }
};
