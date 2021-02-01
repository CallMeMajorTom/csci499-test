#include "merge_sort.h"

#include <gflags/gflags.h>
#include <glog/logging.h>

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

   MergeSort(arr, 0, size-1);

   str_array = "";
   for (int i = 0; i < size; i++){
     str_array += std::to_string(arr[i]) + " ";
   }
   LOG(INFO) << "After: " << str_array;
   return 0;
}
