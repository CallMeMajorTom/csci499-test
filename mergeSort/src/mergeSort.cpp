#include <iostream>
#include <glog/logging.h>
#include <gflags/gflags.h>

void merge(int arr[], int left, int mid, int right) {
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

void mergeSort(int arr[], int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = (left + right) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
  merge(arr, left, mid, right);
}

int main(int argc, char** argv) {
  FLAGS_logtostderr = 1;
  // Initialize Google's logging library.
  google::InitGoogleLogging(argv[0]);

  int arr[] = {5,3,4,1,2};
  int size = sizeof(arr) / sizeof(arr[0]);
	
  std::string str_array = "";
  for (int i = 0; i < size; i++)
    str_array += std::to_string(arr[i]) + " ";
  LOG(INFO) << "Before: " << str_array;

  mergeSort(arr, 0, size-1);

  str_array = "";
  for (int i = 0; i < size; i++){
    str_array += std::to_string(arr[i]) + " ";
  }
  LOG(INFO) << "After: " << str_array;
}
