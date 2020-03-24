//  file:  365_water_and_jup_problem.cpp
//  author：lipcat
//  time：  2020-03-24 23:16


class Solution {
public:
    // 因为只能用x和y来盛水，所以所有可能的容量都只能用x和y来度量
    // 可以理解为用一个水壶来盛水，用另一个水壶来倒水，剩下的就是得到的水量
    // 如果用一个水壶既盛水也倒水，最后等价于一种状态，只盛水或倒水
    // 所以问题可以用一个数学公式表示 ax + by
    bool canMeasureWater(int x, int y, int z) {
        if (x == 0 || y == 0) {
            return x == z || y == z;
        }
        if (x + y < z) {
            return false;
        }
        while (x % y) {
            int m = x % y;
            x = y;
            y = m;
        }
        return z % y == 0;
    }
};
