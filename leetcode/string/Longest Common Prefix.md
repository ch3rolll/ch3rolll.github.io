# Longest Common Prefix

## Prob

Write a function to find the longest common prefix string amongst an array of strings.

## Code

```cpp
std::string LongestPrefix(const std::vector<std::string> &strs){
	std::string ret = "";
	if(strs.empty()) return ret;

	for(int i = 0; i < strs.size();i++){
		for(int j = 1; k < str[0].size(); i++){
			if(strs[0][j] != strs[i][j]) return strs[0].substr(0, i); // Second variable is the length
		}
	}

	return strs[0];
}
```