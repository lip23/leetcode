//  file:  343_integer_break.c
//  author：lipcat
//  time：  2019-03-05 23:50

#include <stdio.h>
#include <string.h>

#define max(x, y) (x > y ? x: y)

int integerBreak(int n) {
  int arr[n + 1];
  memset((void*)arr, 0, sizeof(arr));
  int i, j;
  for (i = 2; i <= n; ++i) {
    printf("%d\n", arr[i]);
    for (int j = 1; j <= i / 2; ++j) {
      arr[i] = max(arr[i], max(arr[i -j], i-j) * max(arr[j], j));
    }
  }
  return arr[n];
}

int main(void) {
  int n;
  scanf("%d", &n);
  printf("%d\n", n);
  printf("%d\n", integerBreak(n));
  return 0;
}
