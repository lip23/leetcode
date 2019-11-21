//  file:  216_combination_sum3.cpp
//  author：lipcat
//  time：  2019-11-21 08:43


class Solution {
public:
    // 解题思路：
    // combination，每次选一个元素放入集合中
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur_set;
        dfs(1, k, n, cur_set, ans);
        return ans;
    }
    void dfs(const int cur, const int k, const int n, vector<int>& cur_set, vector<vector<int>>& ans) {
        if (cur_set.size() == k && n == 0) {
            ans.emplace_back(cur_set);
            return;
        }
        for (int i = cur; i < 10 && n > 0 && cur_set.size() < k; ++i) {
            cur_set.push_back(i);
            dfs(i + 1, k, n - i, cur_set, ans);
            cur_set.pop_back();
        }
    }
};
