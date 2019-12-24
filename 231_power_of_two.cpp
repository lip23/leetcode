//  file:  231_power_of_two.cpp
//  author：lipcat
//  time：  2019-12-24 22:59


class Solution {
public:
    // solution:
    // num为2的n次方，则其只会有一位bit为1
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        for (int i = 0 ;i < 31; ++i) {
            if (n & 1 << i) {
                ++cnt;
            }
        }
        return cnt == 1 && n > 0;
    }
};
