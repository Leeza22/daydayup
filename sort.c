#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void foreach(int arr[], int len);

void bubble_sort(int arr[], int len);
void bubble_sort_flag(int arr[], int len);

void selection_sort(int arr[], int len);

void insertion_sort(int arr[], int len);

void shell_sort(int arr[], int len);

int main()
{
  int arr[10] = { 8,4,2,34,23,28,12,9,34,0 };
  int len = (int) sizeof(arr) / sizeof(*arr);
  shell_sort(arr, len);

  int i = 0;
  for (i = 0; i < len; i++)
    printf("%d, ", arr[i]);
  return 0;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void foreach(int arr[], int len)
{
  int i = 0;
  for (i = 0; i < len; i++)
    printf("%d\t", arr[i]);
}

void bubble_sort(int arr[], int len)
{
  int i, j, temp;
  for (i = 0; i< len - 1; i++) {
    for (j = 0; j < len - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

// 冒泡（设置交换标记）
void bubble_sort_flag(int arr[], int len)
{
  int i, j, temp, flag;
  for (i = 0; i< len - 1; i++) {
    flag = 0;
    for (j = 0; j < len - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
        flag = 1;
      }
    }
    if (flag == 0) break;
  }
}

// 选择排序
void selection_sort(int arr[], int len)
{
  int i, j, temp;
  for (i = 0; i < len - 1; i++) {
    int min = i;
    for(j = i + 1; j < len; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    if (min != i) {
      swap(&arr[i], &arr[min]);
    }
  }
}


void insertion_sort(int arr[], int len)
{
  int i, j, temp;
  for (i = 0; i < len; i++) {
    temp = arr[i];
    for (j = i; j > 0 && arr[j - 1] > temp; j--) {
      arr[j] = arr[j - 1];
    }
    arr[j] = temp;
    // foreach(arr, len);
    // printf("\n");
  }
}

void shell_sort(int arr[], int len)
{
  int i, j, temp;
  int gap;
  for (gap = len >> 1; gap > 0; gap = gap >> 1) {
    printf("gap=%d\n", gap);
    for (i = gap; i < len; i++) {
      printf("i=%d\n", i);
      temp = arr[i];
      for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
          arr[j + gap] = arr[j];
      arr[j + gap] = temp;
    }
  }
}
// 希尔排序
// 是donald shell 1959年提出的一种排序算法。希尔排序也是一种插入排序，它是简单插入排序经过改进之后的一种更高效的版本，也称为缩小增量排序。同时该算法也是冲破O(n2)的第一批算法之一。
// 希尔排序是把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；随着增量逐渐减少，每组包含的关键词越来越多，当增量减至1时，整个文件被分成一组，算法便终止。
