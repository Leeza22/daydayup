#include <stdio.h>

enum Week {
  MON = 1,
  TUE,
  WED,
  THU,
  FRI,
  SAT,
  SUN
};

int main()
{
  enum Week day;
  scanf("%d", &day);

  switch (day) {
    case MON: printf("%s", "monday"); break;
    case TUE: printf("%s", "tuesday"); break;
    case WED: printf("%s", "wednesday"); break;
    case THU: printf("%s", "thursday"); break;
    case FRI: printf("%s", "friday"); break;
    case SAT: printf("%s", "saturday"); break;
    case SUN: printf("%s", "sunday"); break;
    default: printf("%s", "error");
  };
  return 0;
}