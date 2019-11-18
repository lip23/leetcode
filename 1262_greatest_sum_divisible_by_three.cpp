//  file:  1262_greatest_sum_divisible_by_three.cpp
//  author：lipcat
//  time：  2019-11-19 00:18


class Solution {
public:
// 解题思路：
// 数组和sum % 3可能等于0,1,2
// 如果sum % 3 = 1，则nums中可能存在一个数num1 % 3 =1，
// 也可能存在两个数num2 % 3 =2, num3 % 3 = 2, num2 + num3 % 3 =1

// 如果sum % 3 = 2，则nums中可能存在一个数num1 % 3 =2，
// 也可能存在两个数num2 % 3 =1, num3 % 3 = 1, num2 + num3 % 3 =2
    int maxSumDivThree(vector<int>& nums) {
        int min_mod1_1 = 10000, min_mod1_2 = 10000;
        int min_mod2_1 = 10000, min_mod2_2 = 10000;
        int sum = 0;
        for (const auto num: nums) {
            sum += num;
            if (num % 3 == 1 && (num < min_mod1_1 || num < min_mod1_2)) {
                min_mod1_2 = min(min_mod1_1, min_mod1_2);
                min_mod1_1 = num;
            } else if (num % 3 == 2 && (num < min_mod2_1 || num < min_mod2_2)) {
                min_mod2_2 = min(min_mod2_1, min_mod2_2);
                min_mod2_1 = num;
            }
        }
        if (sum % 3 == 1) {
            sum -= min(min(min_mod1_1, min_mod1_2), min_mod2_1 + min_mod2_2);
        } else if (sum % 3 == 2) {
            sum -= min(min(min_mod2_1, min_mod2_2), min_mod1_1 + min_mod1_2);
        }
        return sum;
    }
};
