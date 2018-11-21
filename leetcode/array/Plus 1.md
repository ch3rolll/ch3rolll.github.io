# Plus 1

#Prob

Given a number represented as an array of digits, plus one to the number.

## Code

```cpp
#include <vector>

void Plus1(std::vector<int>& v){
	int carry = 1;
	for (auto it = v.rbegin(); it!=v.rend(); it++){
		*it += carry;
		carry = *it /10;
		*it %= 10;
	}
	if (carry) v.insert(v.begin(), carry);
}
```