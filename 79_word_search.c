//  file:  79_word_search.c
//  author：lipcat
//  time：  2019-01-02 22:38

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool dfs(int i, int j, char** board, int r, int c, char* d) {
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
  return dfs(0, 0, board, boardRowSize, boardColSize, word);
}

int main(int argc, char** argv) {
  char board[3][4] = {{'A','B','C','E'},
                      {'S','F','C','S'},
                      {'A','D','E','E'}};
  int r = 3;
  int c = 4;
  char* w = argv[1];
  if (exist(board, r, c, w)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return 0;
}
