//  file:  1049_last_stone_weight2.cpp
//  author：lipcat
//  time：  2020-03-14 23:20


class Solution {
public:
    // 该问题可转换成将所有元素分成两组，让每组都最接近sum / 2
    // 当sum为奇数时，如sum=23，让其中一组最接近11，等价于让另一组更接近12
    // 综上，该问题可转换成0-1背包问题
    // dp[i][j]: 从nums[0: i]中选择元素，使sum <= j 时的最大解
    // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]) 约束： j - num[i] >= 0
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.cbegin(), stones.cend(), 0);
        vector<int> dp(sum / 2 + 1, 0);
        for (const auto& stone : stones) {
            for (int k = dp.size() -1; k >= 0 && k >= stone; --k) {
                dp[k] = max(dp[k], stone + dp[k - stone]);
            }
        }
        return sum - dp.back() * 2;
    }
};
