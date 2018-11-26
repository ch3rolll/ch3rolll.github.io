# Valid Parentheses

## Prob
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]" are all valid but "(]" and "([)]" are not.

## Code

```cpp
#include <unordered_map>

bool isValidParentheses(const string& str){

	std::unordered_map<char, char> mymap = {{')','('}, {']','['},{'}','{'}};

	std::stack<char> mstack;

	for (auto c:str){
		if (c == '(' || c == '[' || c == '{') mstack.push(c);
		else{
			if(mstack.empty() || mstack.top() != mymap[c]) return false;
			else mstack.pop();
		}
	}

	return mstack.empty();

}
```