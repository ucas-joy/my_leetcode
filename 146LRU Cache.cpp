/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, 
it should invalidate the least recently used item before inserting a new item.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<list>
#include<map>
#include<unordered_map>
using namespace std;
class LRUCache {
public:
	LRUCache(int capacity) :size(capacity) {}

	int get(int key) {
		auto it = hash.find(key);
		if (it == hash.end()) return -1;
		cache.splice(cache.begin(), cache, it->second);
		return it->second->second;
	}

	void set(int key, int value) {
		auto it = hash.find(key);
		if (it != hash.end())
		{
			it->second->second = value;
			return cache.splice(cache.begin(), cache, it->second);
		}
		cache.insert(cache.begin(), make_pair(key, value));
		hash[key] = cache.begin();
		if (cache.size() > size)
		{
			hash.erase(cache.back().first);
			cache.pop_back();
		}
	}
private:
	unordered_map<int, list<pair<int, int>>::iterator> hash;
	list<pair<int, int>> cache;
	int size;
};