//  file:  151_reverse_word_in_a_string.cpp
//  author：lipcat
//  time：  2020-04-11 00:32

class Solution {
public:
    // 两次反正
    // 第一次反正整个字符串
    // 第二次按单词反转，注意反转时要包括前面的空格（把前面多余的空格反转到后面）
    // 最后还要处理末尾的空格
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int p = 0;
        while (p < s.length()) {
            int beg = p;
            while (beg < s.length() && s[beg] == ' ') {
                ++beg;
            }
            int end = beg;
            while (end < s.length() && s[end] != ' ') {
                ++end;
            }
            reverse(s.begin() + p, s.begin() + end);
            p += end - beg + 1;
        }
        p = s.length() - 1;
        while (p >= 0 && s[p] == ' ') {
            --p;
        }
        s.erase(p + 1);
        return s;
    }
};
