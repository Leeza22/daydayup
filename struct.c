#include <stdio.h>

struct stu {
    char *name;
    int age;
    float score;
  } classA[2] = {
    { "小明", 18, 65.5 },
    { "小红", 17, 99 }
  }, (*pclass)[2] = &classA;

int foreach(struct stu *arr, int length);

int main()
{

  printf("%s\t%d\t%f\n", (*pclass)[0].name, (*pclass)[0].age, (*pclass)[0].score);
  foreach(classA, sizeof(classA)/sizeof(struct stu));
  return 0;
}

int foreach(struct stu *arr, int length)
{
  int i = 0;
  for (i = 0;i<length;i++) {
    printf("%s\t%d\t%f", arr[i].name, arr[i].age, arr[i].score);
  }
  return 0;
}