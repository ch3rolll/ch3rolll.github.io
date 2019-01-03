##  String Compression

[leetcode](https://leetcode.com/problems/string-compression/)


### Prob

Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

 
Follow up:
Could you solve it using only O(1) extra space?


### Code

```cpp
int StringCompression(std::vector<char>& chars){
	const int N = chars.size();

	if(N < 2) return N;

	int count = 0, index = 0;

	for(int i = 0; i < N; i++){
		count++;

		if( i == N-1 || chars[i]!= chars[i+1] ){
			chars[index++] = chars[i];

			if(count > 1) {
                    for(auto c:to_string(count)) chars[index++] = c;
                }

			count = 0;
		}
	}

	chars.erase(chars.begin()+index-1, chars.end());

	return index;
}
```


## Smallest Range

### Prob

You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

### Code

```cpp

class Solution {
public:
    
    using riter = vector<int>::reverse_iterator;
    using priter = pair<riter,riter>;
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        auto gcomp = [](const priter &p1, const priter &p2)->bool{
            int c1 = *p1.first;
            int c2 = *p2.first;
            return c1 < c2;
        };
             
        int minVal = INT_MAX;
        priority_queue<priter,vector<priter>,decltype(gcomp)> maxq(gcomp);
        
        for(auto &v : nums){
            minVal = min(minVal,v.back());
            maxq.emplace(v.rbegin(),v.rend());
        }
        
        int maxRange = INT_MAX;
        vector<int> res(2,0);
        while(1){
            auto maxfront = maxq.top();
            int range = *(maxfront.first) - minVal;
            
            if(range <= maxRange){
                maxRange = range;
                res[0] = minVal;
                res[1] = *(maxfront.first);
            }
                        
            maxfront.first++;

            if(maxfront.first == maxfront.second){
                break;
            }
            
            maxq.pop();
            minVal = min(minVal,*(maxfront.first));
            maxq.emplace(maxfront.first,maxfront.second);
        }
        
        return res;
    }
};
```
```cpp

#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Item {
    int val;
    int r;
    int c;
    
    Item(int val, int r, int c): val(val), r(r), c(c) {
    }
};

struct Comp {
    bool operator() (const Item& it1, const Item& it2) {
        return it2.val < it1.val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Item, vector<Item>, Comp> pq;
        
        int high = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            pq.push(Item(nums[i][0], i, 0));
            high = max(high , nums[i][0]);
        }
        int low = pq.top().val;
        
        vector<int> res{low, high};
        
        while (pq.size() == (size_t)n) {
            auto it = pq.top();
            pq.pop();
            
            if ((size_t)it.c + 1 < nums[it.r].size()) {
                pq.push(Item(nums[it.r][it.c + 1], it.r, it.c + 1));
                high = max(high, nums[it.r][it.c + 1]);
                low = pq.top().val;
                if (high - low < res[1] - res[0]) {
                    res[0] = low;
                    res[1] = high;
                }
            }
        }
        
        return res;
    }
};
```