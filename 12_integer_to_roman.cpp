//  file:  12_integer_to_roman.cpp
//  author：lipcat
//  time：  2020-01-06 23:19


class Solution {
public:
    // solution:
    // 1 ~ 9, 和 10 ～ 90的表示逻辑都是一致，所以可以先建立一个dic存储1*到9*的表示逻辑
    string intToRoman(int num) {
        vector<string> dic = {"", "1", "11", "111", "12", "2", "21", "211", "2111", "13"};
        string symbol = "IVXLCDM";
        string ans;
        int beg = 0;
        while (num) {
            int n = num % 10;
            string tmp;
            for (const auto c : dic[n]) {
                tmp += symbol[beg + c - '1'];
            }
            ans = tmp + ans;
            num /= 10;
            beg += 2;
        }
        return ans;
    }
};
