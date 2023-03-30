## Meta Binary Search
Meta binary search is an optimization technique for searching a sorted list of elements. The goal of this technique is to minimize the number of comparisons made during the search process.

In regular binary search, we compare the target element with the middle element of the list and move the search to either the left or the right side of the list based on the comparison result. In meta binary search, we use a similar approach, but instead of comparing the target element directly, we compare it with a meta element that is computed from the middle elements of several sublists.


### Example
For example, let's say we have a sorted list of integers: `[1, 3, 5, 7, 9, 11, 13, 15, 17]`. To search for the element `9` using meta binary search, we first divide the list into three sublists: `[1, 3, 5]`, `[7, 9, 11]`, and `[13, 15, 17]`. Then, we compute the meta element for each sublist by taking the median of the middle element and its two adjacent elements. In this case, the meta elements are `3`, `9`, and `15`.

Next, we compare the target element `9` with the meta element `9`. Since they are equal, we know that the target element is in the second sublist `[7, 9, 11]`. We repeat the process on this sublist, dividing it into three sub-sublists and computing the meta elements for each of them. We continue this process until we find the target element or determine that it is not in the list.


### Performance
The time complexity of meta binary search is `O(log(log(n)))`, which is better than `O(log(n))` time complexity of binary search in certain cases. This is because meta binary search reduces the search space by taking jumps rather than linearly traversing the array. However, it requires an additional logarithmic search to determine the jump size, which adds to the overall time complexity.


### Code Explanation
```c
// This is the linear search function that searches for the target in the subarray of arr[] from index low to index high.
int linearSearch(int arr[], int low, int high, int target) {
	
    for(int i = low; i <= high; i++) {
        if(arr[i] == target){
            return i;
        }
    }
    
	// If the target is not present, then return -1
    return -1;
}
```
The `linearSearch` function simply iterates over the subarray and checks if each element is equal to the target value. If the target value is found, the index of the element is returned. If the target value is not found, `-1` is returned.
<br>
<br>

```c
// This is the meta binary search function that takes an array, its size, and the target value to search for as arguments.
int metaBinarySearch(int arr[], int size, int target)
{
	// Define the search interval
    int low = 0, high = size - 1;

    // Keep dividing the array into smaller subarrays until the size of the subarray has a size of 3.
    while ((high - low) > 3)
    {
        // Find the middle index of the current subarray.
        int mid = (low + high) / 2;

        // If the target is less than the middle element, then search in the left half of the subarray. Otherwise, search in the right half of the subarray.
        if (arr[mid] > target)
            high = mid;
        else
            low = mid;
    }

    // Once the size of the subarray is of size 3, perform a simple linear search to find the target.
    return linearSearch(arr, low, high, target);
}
```
In the `metaBinarySearch` function, the array is first divided into smaller subarrays until the size of the subarray is `3`. This is done using a while loop that checks the difference between the high and low indices. If the difference is greater than `3`, the middle index is calculated, and the subarray to search is determined based on whether the target value is less than or greater than the middle element.

Once the size of the subarray is `3`, a simple linear search is performed to find the target. This is done by calling the `linearSearch` function, which searches for the target in the subarray of `arr[]` from index low to index high.
<br>
<br>

```c
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 9;
    int index = metaBinarySearch(arr, size, target);
	
	printf("\n========== Meta Binary Search ==========\n");

    if (index != -1)
        printf("Target value %d found at index %d\n", target, index);
    else
        printf("Target value %d not found in the array\n", target);

    return 0;
}
```
In the `main` function, an array is defined, and the `metaBinarySearch` function is called to search for the target`9`. The index of the target is printed if it is found, and a message is printed if it is not found.
<br>
<br>

### Sample Output
```bash
========== Meta Binary Search ==========
Target value 9 found at index 4
```
<br>

Thanks for reading!