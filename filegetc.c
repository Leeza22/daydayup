#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;

  char ch;
  if ((fp = fopen("/Users/reginezhang/Documents/xxx/单词摘录.md", "r")) == NULL)
  {
    puts("file to open fail");
    exit(0);
  }

  while (/* condition */(ch = fgetc(fp)) != EOF)
  {
    /* code */
    putchar(ch);
  }
  putchar('\n');

  fclose(fp);
  return 0;
}