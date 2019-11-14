//  file:  416_partition_equal_subset_sum.cpp
//  author：lipcat
//  time：  2019-11-14 22:55


class Solution {
public:
    // 解题思路：
    // subset，求所有可能的组合
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) {
            return false;
        }
        vector<int> ret(1, 0);
        set<int> sums;
        for (const auto num : nums) {
            int end = ret.size();
            for (int i = 0; i < end; ++i) {
                int tmp = num + ret[i];
                if (tmp == sum >> 1) {
                    return true;
                } else if (sums.find(tmp) == sums.end()) {
                    sums.insert(tmp);
                    ret.push_back(tmp);
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    // 解题思路：
    // 经典背包问题，动态规划
    // dp[i][j]:前i个元素中是否存在和为j的情况
    // dp[i][j] = dp[i][j - nums[i]]
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) {
            return false;
        }
        vector<bool> dp(sum / 2 + 1, false);
        dp[0] = true;
        for (const auto num : nums) {
            for (int i = dp.size() - 1; i >= 0; --i) {
                //cout << dp[i] << " ";
                if (dp[i] == false && i - num >=0 && dp[i - num] == true) {
                    dp[i] = true;
                }
            }
            cout <<endl;
        }
        return dp.back();
    }
};
