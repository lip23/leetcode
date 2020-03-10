//  file:  123_best_time_to_buy_and_sell_stock3.cpp
//  author：lipcat
//  time：  2020-03-10 17:06


class Solution {
public:
    // 找到一个时刻ti，将该问题分成两部分
    // 在[0, ti]时段进行依次操作，在[ti +1, tn]时段进行一次操作
    // 找到ti可能的取值位0～n，找到一个ti使两个时段的利润和最大
    // 求[0, ti]的最优解：可用T121中的方法，从0开始遍历到k，先记录下0-k中的历史最低点，
    //                  然后就可以得到k时刻卖出的最大利润，进而可以求的0-k时段中的最大利润
    // 求[ti + 1, n]的最优解：采用的方法于上述方法类似，从n开始遍历到k，先记录下k-n中的历史最高点，
    //                      然后可以得到k时刻买入的最大利润，进而可以求得n-k时段中的最大利润
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int ans = 0;
        // mp[i]: i~n时段中能获得的最大利润
        vector<int> mp(prices.size(), 0);
        int max_price = mp.back();
        for (int i = mp.size() - 1; i >= 0; --i) {
            max_price = max(prices[i], max_price);
            mp[i] = max(0, max_price - prices[i]);
            if (i + 1 < mp.size()) {
                mp[i] = max(mp[i], mp[i + 1]);
            }
        }
        int min_price = prices.front();
        for (int i = 0; i < mp.size(); ++i) {
            min_price = min(min_price, prices[i]);
            int cur_mp = max(0, prices[i] - min_price);
            if (i + 1 < mp.size()) {
                ans = max(ans, cur_mp + mp[i + 1]);
            } else {
                ans = max(ans, cur_mp);
            }
        }
        return ans;
    }
};
