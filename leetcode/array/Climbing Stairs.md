# Climbing Stairs

## Prob

You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

## Solution

Fabonacci: f(n) = f(n-1) + f(n-2)

f(0) = 0, f(1) = 1;

## Code

```cpp

int Stairs(cosnt int n){
	int pre = 0, curr = 1;
	for (int i = 2; i <= n; i++){
		int temp = curr;
		curr += pre;
		pre = curr;
	}

	return curr;
}

```
