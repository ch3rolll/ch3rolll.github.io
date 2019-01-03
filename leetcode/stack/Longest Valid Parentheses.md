# Longest Valid Parentheses

## Prob

Given a string containing just the characters '(' and ')', find the length of the longest valid (well- formed) parentheses substring.
For "(()", the longest valid parentheses substring is "()", which has length = 2.
Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

## Code

```cpp
int LongestParentheses(const std::string& str){

	std::unordered_map<char, char> mymap = {{')','('}, {']','['},{'}','{'}};

	std::stack<char> mstack;

	int len = 0;
	

	for(auto c : str){
	    std::cout << c<<std::endl;
		if (c == '(' || c =='[' || c =='{'){
			mstack.push(c);
		}else{
			if (mstack.empty()) continue;
			if (mstack.top() == mymap[c]){
			    mstack.pop();
			    len += 2;
			}
		}
		std::cout << len<<std::endl;
	}

	return len;
}
```