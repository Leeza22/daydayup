#include <stdio.h>
#include <stdlib.h>

int main() {

  FILE *fp;
  char ch;
  if ((fp = fopen("/Users/reginezhang/Documents/xxx/uuu.txt", "wt+")) == NULL) {
    puts("fail to open file!");
    exit(0);
  }

  puts("开始输入文件内容...");
  while ( (ch = getchar()) != '\n' ) {
    fputc(ch, fp);
  }

  fclose(fp);
  puts("输入结束...");
  return 0;
}