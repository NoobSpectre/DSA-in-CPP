#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b) {
  return a < b ? a : b;
}

void print(int *arr, int size) {
  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}

int* merge_in_desc(int *arr1, int *arr2, int size) {
  // resultant array
  int *result = (int *)malloc(sizeof(int) * (2 * size));

  int index1 = 0, index2 = 0, resIndex = 0;

  while(index1 < size && index2 < size) {
    if(arr1[index1] <= arr2[index2])
      result[resIndex++] = arr2[index2++];
    else
      result[resIndex++] = arr1[index1++];    
  }

  while(index1 < size) {
    result[resIndex++] = arr1[index1++];
  }

  while(index2 < size) {
    result[resIndex++] = arr2[index2++];
  }

  return result;
}

int main() {
  int arr1[] = {2, 1, -9};
  int arr2[] = {6, 0, -2};

  int *arr3 = merge_in_desc(arr1, arr2, 3);

  print(arr3, 6);

  return 0;
}