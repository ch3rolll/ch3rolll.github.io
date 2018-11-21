# Remove Element

## Prob

Given an array and a value, remove all instances of that value in place and return the new length. The order of elements can be changed. It doesn’t matter what you leave beyond the new length.

## Code

```cpp

#include <algorithm> // std::distance, std::remove

int RemoveElement1(int arr[], const int n, const int target){

	int ret = 0;
	for (auto i = 0; i < n; i++){
		if(arr[i] == target) arr[ret++] = arr[i];
	}

	return ret;
}

int RemoveElement2(int arr[], const int n, const int target){

	return std::distance(arr, std::remove(arr, arr+n, target));
}

```