//  file:  47_permutions2.cpp
//  author：lipcat
//  time：  2019-11-10 09:44


class Solution {
public:
    // 解题思路：在不包含重复元素排列的解法基础上增加一个集合
    //         在选择当前位置要放置的数时，要看该数是否已经被放置过
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        perm(0, nums, &ret);
        return ret;
    }
    void perm(const int cur, vector<int>& nums, vector<vector<int>>* ret) {
        if (cur + 1 >= nums.size()) {
            ret->push_back(nums);
            return;
        }
        set<int> s;
        for (int i = cur; i < nums.size(); ++i) {
            if (s.find(nums[i]) != s.end()) {
                continue;
            }
            s.insert(nums[i]);
            swap(nums[cur], nums[i]);
            perm(cur + 1, nums, ret);
            swap(nums[cur], nums[i]);
        }
    }
};
