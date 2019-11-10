//  file:  46_permutations.cpp
//  author：lipcat
//  time：  2019-11-10 09:13


class Solution {
public:
    // 解题思路：
    // 从第一个位置开始，先选择当前位置可能放置的数，再继续选择下一位置
    // 在选择每一位置的可能放置的数时应该考虑到所以情况
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        perm(0, nums, &ret);
        return ret;
    }

    // cur: 当前待排列位置的下标
    void perm(const int cur, vector<int>& nums, vector<vector<int>> * ret) {
        if (cur + 1 >= nums.size()) {
            ret->push_back(nums);
            return;
        }
        for (int i = cur ; i < nums.size(); ++i) {
            swap(nums[i], nums[cur]);
            perm(cur + 1, nums, ret);
            swap(nums[i], nums[cur]);
        }
    }
};
