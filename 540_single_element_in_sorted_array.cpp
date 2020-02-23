//  file:  540_single_element_in_sorted_array.cpp
//  author：lipcat
//  time：  2020-02-23 10:23


class Solution {
public:
    // 每次查找将数组二等分，判断哪一部分包含单独元素，然后继续查找
    // 如何判断哪一部分包含单独元素：
    // 判断相等两元素中后一个元素的index i2，如果index是奇数，则表明[beg, i2]中没有重复元素,否则在[beg, i2 - 2]中有重复元素
    int singleNonDuplicate(vector<int>& nums) {
        int beg = 0;
        int end = nums.size() - 1;
        while (beg < end) {
            //cout << beg << " " << end << endl;
            int mid = beg + end >> 1;
            if (nums[mid] == nums[mid + 1]) {
                mid + 1 & 1 ? beg = mid + 2 : end = mid - 1;
            } else if (nums[mid] == nums[mid - 1]) {
                mid & 1 ? beg = mid + 1 : end = mid - 2;
            } else {
                return nums[mid];
            }
        }
        return nums[beg];
    }
};
