# Median of Two Sorted Arrays

## Desciption

There are two **sorted** arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log(m + n)).

## Solution

This question is equivalent to `find k-th max number`

1. Naive: Do inseration
2. Binary search: find k/2-th in A and B respetively, remove the part has been verified

Termination:
- if m = 0, return B[k-1]
- if n = 0, return A[k-1]
- if A[k/2-1] == B[k/2-1], return either one


```cpp
int find_kth(int A[], int B[], int m, int n, int k){
	//always assume that m is equal or smaller than n
    if (m > n) return find_kth(B, A, n, m, k);

	if (m == 0) return B[k-1];

	int ia = std::min(k / 2, m) - 1, ib = k - ia;
	if (A[ia] == B[ib]) return A[ia];
	else if(A[ia] < B[ib]){
		return find_kth(A+ia, B, m-ia, n, k-ia);
	}else return find_kth(A, B+ib, m, n-ib, k-ib);
}

double findMedianSortedArrays(int A[], int B[], int m, int n, int k) {
          int total = m + n;
          if (total & 0x1)
              return find_kth(A, B, m, n, total / 2 + 1);
          else
              return (find_kth(A, B, m, n, total / 2)
                      + find_kth(A, B, m, n, total / 2 + 1)) / 2.0;
}
```

