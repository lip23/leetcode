//  file:  845_longest_mountain_in_array.c
//  author：lipcat
//  time：  2019-01-01 11:11

#include <stdio.h>

int arr[10000];

int LongestMountain(int* arr, int asize) {
  int ml = 0;  // max length
  int i = 0;
  while (i < asize) {
    int beg = i;
    while (i + 1 < asize && arr[i+1] - arr[i] > 0) {
      ++i;
    }
    int al = i - beg;  // ascend length
    if (al == 0) {
      ++i;
      continue;
    }
    beg = i;
    while (i + 1 < asize && arr[i+1] - arr[i] < 0) {
      ++i;
    }
    int dl = i - beg;  // descend length
    if (dl == 0) {
      ++i;
      continue;
    }
    if (al + dl + 1 > ml) {
      ml = al + dl + 1;
    }
  }
  return ml;
}

void InputArray(int asize) {
  int i = 0;
  for (; i< asize; ++i) {
    scanf("%d", arr + i);
  }
}

int main(void) {
  int n = 0;
  scanf("%d", &n);
  InputArray(n);
  printf("%d\n", LongestMountain(arr, n));
  return 0;
}
