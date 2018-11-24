# Simplify Path

## Prob
> Given an absolute path for a file (Unix-style), simplify it.
For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Corner Cases:
• Didyouconsiderthecasewherepath="/../"?Inthiscase,youshouldreturn"/".
• Anothercornercaseisthepathmightcontainmultipleslashes'/'together,suchas"/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

## Code

```cpp
std::string SimplifyPath(const string& path){
	std::vector<std::string> dirs;

	for(auto i = path.begin(); i != path.end(); ){
		++i;

		auto j = std::find(i, path.end(), '/');
		auto dir = std::string(i, j);

		if(!dir.empty() && dir != "."){
			if(dir == ".."){
				if(!dirs.empty()) dirs.pop_back();
				else dirs.push_back(dir);
			}
		}

		i = j;
	}

	stringstream out;
	if(dirs.empty()) out<<"/";
	else{
		for(auto dir:dirs)
			out <<"/"<<dir;
	}

	return out.str();
}
```