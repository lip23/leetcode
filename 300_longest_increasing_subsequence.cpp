//  file:  300_longest_increasing_subsequence.cpp
//  author：lipcat
//  time：  2020-03-14 21:45

class Solution {
public:
    // dp[i]: 从nums[0 : i]中选择元素，以nums[i]为最后一个元素，构成LIS时的子序列长度
    // dp[i] = max(1 + dp[i - k])   要求： nums[i - k] < nums[i]
    int lengthOfLIS(vector<int>& nums) {
        int ans = nums.empty() ? 0 : 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i] && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
