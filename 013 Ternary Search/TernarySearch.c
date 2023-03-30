int ternarySearch(int arr[], int target, int left, int right) {
  if (left <= right) {
    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;

    if (arr[mid1] == target) {
      return mid1;
    }
    if (arr[mid2] == target) {
      return mid2;
    }
    if (target < arr[mid1]) {
      return ternarySearch(arr, target, left, mid1 - 1);
    } else if (target > arr[mid2]) {
      return ternarySearch(arr, target, mid2 + 1, right);
    } else {
      return ternarySearch(arr, target, mid1 + 1, mid2 - 1);
    }
  }
  return -1;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 6;
  int index = ternarySearch(arr, target, 0, n - 1);
  
  printf("\n========== Ternary Search ==========\n");
  
  if (index == -1) {
    printf("Target value not found in the array.");
  } else {
    printf("Target value found at index %d.", index);
  }
  return 0;
}
