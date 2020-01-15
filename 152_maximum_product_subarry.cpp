//  file:  152_maximum_product_subarry.cpp
//  author：lipcat
//  time：  2020-01-15 21:12


class Solution {
public:
    // solution
    // dp[i].max 以num[i]为结尾的最大子数组乘积
    // dp[i].min 以num[i]为结尾的最小子数组乘积
    // dp[i].max = max(nums[i], num[i] * dp[i- 1].max, num[i] * dp[i-1].min)
    // dp[i].min = min(nums[i], num[i] * dp[i- 1].max, num[i] * dp[i-1].min)
    int maxProduct(vector<int>& nums) {
        int dp_max = nums.front();
        int dp_min = nums.front();
        int ans = nums.front();
        for (int i = 1; i < nums.size(); ++i) {
            int n1 = dp_max * nums[i];
            int n2 = dp_min * nums[i];
            dp_max = max(nums[i], max(n1 ,n2));
            dp_min = min(nums[i], min(n1, n2));
            ans = max(ans, dp_max);
        }
        return ans;
    }
};
