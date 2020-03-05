//  file:  1103_distribute_candies_to_peoples.cpp
//  author：lipcat
//  time：  2020-03-05 23:32


class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        // 满足每个人分得的糖依次递增的情况下，最多可以分k次糖
        int k = sqrt(candies * 2 + 0.25) - 0.5;
        if ((k + 1) * (k + 2) / 2 == candies) {
            ++k;
        }
        // 满足每个人分得的糖依次递增的情况下，最多可以分完整的m躺
        int m = k / num_people;
        vector<int> ans(num_people, 0);
        // 先计算出所有人都能拿m次糖果时，每人拿到的糖果数
        for (int i = 0; i < num_people; ++i) {
            int ni = i + 1;
            ans[i] = ni * m + m * (m - 1) / 2 * num_people;
        }
        // 再依次递增分配剩余糖果
        int kk = m * num_people;
        int left = candies - kk * (kk + 1) / 2;
        for (int i = 0; left > 0 && i < num_people; ++i) {
            ans[i] += min(++kk, left);
            left -= kk;
        }
        return ans;
    }
};
