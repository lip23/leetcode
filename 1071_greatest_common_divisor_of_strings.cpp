//  file:  1071_greatest_common_divisor_of_strings.cpp
//  author：lipcat
//  time：  2020-03-12 23:19


class Solution {
public:
    // 辗转相除法
    string gcdOfStrings(string str1, string str2) {
        if (str1 < str2) {
            return gcdOfStrings(str2, str1);
        }
        int beg = 0;
        while (beg + str2.length() <= str1.length() &&
               str1.substr(beg, str2.length()) ==  str2) {
            beg += str2.length();
        }
        if (beg + str2.length() <= str1.length()) {
            return "";
        }
        if (beg == str1.length()) {
            return str2;
        }
        return gcdOfStrings(str2, str1.substr(beg));
    }
};
