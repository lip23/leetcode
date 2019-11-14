//  file:  233_number_of_digit_one.cpp
//  author：lipcat
//  time：  2019-11-15 00:36


class Solution {
public:
    // 解题思路：
    // 每10   个数里有1个   个位1, 不足10  个数的尾数(num % 10),   count(1) = min(1, (num % 10) - 1 + 1)
    // 每100  个数里有10个  十位1, 不足100 个数的尾数(num % 100),  count(1) = min(10, (num % 100) - 10 + 1)
    // 每1000 个数里有100个 百位1, 不足1000个数的尾数(num % 1000), count(1) = min(100, (num % 10) - 100 + 1)
    int countDigitOne(int n) {
        int ans = 0;
        long base = 1;
        while (base <= n) {
            ans += n / (base * 10) * base;
            int mod = n % (base * 10);
            if (mod >= base) {
                ans += min(mod - base + 1 , base);
            }
            base *= 10;
        }
        return ans;
    }
};
