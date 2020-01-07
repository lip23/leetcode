//  file:  72_edit_distance.cpp
//  author：lipcat
//  time：  2020-01-08 00:15


class Solution {
public:
    // dp[i][j]: word1[0 : i - 1]  --> word2[0 : j - 1]的最小距离
    // dp[i][j] = dp[i - 1][j - 1]    if  word[i] == word[j]
    //            1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1])
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
        for (int i = 0; i <= word1.length(); ++i) {
            for (int j = 0; j <= word2.length(); ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = i + j;
                } else {
                    if (word1[i - 1] == word2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    }
                }
            }
        }
        return dp.back().back();
    }
};
