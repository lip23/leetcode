//  file:  79_word_search.c
//  author：lipcat
//  time：  2019-01-02 22:38

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool dfs(int i, int j, char** board, int r, int c, char* d) {
  //printf("i=%d, j=%d\n", i, j);
  if (*d == 0) {
    return true;
  }
  if (i < 0 || i >= r || j < 0 || j >= c) {
    return false;
  }
  if (board[i][j] == *d) {
    board[i][j] = 0;
    if (dfs(i - 1, j, board, r, c, d + 1) ||
        dfs(i + 1, j, board, r, c, d + 1) ||
        dfs(i, j -1 , board, r, c, d + 1) ||
        dfs(i, j + 1, board, r, c, d + 1)) {
      return true;
    }
    board[i][j] = *d;
  }
  return false;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
  int i = 0, j = 0;
  for (i = 0; i < boardRowSize; ++i) {
    for (j = 0; j < boardColSize; ++j) {
      if (dfs(i, j, board, boardRowSize, boardColSize, word)) {
        return true;
      }
    }
  }
  return false;
}


class Solution {
public:
    // solution:
    // dfs, 以棋盘中每个元素为起点开始进行搜索
    // 先判断当前点和当前元素是否相同，如果相同先将当前点置为0，表示当前点已经走过（防止当前点被重复计算）,
    // 然后再继续往4个方向进行搜索，搜索结束后要将当前点恢复为原值
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (dfs(i, j, 0, word, board)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(const int i, const int j, const int cur, const string& word, vector<vector<char>>& board) {
        if (cur == word.length()) {
            return true;
        }
        if (i >= 0 && i < board.size() && j >= 0 && j < board[i].size() && board[i][j] == word[cur]) {
            board[i][j] = 0;
            if (dfs(i + 1, j, cur + 1, word, board) ||
                dfs(i - 1, j, cur + 1, word, board) ||
                dfs(i, j + 1, cur + 1, word, board) ||
                dfs(i, j - 1, cur + 1, word, board)) {
                    return true;
            }
            board[i][j] = word[cur];
        }
        return false;
    }
};
