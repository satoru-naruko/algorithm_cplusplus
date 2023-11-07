#include <iostream>
#include "search.h"

namespace nrk {
    namespace sort {
        int binarySearch(long long arr[], long long size, long long target) {
            int left = 0;
            int right = size - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == target) {
                    return mid;
                } else if (arr[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return -1;
        }
    }
}  
