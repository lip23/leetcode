//  file:  14_longest_common_prefix.cpp
//  author：lipcat
//  time：  2020-01-09 00:13


class Solution {
public:
    // 先判断多有str的第一个字符是否相同，
    // 若相同则继续判断下一个字符，若不同则最大前缀可以确定
    string longestCommonPrefix(vector<string>& strs) {
        int ind = 0;
        while (!strs.empty()) {
            for (int i = 0; i < strs.size(); ++i) {
                if (ind < strs[i].length() && (i == 0 || strs[i][ind] == strs[i - 1][ind])) {
                    continue;
                }
                return strs.front().substr(0, ind);
            }
            ++ind;
        }
        return strs.empty() ? "" : strs.front().substr(0, ind);
    }
};
