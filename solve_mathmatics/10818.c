#include <stdio.h>

int main(void) {

  int N;
  scanf("%d", &N);

  int num;
  int max, min;

  for(int i = 0; i < N; i++) {
    scanf("%d", &num);
    if (i == 0) {
      max = num;
      min = num;
    } else {
      if (num > max) {
        max = num;
      }
      if (num < min) {
        min = num;
      }
    }
  }

  printf("%d %d", min, max);

  return 0;
}