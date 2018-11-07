# Remove Duplicates from Sorted Array

## Desciption

Given a sorted array, remove the duplicates **in place** such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example, Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].

## Solution 1

Skip same values and keep track of new_num

```cpp

int RemoveDuplicate(int arr[], int n){
	if (n < 2) return n;
	int new_n = 1;

	for (int i = 1; i < n; i++){
		if (arr[i] != arr[i-1]){
			arr[new_n++] = arr[i];
		}
	}
	return new_n;
}
```

## Solution 2

Ultilize STL.

```cpp
#include <algorithm>    // std::unique, std::distance

int RemoveDuplicate(int arr[], int n){
	return std::distance(arr, std::unique(arr, arr+n));
}
```

# Remove Duplicates from Sorted Array II

## Follow up for ”Remove Duplicates”: 

What if duplicates are allowed at most twice? For example, Given sorted array A = [1,1,1,2,2,3],
Your function should return length = 5, and A is now [1,1,2,2,3]

## Solution

Just keep a window with a size of m, compare the first and last one. Dont care about the elements between.

```cpp
int RemoveDuplicate(int nums[], int n, int m) {
      if (n <= 2) return n;
      int index = m;
      for (int i = m; i < n; i++){
          if (nums[i] != nums[index - m])
              nums[index++] = nums[i];
        }
      return index;
    
}
```
