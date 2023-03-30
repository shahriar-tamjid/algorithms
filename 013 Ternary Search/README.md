## Ternary Search
The ternary search algorithm is a divide and conquer search algorithm used to find an element in a sorted array. It is similar to binary search, but instead of dividing the array into two parts, it divides it into three parts.

The algorithm works as follows:

- Determine the left and right boundaries of the current search interval
- Calculate two midpoints by dividing the interval into three parts
- Compare the target value with the elements at the two midpoints
- If the target value is equal to an element at a midpoint, return that midpoint
- Otherwise, depending on the comparison result, discard either the left or right portion of the interval and update the boundaries
- Repeat the process until the target value is found or the interval becomes empty.

### Performance
The time complexity of ternary search algorithm is `O(log3 N)` where `N` is the size of the input array. This is because the algorithm divides the array into three parts at each recursive call, and therefore, the size of the problem reduces by a factor of `3` in each recursive step.

### Code Explanation
This code implements the ternary search algorithm to search for a target value in a sorted array. The ternary search algorithm works by dividing the search range into three parts, and recursively searching for the target in the part that may contain it.

```c
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
```
The function `ternarySearch()` takes four arguments: the `sorted array`, the `target value` to search for, and the `left` and `right` indices of the search range in the array. The function first checks if the `left index` is less than or equal to the `right index`. If it is, the function calculates two midpoints `mid1` and `mid2` using the left and right indices. If either midpoint contains the target value, the function returns the corresponding index.

If the target value is less than the element at `mid1`, the function recursively searches the `left` part of the array using the indices `left` and `mid1 - 1`. If the target value is greater than the element at `mid2`, the function recursively searches the `right` part of the array using the indices `mid2 + 1` and `right`. Otherwise, the function recursively searches the middle part of the array using the indices `mid1 + 1` and `mid2 - 1`.
<br>
<br>

```c
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
```
The `main()` function initializes an array and a target value, calls `ternarySearch()` to find the index of the target value in the array, and prints the result.
<br>
<br>

### Sample Output
```bash
========== Ternary Search ==========
Target value found at index 5.
```
<br>

Thanks for reading!