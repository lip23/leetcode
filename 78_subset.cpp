//  file:  78_subset.cpp
//  author：lipcat
//  time：  2019-11-09 09:18


class Solution {
public:
    // 解题思路：
    // 利用子问题的思想，先求前k-1个数构成的subset(ss[k-1])，然后前k个数构成的subset(ss[k])求解公式如下：
    // ss[k] = ss[k - 1] 并 {ss[k - 1][i] 并 nums[k]}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret (1);
        for (const auto num : nums) {
            int k = ret.size();
            for (int i = 0; i < k; ++i) {
                auto tmp = ret[i];
                tmp.push_back(num);
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};
