# Length of Last Word

## Prob

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only. 

For example, Given s = "Hello World", return 5.

## Code

```cpp
int LengthOfLastWord(const string& str){
	auto i = std::find(str.rbegin(), str.rend(), ' ');

	if(i == str.rend()) return 0;

	std::string s = std::string(str.rbegin(), i);

	return s.length();
}
```
