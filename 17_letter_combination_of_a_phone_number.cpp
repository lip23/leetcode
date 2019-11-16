//  file:  17_letter_combination_of_a_phone_number.cpp
//  author：lipcat
//  time：  2019-11-16 10:44


class Solution {
public:
    // 解题思路：
    // 按顺序处理每一个digit，用一个数组(ret)保存当前已经生成的字母组合
    // 在处理新的digit时，遍历数组ret，将ret中的每个元素都加上digit对应的字母，然后存入到ret中
    vector<string> letterCombinations(string digits) {
        vector<string> num_2_alphs = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret(1, "");
        for (const auto digit : digits) {
            int end = ret.size();
            for (int i = 0; i < end; ++i) {
                const auto& alphs = num_2_alphs[digit - '2'];
                for(int j = 1; j < alphs.length(); ++j) {
                    ret.push_back(ret[i] + string(1, alphs[j]));
                }
                ret[i].append(1, alphs[0]);
            }
        }
        return digits.empty() ? vector<string>() : ret;
    }
};
