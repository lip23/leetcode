//  file:  316_remove_duplicate_letters.cpp
//  author：lipcat
//  time：  2019-11-10 13:48


class Solution {
public:
    // 解题思路
    // 依次判断每个字符能否替代前面的字符
    // 1. 判断字符s[i]能否放到结果集合的最后面，即判断当前结果集合中有无该字符，
    //    如果已经有该字符，则直接跳过（因为前期已经插入该字符说明，在之前那个相同字符后面的字符一定比其大，
    //    因为如果比其小的话一定会在第二步被替换）
    // 2. 重复判断字符s[i]能否前进一步
    //    如果前面字符大于s[i]，且在s[i]后面也有相同字符，则s[i]前进位，并将前面字符删除
    string removeDuplicateLetters(string s) {
        string ret;
        for (int i = 0; i < s.length(); ++i) {
            if (ret.find(s[i]) != string::npos) {
                continue;
            }
            while (!ret.empty() && s[i] < ret.back() && s.find(ret.back(), i + 1) != string::npos) {
                ret.pop_back();
            }
            ret.push_back(s[i]);
        }
        return ret;
    }
};
