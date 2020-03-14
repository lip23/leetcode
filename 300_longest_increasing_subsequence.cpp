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

class Solution {
public:
    // 构造数组lis，lis[i]表示当最长递增子序列长度为i+1时，最后一个元素可以取的最小值
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for (const auto& num : nums) {
            if (lis.empty() || lis.back() < num) {
                lis.push_back(num);
                continue;
            }
            int beg = 0, end = lis.size() - 1;
            while (beg < end) {
                int mid = beg + end >> 1;
                if (num < lis[mid]) {
                    end = mid - 1;
                } else if (num > lis[mid]){
                    beg = mid + 1;
                } {
                    break;
                }
            }
            // 当用[beg, end]（ 不是[beg,end) ）进行二分查处时，最后beg肯定会指向有效元素
            if (lis[beg] < num) {
                lis[beg + 1] = num;
            } else if (lis[beg] > num) {
                lis[beg] = num;
            }
        }

        return lis.size();
    }
};

class Solution {
public:
    // 构造数组lis，lis[i]表示当最长递增子序列长度为i+1时，最后一个元素可以取的最小值
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for (const auto& num : nums) {
            if (lis.empty() || lis.back() < num) {
                lis.push_back(num);
                continue;
            }
            int beg = 0, end = lis.size() - 1;
            while (beg < end) {
                int mid = beg + end >> 1;
                // 找第一个大于num的数, lis[mid] > num, 所以mid不应被舍弃
                if (num < lis[mid]) {
                    end = mid;
                } else if (num > lis[mid]){
                    beg = mid + 1;
                } else {
                    beg = mid;
                    break;
                }
            }
            lis[beg] = num;
        }

        return lis.size();
    }
};
