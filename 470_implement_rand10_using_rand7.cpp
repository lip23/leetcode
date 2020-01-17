//  file:  470_implement_rand10_using_rand7.cpp
//  author：lipcat
//  time：  2020-01-17 21:48


// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    // solution
    // 两次rand7共有49种可能，(49 - 9) / 10 = 4, 将40种可能分为10组，则每组概率相同，可模拟rand10
    // 则调用两次rand7计算处rand10的概率是40/49,则rand7的期望调用次数是2*49/40 = 2.45次
    int rand10() {
        while (true) {
            int s1 = rand7();
            int s2 = rand7();
            if (s2 == 7 || (s1 == 7 && s2 > 4)) {
                continue;
            }
            if (s1 <= 2) {
                return s2 + 1 >> 1;
            } else if (s1 <= 4) {
                return s2 + 7 >> 1;
            } else if (s1 <= 6) {
                return s2 + 13 >> 1;
            } else {
                return 10;
            }
        }
        return 0;
    }
};
