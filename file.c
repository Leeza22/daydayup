#include <stdio.h>
#include <stdlib.h>
#define N 100
int main() {

  FILE *fp;
  char str[N + 1];

  fp = fopen("/Users/reginezhang/Documents/xxx/单词摘录.md", "rt");
  if (fp == NULL) {
    puts("fail to open file!");
    exit(0);
  }

  while (fgets(str, 100, fp) != NULL)
  {
    printf("%s", str);
  }

  fclose(fp);

  return 0;
}