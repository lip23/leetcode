//  file:  45_jump_game.cpp
//  author：lipcat
//  time：  2019-11-08 23:26


class Solution {
public:
    // 解题思路：
    // 从后往前，求当前节点i到n-1需要移动的最小步数dp[i]
    // dp[i] = min(1 + dp[i + k])  k = 1 ... nums[i]，计算dp[i]时可以借助单调栈st，
    // st中的每一个元素elem表示，从elem.first到n-1所需最小步数=elem.second
    // st.first为单调递减的，首先因为计算时时从后往前
    // st.second为单调递增的，因为如果栈中(e2)出现比栈顶(e1)大的数，就表示从e2到n-1比从e1到n-1需要的步数要多
    // 但e2比e1更靠后，能到达e2就肯定先到达e1，所以e1的解肯定优于e2的解，所以指需要保留e1
    // 因此st.second为单调递增

    int jump(vector<int>& nums) {
        stack<pair<int, int>> st;
        st.push({nums.size() - 1, 0});
        for (int i = nums.size() - 2; i >=0; --i) {
            if (i + nums[i] < st.top().first) {
                continue;
            }
            auto elem = st.top();
            while (!st.empty() && i + nums[i] >= st.top().first) {
                elem = st.top();
                st.pop();
            }
            st.push(elem);
            st.push({i, elem.second + 1});
        }
        return st.top().second;
    }
};
