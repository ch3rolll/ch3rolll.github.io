# Gas Station

## Prob

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station’s index if you can travel around the circuit once, otherwise return -1. Note: The solution is guaranteed to be unique.

## Solution

1. Start from index 0, remain += gas[i] - cost[i]. If remain < 0, remain = 0;
2. Check the last index to return to index 0


## Code

```cpp
#include <vector>
#include <algorithm>

int GasStation(std::vector<int> gas, std::vector<int> cost){
	const n = gas.size();

	int remain = 0;
	int index = 0;

	int total = 0;
	for (int i = 0; i < n; i++){

		if(remain < 0){
			index = i;
			remain = 0;
		}

		total += gas[i] - cost[i];
		remain += remain+gas[i] - cost[i];
	}

	return (total>0) ? index : -1;
} 

``` 