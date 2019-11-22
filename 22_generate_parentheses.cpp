//  file:  22_generate_parentheses.cpp
//  author：lipcat
//  time：  2019-11-16 21:52


class Solution {
public:
    // 解题思路：
    // dfs, 每次递归生成一个括号，生成括号时要考虑到所以满足条件的情况
    // 如果左括号剩余数>0，则可生成左括号
    // 如果有括号剩余数>=左括号剩余数，则可生成右括号
    void dfs(string& pars, const int left_count, const int right_count, vector<string>& ans) {
        if (right_count == 0) {
            ans.push_back(pars);
            return;
        }
        if (left_count > 0) {
            dfs(pars.append(1, '('), left_count - 1, right_count, ans);
            pars.pop_back();
        }
        if (right_count > left_count) {
            dfs(pars.append(1, ')'), left_count, right_count - 1, ans);
            pars.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string pars;
        vector<string> ans;
        dfs(pars, n, n, ans);
        return n > 0 ? ans : vector<string>();
    }
};
