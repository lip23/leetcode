//  file:  453_minimum_moves_to_equal_array_elements.cpp
//  author：lipcat
//  time：  2019-11-13 23:12


class Solution {
public:
    // 解题思路：
    // 题目等价每次将一个元素减一
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int min_num = nums.empty() ? 0 : nums.front();
        for (const auto num : nums) {
            min_num = min(num ,min_num);
        }
        for (const auto num : nums) {
            ans += num - min_num;
        }
        return ans;
    }
};
