//  file:  212_word_search2.cpp
//  author：lipcat
//  time：  2019-11-23 00:10


class Solution {
public:
    // solution:
    // 解题方法和word search基本一致
    // 只是word search只要查找一个单词，这个要查找多个单词，那么在找到一个单词后原来的return要进行修改
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        for (auto& word : words) {
            bool finded = false;
            for (int i = 0; i < board.size() && !finded; ++i) {
                for (int j = 0; j < board[i].size(); ++j) {
                    if (dfs(i, j, 0, word, board)) {
                        ans.emplace_back(word);
                        finded = true;
                        break;
                    }
                }
            }
        }
        return ans;
    }
    bool dfs(const int i, const int j, const int cur, string& word, vector<vector<char>>& board) {
        if (cur == word.length()) {
            return true;
        }
        if (i >= 0 && i < board.size() && j >= 0 && j < board[i].size() && word[cur] == board[i][j]) {
            board[i][j] = 0;
            if (dfs(i + 1, j, cur + 1, word, board) ||
                dfs(i - 1, j, cur + 1, word, board) ||
                dfs(i, j + 1, cur + 1, word, board) ||
                dfs(i, j - 1, cur + 1, word, board)) {
                    // 和word search不同，此处也要进行回溯
                    board[i][j] = word[cur];
                    return true;
            }
            board[i][j] = word[cur];
        }
        return false;
    }
};
