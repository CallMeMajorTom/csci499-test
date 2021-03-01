#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
  int size1 = mid - left + 1;
  int size2 = right - mid;

  int arr1[size1], arr2[size2];
  for (int i = 0; i < size1; i++ ) {
    arr1[i] = arr[left + i];
  }

  for (int i = 0; i < size2; i++ ) {
    arr2[i] = arr[mid + 1 + i];
  }
  int i = 0;
  int j = 0;
  int k = left;
  while ( i < size1 && j < size2 ) {
    if (arr1[i] < arr2[j]) {
      arr[k] = arr1[i];
      i++;
    } else {
      arr[k] = arr2[j];
      j++;
    }
    k++;
  }

  while ( i < size1 ) {
    arr[k] = arr1[i];
    i++;
    k++;
  }

  while ( j < size2 ) {
    arr[k] = arr2[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = (left + right) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
  merge(arr, left, mid, right);
}

int main() {
  int arr[] = {5,3,4,1,2};
  int sizeArr = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < sizeArr; i++)
    cout << arr[i] << " ";
  cout << "\n";

  mergeSort(arr, 0, sizeArr-1);

  for (int i = 0; i < sizeArr; i++)
    cout << arr[i] << " ";
  cout << "\n";
}
