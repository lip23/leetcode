//  file:  13_roman_to_integer.cpp
//  author：lipcat
//  time：  2020-01-06 23:32


class Solution {
public:
    // solution:
    // 如果左边的数小于右边的数，则需要减去左边的数
    int romanToInt(string s) {
        unordered_map<char, int> u_map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            int num = u_map[s[i]];
            if (i + 1 < s.length() && u_map[s[i + 1]] > num) {
                ans -= num;
            } else {
                ans += num;
            }
        }
        return ans;
    }
};
