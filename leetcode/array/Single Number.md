# Single Number

## Prob

Given an array of integers, every element appears twice except for one. Find that single one.
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

## Solution

Accumulate the bit_xor operation


## Code 

```cpp
#include <numeric> // For std::accumulate()
#include <functional> // For std::bit_xor
#include <vector>

int SingleNumber(std::vector<int> vec){
	return std::accumulate(vec.begin(), vec.end(), 0, std::bit_xor<int>());
}
```