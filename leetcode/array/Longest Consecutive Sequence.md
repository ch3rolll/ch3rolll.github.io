# Longest Consecutive Sequence

## Description

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example, Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.

## Answer

- Solution 1: Naive. Sort it. And do linear scan to check the longest. Use an index, if it is broken, index = 0.
- Solution 2: Use a hash table, store visited and expand for every element

## Code

```cpp
#include <unordered_map>

int LongestConSeq(int arr[], int n){
	
	// Pre-checks
	if (n < 2) return n;

	// Hash-table
	std::unordered_map<int, bool> mymap;
	for (int i = 0; i < n; i++){
		mymap[arr[i]] = true;
	}

	int longest = 1;

	for (auto it = mymap.begin(); it != mymap.end(); it++){
		int num = it->first;

		int length = 0;

		while(mymap.find(num) != mymap.end()){
			length ++;
			num --;
		}
		num = it -> first + 1;
		while(mymap.find(num) != mymap.end()){
			length ++;
			num ++;
		}

		longest = std::max (longest, length);
	}
	return longest;
}

```
