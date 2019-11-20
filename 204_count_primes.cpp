//  file:  204_count_primes.cpp
//  author：lipcat
//  time：  2019-11-20 07:34


class Solution {
public:
    // 解题思路：
    // 创建一个大小为n的集合nums，将集合中不是质数的元素都删除
    // 因为任何一个不是质数的数都可以分解成两个数的乘积（其中至少可以包含一个比其小的质数）
    // 所以可以从最小的质数（2）来依次将2*k的数删除
    // 从i=2开始继续递增处理，如果nums[i] == 0则表示该数不是质数，跳过
    // 如果nums[i] = 1，表示该数是质数，再将i*k的元素都删除
    int countPrimes(int n) {
        vector<int> nums(n, 1); // nums[i] = 1 表示i是质数
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                for (int j = i * 2; j < n; j += i) {
                    nums[j] = 0;
                }
            }
        }
        return n > 2 ? accumulate(nums.begin(), nums.end(), -2) : 0;
    }
};

class Solution {
public:
    // 解题思路：
    // 如果一个数不能被比他小的质数整除，则这个数也是一个质数
    // 创建一个大小为n的集合nums，将集合中不是质数的元素都删除
    // 因为任何一个不是质数的数都可以分解成两个数的乘积（其中至少可以包含一个比其小的质数）
    // 所以可以从最小的质数（2）来依次将2*k的数删除
    // 从i=2开始继续递增处理，如果nums[i] == 0则表示该数不是质数，跳过
    // 如果nums[i] = 1，表示该数是质数，再将i*k的元素都删除
    int countPrimes(int n) {
        vector<bool> nums(n, true);
        // 因为数num分解成多数相乘时，至少有一个数小于sqrt(n)
        // 又因为数num如果不是质数，则一定可以分解成多个质数相乘
        // 所以对于num>sqrt(n)的数，一定存在一个小于sqrt(n)的质因数
        // 所以用i < sqrt(n)已经可以计算出所有小于n的非质数
        for (int i = 2; i < sqrt(n); ++i) {
            if (nums[i] == 1) {
                for (int j = i * 2; j < n; j += i) {
                    nums[j] = false;
                }
            }
        }
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (nums[i]) {
                ++ans;
            }
        }
        return ans;
    }
};
