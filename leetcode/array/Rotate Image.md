# Rotate Image

## Prob

You are given an n × n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).
Follow up: Could you do this in-place?


## Thought

Flip diagonally and horizontally.

1. Diagonally
i, j --> m-j, n-i


## code

```cpp
#include <algorithm>
#include <vector>

void RotateImage(std::vector<std::vector<int>>& image){
	const int n = image.size();

	if (n < 2) return;

	// Flip Diagonally
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n-i; j++){
			std::swap(image[i][j], image[n - 1 - j][n - 1 - i]);
		}
	}

	// Flip Horizontally
	for (int i = 0; i < n/2; i++){
		for (int j = 0; j < n ; j++){
			std::swap(image[i][j], image[n - 1 - i][j]);		
		}
	}
}

```
