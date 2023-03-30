#include <stdio.h>

// This is the linear search function that searches for the key in the subarray of arr[] from index low to index high.
int linearSearch(int arr[], int low, int high, int key)
{
    for (int i = low; i <= high; i++)
    {
        if (arr[i] == key)
            return i;
    }

    // If the key is not found, return -1.
    return -1;
}

// This is the meta binary search function that takes an array, its size, and the value to search for as arguments.
int metaBinarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    // Keep dividing the array into smaller subarrays until the size of the subarray is less than 4.
    while ((high - low) > 3)
    {
        // Find the middle index of the current subarray.
        int mid = (low + high) / 2;

        // If the key is less than the middle element, then search in the left half of the subarray. Otherwise, search in the right half of the subarray.
        if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }

    // Once the size of the subarray is less than 4, perform a simple linear search to find the key.
    return linearSearch(arr, low, high, key);
}

int main()
{
    int arr[] = {1, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;
    int index = metaBinarySearch(arr, n, key);
	
	printf("\n========== Meta Binary Search ==========\n");

    if (index != -1)
        printf("Key %d found at index %d\n", key, index);
    else
        printf("Key %d not found in the array\n", key);

    return 0;
}
