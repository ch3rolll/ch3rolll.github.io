# Permuatation with Duplicates

## Solution
1. for every element, find the (n-1) permutation
2. Skip the duplicates

## Code

```cpp
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> Permutation(const std::vector<int>& num){
	std::vector<std::vector<int>> res;
	std::vector<int> curr;
	std::vector<bool> isVisited(num.size(), false); //using this bool type array to check whether or not the elments has been visited
    DFS(res,curr,isVisited,num);
    return res;
} 

void DFS(const std::vector<std::vector<int>>& res, const std::vector<int>& num, std::vector<int>& curr, std::vector<bool>& isVisited){
	if(curr.size() == num.size()){
	    res.push_back(curr);
	    return;
    }

    for(int i = 0; i < num.size(); ++i){
        if(isVisited[i] == false){
            isVisited[i] = true;
            curr.push_back(num[i]);
            DFS(res,curr,isVisited,num);
            isVisited[i] = false;
            curr.pop_back();
        }
    }
}

```

## For with Duplicates

```cpp

#include <algorithm>
#include <vector>


std::vector<std::vector<int>> PermutationWDuplicates(const std::vector<int>& num){
	std::vector<std::vector<int>> ret;
	std::vector<int> curr;

	std::sort(num.begin(),num.end());

	std::vector<bool> visited(num.size(), false);

	DFS(ret, num, curr, visited);

	return ret;
}

void DFS(std::vector<std::vector<int>>& ret, const std::vector<int>& num, std::vector<int>& curr, std::vector<bool>& visited){
	if (curr.size() == num.size()) ret.push_back(curr);

	const int n = num.size();

	for (auto i = 0; i < n; i++){
		if(visited[i] == false){
			visited[i] = true;
			curr.push_back(num[i]);
			DFS(ret, num, curr, visited);
			visited[i] = false;
			curr.pop_back();
			**while (i < n && num[i] == num[i-1]) i++;**
		} 
	}
}

