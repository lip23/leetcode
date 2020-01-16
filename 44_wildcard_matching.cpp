//  file:  44_wildcard_matching.cpp
//  author：lipcat
//  time：  2020-01-17 00:18


class Solution {
public:
    // solution
    // dp[i][j] : p[0:i] 是否匹配 s[0:j]
    // dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j]                      if p[i] == '*'
    //          = dp[i - 1][j - 1] && (p[i] == s[j] || p[i] = '?')      if p[i] != '*'
    bool isMatch(string s, string p) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int pi = 0; pi < p.length(); ++pi) {
            if (p[pi] == '*') {
                for (int i = 1; i <= s.length(); ++i) {
                    dp[i] = dp[i - 1] || dp[i];
                }
            } else {
                for (int i = s.length(); i > 0; --i) {
                    dp[i] = dp[i - 1] && (p[pi] == '?' || p[pi] == s[i - 1]);
                }
                dp[0] = false;
            }
        }
        return dp.back();
    }
};
