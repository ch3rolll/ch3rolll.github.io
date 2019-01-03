# 642. Design Search Autocomplete System

## Description
Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#'). For each character they type except '#', you need to return the top 3 historical hot sentences that have prefix the same as the part of sentence already typed. Here are the specific rules:

The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same degree of hot, you need to use ASCII-code order (smaller one appears first).
If less than 3 hot sentences exist, then just return as many as you can.
When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
Your job is to implement the following functions:

## Code

```cpp
struct TrieNode{
	int time;
	unordered_map<char, TrieNode*> next;
	TrieNode():time(0){}
};

TrieNode *root, *cur;

string sentence;

struct Compare{
	bool operator()(pair<string, int>&p1, pair<string, int>& p2){
		return p1.second == p2.second ? p1.first < p2.first ? p1.second > p2.second;
	}
};

priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;


void buildTrie(string s, int t){
	auto p = root;
	for(auto c : s){
		if (!p->next[c]) p->next[c] = new TrieNode();
		p = p->next[c];
	}

	p ->time += t;
}

void dfs(string& s, TrieNode* p){
	if( p->time){
		pq.push({s, p->time});
		while(pq.size() > 3) pq.pop();
	}

	for (auto x:p->next){
		s.push_back(x.first);
		dfs(s, x.second);
		s.pop_back();
	}
}


```