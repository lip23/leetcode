//  file:  754_reach_a_num.c
//  author：lipcat
//  time：  2018-12-30 13:41

#include <stdio.h>
#include <stdlib.h>

int GetTotalStepToReachTheTarget (int target) {
  target = abs(target);
  int i = 1;
  int gap = target;
  while ((gap = target - i * (i + 1) / 2) > 0) {
    ++i;
  }
  if ((-gap) % 2 == 0) {
    return i;
  }
  if ((i + 1) % 2 == 0) {
    return i + 2;
  }
  return i + 1;
}

int main(void) {
  int target;
  scanf("%d", &target);
  printf("%d\n", GetTotalStepToReachTheTarget(target));
  return 0;
}
