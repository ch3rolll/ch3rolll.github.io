# Gray Code

## Prob 

The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
  00 - 0
  01 - 1
  11 - 3
  10 - 2

Note:
• For a given n, a gray code sequence is not uniquely defined.
• For example,[0,2,3,1]is also avalid gray code sequence according to the above definition.
• For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

## Solution

Reflex-and-prefix

Gray code can be splitted into two steps. 
Step 1: Prefix 0, recursively get GrayCode(n-1)
Step 2: Prefix 1, reflex GrayCode(n-1)

## Code

```cpp
#include <vector>

std::vector<int> GrayCode(const int n){
	
	std::vector<int> result;
	if (n == 1){
		result = {0 ,1};
		return result;
	}

	std::vector<int> ret = GrayCode(n-1);
	result = ret;
	int high = 1<<(n-1);
	for (int i = ret.size() - 1; i >= 0; --i){
		result.push_back( high + ret[i]);
	}

	return result;
}

```

