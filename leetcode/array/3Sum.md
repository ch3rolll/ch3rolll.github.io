# 3Sum

## Desciption

Given an array S of n integers, are there elements a,b,c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
• Elements in a triplet (a, b, c) must be in non-descending order. (ie, a ≤ b ≤ c) • The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4}.
A solution set is:
  (-1, 0, 1)
  (-1, -1, 2)



## Solution

1. Solution 1: Sort the array first, and narrow down --> O(nlogn + n^2)
2. Solution 2: Sort the array, use a hash table to store visited. Then linear scan i and j. Find the key 


## Code

```cpp

#include <algorithm> // std::sort
#include <vector>
#include <tuple> 

std::vector<std::tuple <int, int , int>> ThreeSum(int arr[], const int n, int target){

	std::vector<std::tuple <int, int , int>> result;

	if (n < 3) return result;

	// Sort the array
	std::sort(arr, arr+n);

	for (auto i = 0; i < n - 2; i++){

		if ( i > 0 && arr[i] == arr[i-1] ) continue;

		int l = i + 1;
		int r = n - 1;

		while (l < r){

			if ((arr[i] + arr[l] + arr[r]) == target){
				result.push_back(std::make_tuple(arr[i] ,arr[l], arr[r]));
				++l;
				--r;
				while(arr[l] == arr[l - 1] && arr[r] == arr[r + 1] && l < r) ++l;
			} else if ((arr[i] + arr[l] + arr[r]) < target){
				++l;
				while (arr[l] == arr[l-1]) ++l;
			} else{
				--r;
				while (arr[r] == arr[r-1]) --r;
			}
		}
	}
	return result;
}

```


