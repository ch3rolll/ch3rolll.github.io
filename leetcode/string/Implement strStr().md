# Implement strStr()

## Prob
Implement strStr().
Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.


## Code

```cpp
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (haystack.size() < needle.size()) return -1;
        
        for (auto i = 0; i < haystack.size() - needle.size() + 1; i ++)
        {   
            if (haystack[i] == needle[0]){
                if (haystack.substr(i, needle.size()) == needle) return i;
            }

        }
        return -1;
    }
```