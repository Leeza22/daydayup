#include <stdio.h>

void foreach(int arr[], int len)
{
  int i;
  printf("arr=");
  for (i=0;i<len;i++) {
    printf("%d, ", arr[i]);
  }
}

void bubble(int arr[], int len)
{
  int i,j,temp;
  for(i=0;i<len-1;i++) {
    for(j=0;j<len-1-i;j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void bubble_flag(int arr[], int len)
{
  int i,j,temp;
  int flag;
  for (i=0;i<len-1;i++){
    flag = 0;
    for(j=0;j<len-1-i;j++) {
      if (arr[j] > arr[j+1]) {
        temp  = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        flag = 1;
      }
    }
    if (flag == 0) break;
  }
}

void selection(int arr[], int len)
{
  int i,j,temp;
  int min;
  for(i=0;i<len-1;i++) {
    min = i;
    for(j=i+1;j<len;j++) {
      if (arr[j] < arr[min])
        min = j;
    }
    if(min != i) {
      temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
}

void insertion(int arr[], int len)
{
  int i,j,temp;
  for(i=0;i<len;i++) {
    temp = arr[i];
    for(j=i;j>0 && arr[j-1] > temp;j--){
      arr[j] = arr[j-1];
    }
    arr[j] = temp;
    foreach(arr, len);
    printf("\n");
  }
}

void shell(int arr[], int len)
{
  int i,j,temp;
  int gap;
  for(gap = len >> 1;gap > 0; gap = gap >> 1) {
    for(i=gap;i<len;i++) {
      temp = arr[i];
      for(j=i-gap;j>=0 && arr[j] > temp;j -= gap)
        arr[j + gap] = arr[j];
      arr[j + gap] = temp;
      foreach(arr, len);
      printf("\n");
    }
  }
}

void merge_sort_recursive(int arr[], int reg[], int start,int end)
{
  if (start >= end) {
    return;
  };
  int len = end - start, mid = (len >> 1) + start;
  int start1 = start, end1 = mid;
  int start2 = mid + 1, end2 = end;
  printf("%d,%d\t", start, end);
  printf("%d,%d\t", start1, end1);
  printf("%d,%d\n", start2, end2);
  merge_sort_recursive(arr, reg, start1, end1);
  merge_sort_recursive(arr, reg, start2, end2);
  int k = start;
  printf("s%d,%d,%d\n", start, start1, start2);
  printf("e%d,%d,%d\n", end, end1, end2);
  while(start1<=end1 && start2<=end2) {
    reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
  }
  printf("%d,%d,%d\n", start, start1, start2);
  foreach(reg, len);
  printf("\n");
  while (start1<=end1)
  {
    reg[k++] = arr[start1++];
  }
  while (start2<=end2)
  {
    reg[k++] = arr[start2++];
  }
  for(k=start;k<=end;k++){
    arr[k] = reg[k];
  }
  foreach(arr, len);
  printf("\n");
}
void merge_sort(int arr[], int len)
{
  int reg[len];
  merge_sort_recursive(arr, reg, 0, len-1);
}


int main()
{
  int arr[10] = { 2,7,3,4,9,2,1,8,5,0 };
  int len = (int) sizeof(arr) / sizeof(*arr);

  merge_sort(arr, len);

  foreach(arr, len);
  return 0;
}