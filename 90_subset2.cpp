//  file:  90_subset2.cpp
//  author：lipcat
//  time：  2019-11-09 23:40


class Solution {
public:
    // 解题思路：
    // 先考虑不包含重复元素时的解题方法，即通过子问题的方法，先求出前k-1个元素能组成的所以subset，
    // 然后包含前k个元素组成的subset就包括两部分，即包含第k个元素(前k-1个元素组成的subset都加上第k个元素)和
    // 不包含第k个元素(前k-1个元素组成的subset)，抽象为数学公式就是subset[k] = subset[k - 1] * {{}, {nums[k]}}
    // 对于包含重复元素的情况，需要将重复元素作为一个小集合统一处理，因为重复元素能够组成的subset比非重复元素要少
    // subset[k] = subset[k - 1] * {重复元素组成的subset}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret(1);
        int i = 0;
        while (i < nums.size()) {
            int end = i;
            while (++end < nums.size() && nums[end] == nums[i]);
            int n = ret.size();
            for (int j = 0; j < n; ++j) {
                auto tmp = ret[j];
                for (int k = i; k < end; ++k) {
                    tmp.push_back(nums[k]);
                    ret.emplace_back(tmp);
                }
            }
            i = end;
        }
        return ret;
    }
};
