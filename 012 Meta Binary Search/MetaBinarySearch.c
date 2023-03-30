#include <stdio.h>

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
