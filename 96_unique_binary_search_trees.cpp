//  file:  96_unique_binary_search_trees.cpp
//  author：lipcat
//  time：  2020-03-02 19:03

class Solution {
public:
    // dp[n] = dp[i] * dp[n - 1 - i]    i = 0, 1, ... n - 1
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int k = 0; k < i; ++k) {
                dp[i] += dp[k] * dp[i - 1 - k];
            }
        }
        return dp.back();
    }
};
