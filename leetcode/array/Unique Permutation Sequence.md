# Unique Permutation Sequence

## Question

The set [1,2,3,...􏲳,n] contains a total of n! **unique** permutations.
By listing and labeling all of the permutations in order, We get the following sequence (ie, for n = 3):
  "123"
  "132"
  "213"
  "231"
  "312"
  "321"
Given n and k, return the kth permutation sequence. Note: Given n will be between 1 and 9 inclusive.

## Thoughts:

[kanton permutation](https://blog.csdn.net/u011531613/article/details/62237453)
[English Version](https://www.topcoder.com/blog/generating-permutations/)

1. For k-th, the first element would be the `p = (k-1)/(n-1)! ` smallest element in the array.
2. k = k % (n-1)!
3. Do the same thing till `i == 0`
4. Put the last remaining element

## Code

```cpp
#include <algorithm>
#include <string>


int factorial(const int n){
	if n == 0 return 1;
	return factorial(n-1);
}

std::string getPermutation(const int n, int k){
	std::string s(n, '0');
    std::string result;
    for (int i = 0; i < n; ++i) s[i] += i + 1;

    return KPermutation(s, k);
}


template<typename Sequence>
std::string KPermutation(const Sequence& seq, int k){
	const int n = seq.size();
    Sequence S(seq);
    Sequence result;
	int base = factorial(n - 1); 

	--k;

	for (int i = n - 1; i > 0; k %= base, base /= i, --i) {
		auto a = std::next(S.begin(), k / base);
		result.push_back(*a);
		S.erase(a);
	}
	result.push_back(S[0]);
	return result;
}

```