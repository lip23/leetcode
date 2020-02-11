//  file:  153_find_min_in_rotated_sorted_array.cpp
//  author：lipcat
//  time：  2020-02-11 13:21


class Solution {
public:
    // 对于旋转的有序数组，每次去中间节点，肯定会把数组分层有序和无序两段
    int findMin(vector<int>& nums) {
        int beg = 0;
        int end = nums.size() - 1;
        int ans = INT_MAX;
        while (beg < end) {
            int mid = beg + end >> 1;
            if (nums[beg] <= nums[mid]) {
                ans = min(ans, nums[beg]);
                beg = mid + 1;
            } else {
                ans = min(ans, nums[mid + 1]);
                end = mid;
            }
        }
        return min(ans, nums[beg]);
    }
};
