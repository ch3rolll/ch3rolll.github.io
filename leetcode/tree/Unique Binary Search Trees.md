# Unique Binary Search Trees


## Prob
Given n, how many structurally unique BST’s (binary search trees) that store values 1...n? For example, Given n = 3, there are a total of 5 unique BST’s.

## Code

```
f(i) = sum(k=1 --> i) f(k-1)*f(i-k)

```

```cpp
int UniqueBST(int n){
	std::vector<int> f(n+1, 0);

	f[0] = 1, f[1] = 1;

	for(auto i = 2; i <= n; i++){
		for(auto k = 1; k <= i; k++)
			f[i] += f[k-1] * f[i-k];
	}

	return f[n];
}

```


