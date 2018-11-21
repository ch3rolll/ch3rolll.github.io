# K-th Frequent number

## Thoughts
1. Use a map to count how many times it appears.
2. Find the k-th largest number from the map

## Code

```cpp
#include <utility> // For std::pair
#include <set>
#include <algorithm> // For std::nth_element

typedef std::pair<int, int> Pair;

vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    std::vector<int> ret;
    ret.reserve(nums.size());
    for (auto n : nums) {
      if (1 == ++freq[n]) {
        // Count the frequency for each int, storing each new int as we go
        ret.push_back(n);
      }
    }

    // Piviot around the kth element using custom compare. Elements are not sorted, just
    // reordered such that all elements in the range [0, k] are greater than those in [k + 1, n)
    // This is an (average) O(n) operation
    std::nth_element(ret.begin(), ret.begin() + k - 1, ret.end(), [&freq] (int l, int r) -> bool {
        return freq[l] > freq[r];
      });
    ret.resize(k);
    return ret;
}
```

Write the function by myself

```cpp
void QuickSelect(std::vector<int>& vec, std::unordered_map<int, int> mymap, int s, int e, int k){

	if (s >= e) return;
	// Patition
	int j = s+1;
	for(int i = s+1; i < e; i++){
		if(mymap[arr[i] >= mymap[arr[0]]]){
			std::swap(vec[i], vec[j++]);
		}
	}

	std::swap(vec[0], vec[j-1]);
	if (j == k) return;
	else if(j < k) QuickSelect(vec, mymap, j, e, k-j+1);
	else QuickSelect(vec, mymap, s, j-1, k);
}
```
