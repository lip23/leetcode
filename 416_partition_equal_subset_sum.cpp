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
