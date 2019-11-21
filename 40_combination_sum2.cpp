//  file:  40_combination_sum2.cpp
//  author：lipcat
//  time：  2019-11-19 22:39


class Solution {
public:
    // 解题思路：
    // 带条件的subset2
    // 非递归的解法，依次判断当前元素，当前元素只有两种可能，包含在集合或不包含在集合中
    // 因为candidates中包含相同元素，为了防止subset有重复，对于相同元素要特殊处理，
    // k相同元素构成的subset只能有k+1种
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<vector<int>> subset(1);
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size();) {
            int end = i + 1;
            while (end < candidates.size() && candidates[end] == candidates[i]) {
                ++end;
            }
            int size = subset.size();
            for (int j = 0; j < size; ++j) {
                int sum = accumulate(subset[j].begin(), subset[j].end(), 0);
                auto cur_set = subset[j];
                for (int k = i; k < end; ++k) {
                    cur_set.push_back(candidates[k]);
                    sum += candidates[k];
                    if (sum  == target) {
                        ans.emplace_back(cur_set);
                        break;
                    } else if (sum > target) {
                        break;
                    }
                    subset.emplace_back(cur_set);
                }
            }
            i = end;
        }
        return ans;
    }
};


class Solution {
public:
    // 解题思路：
    // dfs, 每次选一个元素放入集合中
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur_set;
        sort(candidates.begin(), candidates.end());
        dfs(0, target, candidates, cur_set, ans);
        return ans;
    }
    void dfs(const int cur, const int target, const vector<int>& candidates,
             vector<int>& cur_set, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.emplace_back(cur_set);
            return;
        }
        for (int i = cur; i < candidates.size() && target >= candidates[i]; ++i) {
            if (i == cur || candidates[i] != candidates[i - 1]) {
                cur_set.push_back(candidates[i]);
                dfs(i + 1, target - candidates[i], candidates, cur_set, ans);
                cur_set.pop_back();
            }
        }
    }
};
