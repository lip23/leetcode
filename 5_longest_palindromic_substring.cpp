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
