//  file:  78_subset.cpp
//  author：lipcat
//  time：  2019-11-09 09:18


class Solution {
public:
    // 解题思路：
    // 利用子问题的思想，先求前k-1个数构成的subset(ss[k-1])，然后前k个数构成的subset(ss[k])求解公式如下：
    // ss[k] = ss[k - 1] 并 {ss[k - 1][i] 并 nums[k]}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret (1);
        for (const auto num : nums) {
            int k = ret.size();
            for (int i = 0; i < k; ++i) {
                auto tmp = ret[i];
                tmp.push_back(num);
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};

class Solution {
public:
    // 解题思路：
    // dfs, 每次递归中都分别计算包含当前元素和不包含当前元素的情况
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur_set;
        dfs(0, nums, cur_set, ret);
        return ret;
    }
    void dfs(int cur, const vector<int>& nums, vector<int>& cur_set, vector<vector<int>>& ans) {
        if (cur == nums.size()) {
            ans.emplace_back(cur_set);
            return;
        }
        dfs(cur + 1, nums, cur_set, ans);
        cur_set.push_back(nums[cur]);
        dfs(cur + 1, nums, cur_set, ans);
        cur_set.pop_back();
    }
};
