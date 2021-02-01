#include "merge_sort.h"
#include <vector>
#include <gtest/gtest.h>

TEST(MergeSort, HandlesEmptyArray) {
    int actual[] = {};
    int expected[] = {};
    int size = sizeof(actual) / sizeof(actual[0]);
    MergeSort(actual, 0, size-1);
    for (int i = 0; i < size; ++i) {
    	EXPECT_EQ(expected[i], actual[i]);
    }
}
