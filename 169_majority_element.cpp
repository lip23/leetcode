//  file:  169_majority_element.cpp
//  author：lipcat
//  time：  2019-11-12 09:31


class Solution {
public:
    // 解题思路：
    // 按位统计，因为对于每个bit，如果大于n/2，则肯定时众数的bit
    int majorityElement(vector<int>& nums) {
        vector<int> bits(32, 0);
        for (const auto num : nums) {
            for (int b = 0; b < 32; ++b) {
                if (num & (1 << b)) {
                    ++bits[b];
                }
            }
        }
        int m = nums.size() + 1 >> 1;
        int ret = 0;
        for (int b = 0; b < bits.size(); ++b) {
            if (bits[b] / m > 0) {
                ret |= (1 << b);
            }
        }
        return ret;
    }
};

class Solution {
public:
    // 解题思路：
    // http://www.cs.utexas.edu/~moore/best-ideas/
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for (const auto num : nums) {
            if (0 == count) {
                candidate = num;
                count = 1;
            } else {
                num == candidate ? ++count : --count;
            }
        }
        return candidate;
    }
};
