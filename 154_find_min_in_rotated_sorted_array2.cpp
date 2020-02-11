//  file:  154_find_min_in_rotated_sorted_array2.cpp
//  author：lipcat
//  time：  2020-02-11 18:53


class Solution {
public:
    // 对于 rotated sorted array, 每次二分都可以把当前数组划分成左右两个子数组
    // 若子数组满足nums[beg] < nums[end], 则该子数组是有序的，可以直接求最小元素，也可以直接判断给定target是否在该子数组中
    // 若array中不包含重复元素, 则每次划分至少必有一个数组可断定有序, 故每次二分可将数据规模缩小一半, 故O(n)=logn
    // 若array中包含重复元素，则每次划分可能会出现无法判断那个子数组是有序的情况，这时候两个子数组都要求解, 故最坏情况下O(n)=n
    int findMin(vector<int>& nums) {
        return FindMin(0, nums.size() - 1, nums);
    }
    int FindMin(const int beg, const int end, const vector<int>& nums) {
        if (end - beg <= 1) {
            return min(nums[beg], nums[end]);
        }
        int mid = beg + end >> 1;
        int lmin = nums[beg] < nums[mid] ? nums[beg] : FindMin(beg, mid, nums);
        int rmin = nums[mid + 1] < nums[end] ? nums[mid + 1] : FindMin(mid + 1, end, nums);
        return min(lmin, rmin);
    }
};
