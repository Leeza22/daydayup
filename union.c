#include <stdio.h>
#include <stdlib.h>

#define TOTAL 4

struct stu {
   char name[5];
   int age;
   char sex;
   char profession;
   union sc {
      float score;
      char course[10];
   } sc;
} class[TOTAL];

int main() {
  int i = 0;
  for (i=0; i<TOTAL; i++) {
    printf("INPUT INFO: ");
    scanf("%s %d %c %c", class[i].name, &(class[i].age), &(class[i].sex), &(class[i].profession));
    if (class[i].profession == 's') {
      scanf("%f", &(class[i].sc.score));
    } else {
      scanf("%s", class[i].sc.course);
    }
    fflush(stdin);
  }
  printf("\nName\t\tAge\tSex\tProfession\t\tScore / Course\n");
  for (i = 0; i < TOTAL; i++) {
    if (class[i].profession == 's') {
      printf("%s\t\t%d\t%c\t%c\t\t%f\n", class[i].name, class[i].age, class[i].sex,class[i].profession, class[i].sc.score);
    } else {
      printf("%s\t\t%d\t%c\t%c\t\t%s\n", class[i].name, class[i].age, class[i].sex,class[i].profession, class[i].sc.course);
    }
  }
  return 0;
}