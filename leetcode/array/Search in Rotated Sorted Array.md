# Search in Rotated Sorted Array

## Description

Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1. You may assume no duplicate exists in the array.

## Solution
1. Naive Solution: linear scan O(n)

2. O(logn), binary search. Compare the mid with left and right neighbor. Randomized will imporve worst case.

```cpp

int SearchRotatedArray( int arr[], int n, int target){
	if (n < 2) return n-1;
	int l = 0, r = n-1;

	while(l < r){
		//int mid = (l + r )/2; // DONT USE IT TO AVOID OVERFLOW
		int mid = l + ( r - l ) / 2;
		if (arr[mid] == target){
			return mid;
		} 

		if (arr[l] <= arr[mid]){
			if (arr[l] <= target && target < arr[mid]) r = mid -1;
			else l = mid + 1;
		}else{
			if (arr[mid] < target && target <= arr[r]) l = mid + 1;
			else r = mid - 1;
		}
	}
	return -1;
}
```


# Search in Rotated Sorted Array II

## Desciption

**Follow up for ”Search in Rotated Sorted Array”:**

What if duplicates are allowed? Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.

## Answer

Yes, You would have to check the left and right with mid.

===> Skip the duplicate left ones.


```cpp

int SearchRotatedArray( int arr[], int n, int target){
	if (n < 2) return n-1;
	int l = 0, r = n-1;

	while(l < r){
		//int mid = (l + r )/2; // DONT USE IT TO AVOID OVERFLOW
		int mid = l + ( r - l ) / 2;
		if (arr[mid] == target){
			return mid;
		} 

		if (arr[l] < arr[mid]){
			if (arr[l] <= target && target < arr[mid]) r = mid -1;
			else l = mid + 1;
		} else if(arr[l] > arr[mid]){
			if (arr[mid] < target && target <= arr[r]) l = mid + 1;
			else r = mid - 1;
		} else l++;
	}
	return -1;
}
```