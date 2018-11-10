# 3Sum Closest

## Description

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
For example, given array S = {-1 2 1 -4}, and target = 1. The sum that is closest to the target is 2. (-1+2+1=2).


## Solution:
Step 1: Sort the array
Step 2: For each element, narrow down and record the closest

## code

```cpp

#include <algorithm> // For STL sort
#include <climits> // For INT_MAX

int Closest3Sum(int arr[], const int n, int target){
	int ret = -1;
	
	// Pre-checks
	if ( n < 3 ) return ret;

	// Sort
	std::sort(arr, arr+n);

	//
	int dist = INT_MAX;
	int closest;

	for (auto i = 0; i < n-2; i++){
		int l = i+1, r = n-1;
		
		while (l < r){

			int dist_temp = target - arr[i] - arr[l] - arr[r];
			
			std::cout << arr[i] <<"- l: "<<arr[l] <<" r:" <<arr[r]<<std::endl;

			if (std::abs(dist_temp) < dist){
				dist = dist_temp;
				closest = arr[i] + arr[l] + arr[r];
			}

			if (dist_temp < 0){
				--r;
				while (arr[r] == arr[r+1]) --r;
			} else if (dist_temp > 0){
				++l;
				while (arr[l] == arr[l-1]) ++l;
			} else return target;
		}

	}
	return closest;
}
```
