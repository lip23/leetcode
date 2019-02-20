//  file:  946_validate_stack_sequences.c
//  author：lipcat
//  time：  2019-02-20 22:58

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
  int* st = (int*)malloc(sizeof(int) * pushedSize);
  int top = -1;
  int pui = 0;
  int poi = 0;
  while (pui < pushedSize && poi < poppedSize) {
    if (top >= 0 && st[top] == popped[poi]) {
      --top;
      ++poi;
    } else {
      st[++top] = pushed[pui++];
    }
  }
  while (top >=0 && poi < poppedSize && st[top] == popped[poi]) {
    --top;
    ++poi;
  }
  return pui == pushedSize && poi == poppedSize && top == -1;
}

int main(void) {
  int pu1[] = {1, 2, 3, 4, 5};
  int po1[] = {4, 5, 3, 2, 1};
  if (validateStackSequences(pu1, 5, po1, 5)) {
    printf("ture\n");
  } else {
    printf("false\n");
  }

  int pu2[] = {1, 2, 3, 4, 5};
  int po2[] = {4, 3, 5, 1, 2};
  if (validateStackSequences(pu2, 5, po2, 5)) {
    printf("ture\n");
  } else {
    printf("false\n");
  }
  return 0;
}
