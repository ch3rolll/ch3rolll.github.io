# Trapping Rain Water

## Prob

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
For example, Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

## Solution

1. For every bar, find the max_left & max_right. the volumn = min(max_left, max_right) - height


## Code

```cpp

int RainWater(int arr[], const int n){
	int res = 0;
	if (n < 2) return res;

	// Find the left max
	int* left_max(arr), right_max(arr);
	for (int i = 1; i < n; i++){
		left_max[i] = std::max(arr[i], left_max[i-1]);
	}

	// Find the right max
	for (int i = n-1; i >=0; i++){
		right_max[i] = std::max(arr[i], right_max[i+1]);
	}

	for (int i = 0; i < n; i++){
		res += std::min(left_max[i], right_max[i]) - arr[i];
	}

	return res;
}
```