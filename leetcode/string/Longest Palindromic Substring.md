# Longest Palindromic Substring

## Prob

> Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

## Thoughts

- Solution 1. For every element, use a point from i and the end to narrow down.
- Solution 2. Memorize palindromic pairs (DP)
- Solution 3. Manacher's Algorithm

## Code

- Solution 1:
```cpp
int LongestPalindromic(const std::string& str){
	if (str.length() < 1) return 0;
	int ret = 1;
	for(int i = 0; i < str.length() - 1; i++){
		int k = str.length() - 1;
		int temp = 0;
		while(k > i){
			if(str[i] == str[k]){
				bool isPal = isPalindromic(str.substr(i, k-i+1));
				if (isPal){
    				temp = k-i+1;
    				break;
				}
			}
			k--;
		}
		ret = std::max(ret, temp);
	}
	return ret;
}


bool isPalindromic(const std::string& str){
	for(int l = 0, r = str.length()-1; 
		l + 1 < r;
		l++, r--){
		if(str[l] != str[r]) return false;
	}
	return true;
}
```


- Solution 2: DP

```cpp
#include <algorithm>

int LongestPalindrome(const string& s){
	const int n = s.size();
	bool f[n][n];
	std::fill_n(&f[0][0], n*n, false);

	size_t max_len = 1, start = 0;

	for(auto i = 0; i < s.size(); i++){
		f[i][i] = true;
		for(auto j = 0; j < i; j++){
			f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j+1][i-1]));

			if (f[j][i] && max_len < (i - j + 1)){
				max_len = i - j + 1;
				start = j;
			}
		}
	}
	return max_len;
}
```


- Solution 3: Manacher

```cpp

```
