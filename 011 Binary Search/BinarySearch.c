#include <stdio.h>

int binarySearch(int arr[], int target, int left, int right) {
  // Base case: target not found
  if (left > right) {
    return -1;
  }

  // Find the middle index
  int middle = (left + right) / 2;

  // Compare the middle element with target
  if (arr[middle] == target) {
    // Target found at middle index
    return middle;
  } else if (arr[middle] > target) {
    // Target is in the left half of the array
    return binarySearch(arr, target, left, middle - 1);
  } else {
    // Target is in the right half of the array
    return binarySearch(arr, target, middle + 1, right);
  }
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 11;
  int index = binarySearch(arr, target, 0, n - 1);
  
  printf("\n========== Binary Search ==========\n");
  
  if (index == -1) {
    printf("Target value not found in the array.");
  } else {
    printf("Target value found at index %d.", index);
  }
  return 0;
}
