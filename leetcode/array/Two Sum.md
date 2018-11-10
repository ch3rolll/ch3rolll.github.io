# Two Sum

## Description

Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 
 You may assume that each input would have exactly one solution. Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

## Solution

1. Use a hash table to store used. For every element in hash_map, check if target-arr[i] exists in the map.
2. Use map<int, vector<int>> to avoid duplicate ones, like 6 = 3 + 3
3. The vector will also return all possible output like [3, ,3 ,3]


## Code

```cpp
#include <unordered_map>
#include <vector>
#include <utility>      // std::pair, std::make_pair

std::vector <std::pair <int, int> > TwoSum(int arr[], int n, int target){
	std::unordered_map <int, std::vector<int>> mymap;
	std::vector <std::pair <int, int> > ret;

	for (auto i = 0; i < n; i++){

		// Find existing elements
		auto it = mymap.find(target - arr[i]);
		if ( it != mymap.end()){
			for (auto idx : it -> second){
				ret.push_back(std::make_pair(idx, i));
			}
		}
		mymap[arr[i]].push_back(i);
	}

	return ret;
}
```
