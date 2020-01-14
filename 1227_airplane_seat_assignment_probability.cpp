//  file:  1227_airplane_seat_assignment_probability.cpp
//  author：lipcat
//  time：  2020-01-14 22:33


class Solution {
public:
    // solution
    // 刚开始从n开始分析，没有想清楚怎么解决，列举来很复杂的情况。后来从n=2，3，4开始分析，找到来如下规律
    // 第1个人做到每个位置的概率都是1/n，
    // 如果第1个人坐到第2个位置，则问题就变成来第2个人能否坐到第1个位置，即问题变成f(n-1),
    // 如果第1个人坐到第3个位置，则问题就变成来第3个人能否坐到第1个位置，即问题变成f(n-2),以此类推
    // f(1) = 1
    // f(2) = 1/2 * f(1)
    // f(n) = 1/n * (f(n - 1) + f(n - 2) + .. + f(1))
    double nthPersonGetsNthSeat(int n) {
        if (n == 1) {
            return 1.0;
        } else {
            return 0.5;
        }
    }
};
