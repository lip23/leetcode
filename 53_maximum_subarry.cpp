//  file:  53_maximum_subarry.cpp
//  author：lipcat
//  time：  2020-01-15 20:53


class Solution {
public:
    // solution
    // dp[i] : 包含num[i]的最大连续子数组
    // dp[i] = nums[i] + max(0, dp[i - 1])
    int maxSubArray(vector<int>& nums) {
        int ans = nums.front();
        int dp = nums.front();
        for (int i = 1; i < nums.size(); ++i) {
            dp > 0 ? dp += nums[i] : dp = nums[i];
            ans = max(ans, dp);
        }
        return ans;
    }
};
