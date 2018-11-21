# Set Matrix Zeroes

## Prob

Given a m × n matrix, if an element is 0, set its entire row and column to 0. Do it in place. Follow up: Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution? 

## Solution
1. Scan every element, record if the row and column contain zeros. --> O(m+n) Space

2. Use the first row and column to record.


## Code

```cpp
#include <vector>
#include <algorithm> // For STL std:fill

void SetZeros(std::vector<std::vector<int>>& vec){

	bool row = false, column = false;

	for (int i = 0; i < vec.size(); i++){
		if (vec[i][0] == 0){
			column = true;
			break;
		}
	}

	for (int j = 0; j < vec[0].size(); j++){
		if (vec[0][j] == 0){
			row = true;
			break;
		}
	}

	for(int i = 0; i < vec.size(); i++){
		for(int j = 0; j < vec[0].size(); j++){
			if (vec[i][j] == 0){
				vec[0][j] = 0;
				vec[i][0] = 0;
			}
		}
	}

	// Check for rows
	for(int i = 0; i < vec.size(); i++){
		if (vec[i][0] == 0){
			std::fill(&vec[i][0], &vec[i][0]+n, 0);
		}
	}

	// Check for columns
	for(int i = 0; i < vec.size(); i++){
		for(int j = 0; j < vec[0].size(); j++){
			if (vec[0][j] == 0){
				vec[i][j] = 0;
			}
		}
	}

	if(column){
		for (int i = 0; i < vec.size(); i++){
			vec[i][0] = 0;
		}
	}

	if(row){
		for (int j = 0; j < vec[0].size(); j++){
			vec[0][j] = 0;
		}
	}
}

```
