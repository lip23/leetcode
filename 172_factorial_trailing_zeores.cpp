//  file:  172_factorial_trailing_zeores.cpp
//  author：lipcat
//  time：  2019-11-15 00:49


class Solution {
public:
    // 解题思路：
    // 0的个数又5的个数决定
    int trailingZeroes(int n) {
        int ans = 0;
        while (n) {
            ans += n / 5;
            n /= 5;
        }
        return ans;
    }
};
