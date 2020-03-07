//  file:  239_sliding_window_maximum.cpp
//  author：lipcat
//  time：  2020-03-07 10:59


class Solution {
public:
    // 单调队列deque
    // deque中保存nums[i - k, i]元素中的单调递减序列， 每次i后移时，更新deque即可
    // 主要原理是，求[i - k, i]中的最大元素时，如果nums[i] > nums[i - 1]则最大元素肯定不是nums[i - 1]
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> dq;
        for (int i = 0; i < k - 1; ++i) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for (int i = k - 1; i < nums.size(); ++i) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() <= i - k) {
                dq.pop_front();
            }
            ret.push_back(nums[dq.front()]);
        }
        return ret;
    }
};
