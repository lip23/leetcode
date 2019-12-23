//  file:  38_count_and_say.cpp
//  author：lipcat
//  time：  2019-12-23 23:44


class Solution {
public:
    // solution:
    // 顺序生成
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 1; i < n; ++i) {
            string tmp;
            int cnt = 1;
            for (int j = 1; j < ans.length(); ++j) {
                if (ans[j] != ans[j - 1]) {
                    tmp += to_string(cnt) + string(1, ans[j -1]);
                    cnt = 0;
                }
                ++cnt;
            }
            ans = tmp + to_string(cnt) + string(1, ans.back());
        }
        return ans;
    }
};
