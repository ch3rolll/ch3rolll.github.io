# Valid Number

## Prob

Validate if a given string is numeric.
Some examples:
  "0" => true
  " 0.1 " => true
  "abc" => false
  "1 a" => false
  "2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

## Code
```cpp
bool isNumber (char const* s) {
	char* endptr;
	std::strtod (s, &endptr);
	if (endptr == s) return false;
	for (; *endptr; ++endptr)
		if (!std::isspace (*endptr)) return false;
	return true;
}
```