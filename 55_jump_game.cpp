//  file:  55_jump_game.cpp
//  author：lipcat
//  time：  2019-11-09 00:41


class Solution {
public:
    // 解题思路：
    // 只需要维护一个能够进行jump的点的集合，并从最小的点开始进行jump来更新集合
    bool canJump(vector<int>& nums) {
        int beg = 0, end = 1;
        while (end < nums.size() && beg < end) {
            if (beg + nums[beg] >= end) {
                end = beg + nums[beg] + 1;
            }
            ++beg;
        }
        return end >= nums.size();
    }
};
