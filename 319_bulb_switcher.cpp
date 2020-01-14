//  file:  319_bulb_switcher.cpp
//  author：lipcat
//  time：  2020-01-14 23:03


class Solution {
public:
    // solution:
    // 第i个位置最后的状态是由i被操作的次数决定，如果i被操作奇数则i最后为打开，为偶数则为关闭
    // i被操作的次数即i含有的约数的个数。
    // 一个数num含有的约数是两个小于等于sqrt(num)的数相乘，所以如果num不是某个数的平方，则num含有偶数个约数
    // 否则含有奇数个约数。
    // 1～n中包含的完全平方数的个数是sqrt(num)
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
