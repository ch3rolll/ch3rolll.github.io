# 4Sum

## Desciption:

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
Note:
• Elements in a quadruplet (a, b, c, d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d) • Thesolutionsetmustnotcontainduplicatequadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
A solution set is:
  (-1,  0, 0, 1)
  (-2, -1, 1, 2)
  (-2,  0, 0, 2)

## Thoughts:
- Solution 1: Use hashmap to store the array. Linear scan i, j, k --> average O(n^3)
- Solution 2: Use hashmap to store the sum of two elements. Linear scan i , j --> average O(n^3)

**NOTE: Not really need to sort the array. But if the return value has to be sorted, then sort it.**


## Code

```cpp
#include <iostream>
#include <algorithm> //sort
#include <unordered_map>
#include <vector>
#include <tuple>
#include <utility> // pair, make_pair


std::vector<std::tuple<int, int, int, int>> FourSum(int arr[], const int n, const int target){
		
	std::vector<std::tuple<int, int, int, int>> ret;
	//pre-checks
	if (n < 4) return ret;

	std::sort(arr, arr+n);

	std::unordered_map <int, std::vector<std::pair<int, int>>> mymap;

	for (auto i = 0; i < n-1; i++){
		for (auto j = i+1; j < n; j++){
			mymap[arr[i] + arr[j]].push_back(std::make_pair(arr[i], arr[j]));
		}
	}

	for (auto i = 0; i < n-3; i++){
		for (auto j = i+1; j < n-2; j++){
			int residual = target - arr[i] - arr[j];

			if(mymap.find(residual) == mymap.end()) continue;

			auto v = mymap[residual];

			for(auto p : v){
				if (j > p.first) continue;
				ret.push_back(std::make_tuple(arr[i], arr[j], p.first, p.second));
			}
		}
	}
	return ret;
}

int main()
{
    int arr[] = {100, 3, 200, 1, 3, 2, 4, 3};
    const int n = sizeof(arr)/sizeof(arr[0]);
    std::vector<std::tuple<int, int, int, int>> ret = FourSum(arr, n, 306);
    
    for (auto v: ret){
        std::cout<< std::get<0>(v)<<"-"<< std::get<1>(v)<<"-"<< std::get<2>(v)<<"-"<< std::get<3>(v)<<std::endl;
    }
    
    
    return 0;
}

