#include "merge_sort.h"
#include <iostream>

void MergeHelper(int* arr, int left, int mid, int right) {
  int size_left = mid - left + 1;
  int size_right = right - mid;

  int arr_left[size_left], arr_right[size_right];
  for (int i = 0; i < size_left; i++ ) {
    arr_left[i] = arr[left + i];
  }

  for (int i = 0; i < size_right; i++ ) {
    arr_right[i] = arr[mid + 1 + i];
  }
  int i = 0;
  int j = 0;
  int k = left;
  while ( i < size_left && j < size_right ) {
    if (arr_left[i] < arr_right[j]) {
      arr[k] = arr_left[i];
      i++;
    } else {
      arr[k] = arr_right[j];
      j++;
    }
    k++;
  }

  while ( i < size_left ) {
    arr[k] = arr_left[i];
    i++;
    k++;
  }

  while ( j < size_right ) {
    arr[k] = arr_right[j];
    j++;
    k++;
  }
}

void MergeSort(int* arr, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = (left + right) / 2;
  MergeSort(arr, left, mid);
  MergeSort(arr, mid + 1, right);
  MergeHelper(arr, left, mid, right);
}
