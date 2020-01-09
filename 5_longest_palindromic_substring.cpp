//  file:  5_longest_palindromic_substring.cpp
//  author：lipcat
//  time：  2020-01-08 23:55


class Solution {
public:
    // solution
    // 依次判断s[i:j]是否回文
    string longestPalindrome(string s) {
        string ans;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = s.length() - 1; j >= i && j - i + 1 > ans.length(); --j) {
                int beg = i;
                int end = j;
                while (beg < end && s[beg] == s[end]) {
                    ++beg;
                    --end;
                }
                if (beg >= end) {
                    ans = s.substr(i, j - i + 1);
                    break;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    // solution
    // dp  O(n*n)
    // dp[i][j] 表示 s[i:j]是否回文
    // dp[i][j] = 1     if (s[i] == s[j] && dp[i + 1][j - 1] && j - i > 1)
    //          = 0     else
    string longestPalindrome(string s) {
        string ans;
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        for (int l = 1; l <= s.length(); ++l) {
            for (int i = 0; i <= s.length() - l; ++i) {
                int j = i + l - 1;
                if (s[i] == s[j] && (l <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = 1;
                    if (l > ans.length()) {
                        ans = s.substr(i, l);
                    }
                }
            }
        }
        return ans;
    }
};
