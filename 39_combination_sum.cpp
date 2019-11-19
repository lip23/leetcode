//  file:  39_combination_sum.cpp
//  author：lipcat
//  time：  2019-11-19 21:51


class Solution {
public:
    // 解题思路：
    // dfs，每次从集合中选一个
    // 因为找出的集合不关心的顺序，故只需要固定顺序
    // 每次从当前元素开始往后找，因为每个元素都可以被选中多次，所以每次都可以继续选择当前原始
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur_set;
        dfs(candidates, 0, 0, target, cur_set, ans);
        return ans;
    }
    void dfs(const vector<int>& candidates, const int cur, const int sum,
             const int target, vector<int>& cur_set, vector<vector<int>>& ans) {
        if (sum == target) {
            ans.emplace_back(cur_set);
            return;
        }
        for (int i = cur; i < candidates.size() && sum < target; ++i) {
            cur_set.push_back(candidates[i]);
            dfs(candidates, i, sum + candidates[i], target, cur_set, ans);
            cur_set.pop_back();
        }
    }
};
