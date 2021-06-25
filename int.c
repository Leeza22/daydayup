#include <stdio.h>
union {
  int i;
  short h;
  char c;
} un;

int main() {

  int i = 1;
  // printf("%d", *(char *)&i);
  un.i = 1;
  if (un.c == 1) {
    printf("1 = %d", un.h);
  } else {
    printf("2 = %d", un.h);
  }
  return 0;
}