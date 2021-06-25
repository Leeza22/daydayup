#include <stdio.h>

int fn1(int a, int b);

int main() {

  // typedef char string[20];
  // string s = "jdkjskajkd";
  // puts(s);


  // 指针别名
  // 1. 二维数组指针
  typedef int (*PRO_ARR)[5];
  typedef int (*PRO_F)(int a, int b);

  int str[3][5] = {
    {1,2,3,8,7},
    {4,5,6},
    {7,8,9}
  };
  PRO_ARR p1 = str;
  int i = 0;
  for(i=0;i<3;i++) {
    for(int j=0;j<5;j++) {
      printf("%d", p1[i][j]);
    }
    printf("\n");
  }


  // 函数指针
  PRO_F pf = fn1;
  printf("%d", pf(2, 4));
  return 0;
}

int fn1(int a, int b) {
  return a + b;
}