# Add Binary

## Prob
Given two binary strings, return their sum (also a binary string).
For example,
a = "11" b = "1"
Return "100".

## Code

```cpp
std::string AddBinary(string& str1, string& str2){
	std::string res;
	int carry = 0;
	std::reverse(str1.begin(), str1.end());
	std::reverse(str2.begin(), str2.end());
	for(int i = 0;
		i < str1.length() || i < str2.length();
		i++){
		char ch;
		if(i >= str1.length()) ch = str2[i];
		else if(i >= str2.length()) ch = str1[i];
		else{
			ch = str1[i] + str2[i] - '0';
		}
		carry += ch - '0';

		res.insert(res.begin(), '0' + carry%2);
		carry /= 2;
	}

	if(carry) res.insert(res.begin(), '1');

	return res;
}
```