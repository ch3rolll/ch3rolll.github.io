# Valid Sudoku

## Prob

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules http://sudoku.com.au/TheRules.aspx .
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

## Solution

1. Check every row, every column and every `3*3` block.
2. Use bool[9] to check.

## Code

```cpp
#include <algorithm>
#include <vector>

bool Check(char c, bool visited[9]){
	if (c == '.' || !visited[c - '1']) return visited[c - '1'] = true;
	return false;
}

bool IsValidSudoku(std::vecotr<std::vector<char>> s){

	bool visited[9]{false};
	for (int i = 0; i < 9; i++){
		// Check rows
		for(int j = 0; j < 9; j++){
			if (check(s[i][j], visited) == false) return false;
		}

		// Check for columns
		std::fill(visited, visited+ 9, false);

		for(int j = 0; j < 9; j++){
			if (check(s[j][i], visited) == false) return false;
		}
	}

	// Check for small blocks

	for(auto i = 0; i < 3; i++){
		for (auto j = 0; j < 3; j++){

			std::fill(visited, visited+ 9, false);

			for(int r = i * 3; r < i * 3 + 3; r++){
				for (int c = j * 3; c < j*3+3; c++){
					if (check(s[j][i], visited) == false) return false;
				}
			}
		}
	}
	return true;
}

```