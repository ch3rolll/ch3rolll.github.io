# LRU Cache

## Prob

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

## Solution


## Code
```cpp


class LRUCache{
  private:
	struct CacheNode {
		int key;
		int value;
		CacheNode(int k, int v) :key(k), value(v){}
    };
  public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}
	
	int get(int key) {
		if (cacheMap.find(key) == cacheMap.end()) return -1;

		// Bring the key to the head
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]); 

		// Update the address
		cacheMap[key] = cacheList.begin();
		return cacheMap[key]->value;
	}
    

    void set(int key, int value) {

    	// If not found
		if (cacheMap.find(key) == cacheMap.end()) {

			// If reach the limit
			if (cacheList.size() == capacity) { 
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			// Push to the front
			cacheList.push_front(CacheNode(key, value)); 

			// insert the key
			cacheMap[key] = cacheList.begin();
		} else {

			// Update the value
			cacheMap[key]->value = value;

			// Bring the key to the front
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]); 

			// Update the key
			cacheMap[key] = cacheList.begin();
		} 
	}

  private:
	std::list<CacheNode> cacheList;
	std::unordered_map<int, list<CacheNode>::iterator> cacheMap;
	int capacity;
};
