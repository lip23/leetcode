//  file:  1366_rank_teams_by_votes.cpp
//  author：lipcat
//  time：  2020-03-02 16:16


class Solution {
public:
    // 因为最多有26个参赛者，所以stats[i]用0--25表示26个参赛者
    // 又因为最多排26名，所以用stats[i][j]表示参赛者i得到排j名的投票数
    // stats[i][26]来记录参赛者i的名字(即‘A’～'Z')
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> stats(26, vector<int>(27, 0));
        for (int i = 0; i < 26; ++i) {
            stats[i][26] = i;
        }
        for (const auto& vote : votes) {
            for (int rank = 0; rank < vote.size(); ++rank) {
                ++stats[vote[rank] - 'A'][rank];
            }
        }
        sort(stats.begin(), stats.end(),
             [](const auto& lhs, const auto& rhs) {
                 for (int i = 0; i < 26; ++i) {
                     if (lhs[i] != rhs[i]) {
                         return lhs[i] > rhs[i];
                     }
                 }
                 return lhs.back() < rhs.back();
             });
        string ans;
        int cnt = votes.front().length();
        for (int i = 0; i < cnt; ++i) {
            ans.append(1, 'A' + stats[i].back());
        }
        return ans;
    }
};
