# Next Permutation

## Desciption

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascend- ing order).
The replacement must be in-place, do not allocate extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
  1,2,3 → 1,3,2
  3,2,1 → 1,2,3
  1,1,5 → 1,5,1


## Thoughts

1. From right to left, find the first element which violates the increasing order
2. From right to left, find the first element which is greater than pivoting element
3. Swap these two and reverse the order right after


For example, `[1 4 3 6 5]` --> `[1 4 5 3 6]`


## Code

```cpp
#include <algorithm>

void NextPermutation(int arr[], int n){
	if (n < 2) return;

	// Step 1, find pivotIdx
	int pivotIdx = 0, changeIdx = 0;
	for (auto i = n-1; i > 0; i--){
		if (arr[i] > arr[i-1]){ 
		    pivotIdx = i - 1;
		    break;
		}
	}

	// Step 2, find changeIdx
	for (auto i = n-1; i > pivotIdx; i--){
		if (arr[i] > arr[pivotIdx]){
		    changeIdx = i;
		    break;
		}
		    
	}

	// If it is already reverse sorted 
	if(pivotIdx == changeIdx){
	    std::reverse(arr+ pivotIdx, arr+n);
	    return;
	}

	// Step 3: swap
	std::swap(arr[pivotIdx], arr[changeIdx]);

	std::reverse(arr+ pivotIdx + 1, arr+n);
}
```
