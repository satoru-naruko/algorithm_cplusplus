#include <gtest/gtest.h>
#include "search.h"

using namespace nrk::sort;

TEST(BinarySearchTest, EmptyArray) {
    long long arr[] = {};
    long long size = 0;
    long long target = 10;
    EXPECT_EQ(-1, binarySearch(arr, size, target));
}

TEST(BinarySearchTest, TargetNotFound) {
    long long arr[] = {1, 3, 5, 7, 9};
    long long size = 5;
    long long target = 4;
    EXPECT_EQ(-1, binarySearch(arr, size, target));
}

TEST(BinarySearchTest, TargetFound) {
    long long arr[] = {1, 3, 5, 7, 9};
    long long size = 5;
    long long target = 5;
    EXPECT_EQ(2, binarySearch(arr, size, target));
}

TEST(BinarySearchTest, TargetFoundAtFirstIndex) {
    long long arr[] = {1, 3, 5, 7, 9};
    long long size = 5;
    long long target = 1;
    EXPECT_EQ(0, binarySearch(arr, size, target));
}

TEST(BinarySearchTest, TargetFoundAtLastIndex) {
    long long arr[] = {1, 3, 5, 7, 9};
    long long size = 5;
    long long target = 9;
    EXPECT_EQ(4, binarySearch(arr, size, target));
}
