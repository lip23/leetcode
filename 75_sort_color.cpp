//  file:  75_sort_color.cpp
//  author：lipcat
//  time：  2020-04-08 12:47


class Solution {
public:
    // 顺序遍历数组，
    // 如果是0的话，则插入到左边第一个不是0的位置
    // 如果是2的话，则插入到右边第一个不是2的位置
    void sortColors(vector<int>& nums) {
        int l = 0;  // l指向0插入的位置
        int r = nums.size() - 1;  // r指向1插入的位置
        for (int i = l; i <= r;) {
            if (0 == nums[i]) {
                if (l == i) {
                    ++i;
                } else {
                    swap(nums[l], nums[i]);
                }
                ++l;
            } else if (2 == nums[i]) {
                if (r == i) {
                    ++i;
                } else {
                    swap(nums[r], nums[i]);
                }
                --r;
            } else {
                ++i;
            }
        }
    }
};
