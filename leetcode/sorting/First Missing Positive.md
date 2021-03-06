# First Missing Positive

## Prob

Given an unsorted integer array, find the first missing positive integer. For example, Given [1,2,0] return 3, and [3,4,-1,1] return 2. Your algorithm should run in O(n) time and uses constant space.

## Code

```cpp
int firstMissingPositive(std::vector<int>& nums){
	bucket_sort(nums);

	for(int i = 0; i < nums.size(); ++i){
		if(nums[i] != i +1) return i+1;
	}

	return nums.size() + 1;
}

private: 

void bucket_sort(std::vector<int>& A){
	const int n = A.size();

	for(int i = 0; i < n; i++){
		while(A[i] != i + 1){
			if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
				break;
			std::swap(A[i], A[A[i] - 1]);
		}
	}
}
```