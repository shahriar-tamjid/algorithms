## Binary Search
Binary search is a searching algorithm that finds the position of a target value within a sorted array. It works by repeatedly dividing the search interval in half, comparing the middle element with the target value, and adjusting the interval accordingly until the target value is found or the interval is empty.

Here's an example in simple words:

Suppose we have a sorted list of numbers: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19

And we want to find the position of the number `11` in the list using binary search algorithm:
- First, identify the middle element of the list, which is `9`.
- Compare the middle element `9` with the target value `11`.
- Since the target value `11` is greater than the middle element `9`, we know that the target value must be in the `upper half` of the list or in other words in the `right` side of the list.
- So, we discard the `lower half` of the list or the `left` side of the list and repeat the process on the `upper half`.
- The new middle element is `15`, which is greater than the target value `11`.
- So, we discard the `upper half` of the list and repeat the process on the `lower half`.
- The new middle element is `11`, which is equal to the target value `11`.
- We have found the target value at position `6`.

### Performance
The time complexity of the binary search algorithm is `O(log n)`, where n is the number of elements in the sorted array. This is because in each step, the algorithm divides the search space in half and only searches in one of the halves. As a result, the number of elements to search reduces by half in each step. This logarithmic behavior makes binary search very efficient for searching large sorted arrays.

### Code Explanation
```c
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
```
- The function `binarySearch()` takes four arguments: the array to be searched, the target value to search for, and the left and right indices of the subarray to search within.
- The function checks if the left index is greater than the right index. If it is, the target value has not been found in the array and the function returns `-1`.
- If the left index is not greater than the right index, the function calculates the middle index by taking the average of the left and right indices.
- The middle element of the subarray is compared to the target value. If they are equal, the function returns the middle index as the index of the target value in the array.
- If the middle element is greater than the target value, the target value must be in the left half of the subarray. The function calls itself recursively with the left index and the middle index minus one as the new left and right indices, respectively.
- If the middle element is less than the target value, the target value must be in the right half of the subarray. The function calls itself recursively with the middle index plus one and the right index as the new left and right indices, respectively.
<br>
<br>

```c
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
```
- In the `main()` function, an example array is defined and the `binarySearch()` function is called with the target value and the indices of the entire array.
- The return value of binary_search() is checked to see if it is -1, indicating that the target value was not found, or an index in the array, indicating that the target value was found.
- The appropriate message is printed to the console depending on whether the target value was found or not.
<br>
<br>

### Sample Output
```bash
========== Binary Search ==========
Target value found at index 5.
```
<br>

Thanks for reading!