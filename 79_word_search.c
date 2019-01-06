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

int main(int argc, char** argv) {
  //char* board[] = {"ABCE", "SFCS", "ADEE"};
  char* board[] = {"ab", "cd"};
  char* b[2];
  int r = 2;
  int c = 2;
  int i = 0;
  while (i < r) {
    b[i] = malloc(c + 1);
    strcpy(b[i], board[i]);
    ++i;
  }
  char* w = argv[1];
  if (exist(b, r, c, w)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return 0;
}
