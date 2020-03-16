//  file:  1383_maximum_performance_of_a_team.cpp
//  author：lipcat
//  time：  2020-03-16 12:47


class Solution {
public:
    // 可以把efficiency理解为工作质量，把speed理解成工作速度，则有些人工作又快又好，则工作成果performance则更大
    // 挑选k个工程师组成一个工作团队，该团队的工作质量为团队最小值，可以理解为该工作所需的最低工作质量
    // 当团队所需的工作质量越低，则慢功出细活的工人就没有了优势
    // 所以本题可以先选出工作质量最高的k个工程师
    // 然后再逐渐降低工作质量的要求，用速度快质量低的员工替代速度慢的员工
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
         vector<pair<int, int>> engs(speed.size());
         for (int i = 0; i < speed.size(); ++i) {
             engs[i] = {speed[i], efficiency[i]};
         }
         sort(engs.begin(), engs.end(),
              [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
                  return lhs.second > rhs.second;
              });
        long ans = 0;
        long total_speed = 0;
        priority_queue<int, vector<int>, std::greater<int>> pq;
        for (int i = 0; i < k; ++i) {
            total_speed += engs[i].first;
            ans = max(ans, total_speed * engs[i].second);
            pq.push(engs[i].first);
        }
        for (int i = k; i < n; ++i) {
            if (pq.top() < engs[i].first) {
                total_speed += engs[i].first - pq.top();
                ans = max(ans, total_speed * engs[i].second);
                pq.pop();
                pq.push(engs[i].first);
            }
        }
        return ans % 1000000007;
    }
};
