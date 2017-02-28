/*
Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.
insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The probability of each element being returned is 
linearly related to the number of same value the collection contains.
Example:

// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;
class RandomizedCollection {
public:
	unordered_map<int, vector<int>>mp;
	vector<pair<int,int>>nums;
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}
	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		auto result =  mp.find(val) == mp.end();
		mp[val].push_back(nums.size());
		nums.push_back(make_pair(val, nums.size() - 1));
		return result;
	}
	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		if (mp.find(val) == mp.end()) return false;
		auto last = nums.back();
		if (last.first != val)
		{
			mp[last.first][last.second] = mp[val].back();
			nums[mp[val].back()] = last;
		}
		mp[val].pop_back();
		if (mp[val].size() == 0)
			mp.erase(val);
		nums.pop_back();
		return true;
    }
	/** Get a random element from the collection. */
	int getRandom() {
		return nums[rand() % nums.size()].first;
	}
};
int main()
{
	RandomizedCollection t;
	cout << t.insert(1) << endl; //1
	cout << t.insert(1) << endl; // 1 1 
	cout << t.insert(2) << endl; // 1 1 2 
	cout << t.insert(1) << endl; // 1 1 2 1 
	cout << t.insert(2) << endl; // 1 1 2 1 2 
	cout << t.insert(2) << endl;// 1 1 2 1 2 2 
	cout << t.remove(1) << endl; // 1 2 1 2 2 
	cout << t.remove(2) << endl; // 1 1 2 2 
	cout << t.remove(2) << endl;// 1 1 2 
	cout << t.remove(2) << endl; // 1 1 
	cout << t.getRandom() << endl;
	cout << t.getRandom() << endl;
	cout << t.getRandom() << endl;
	cout << t.getRandom() << endl;
	cout << t.getRandom() << endl;
	cout << t.getRandom() << endl;
	cout << t.getRandom() << endl;
	cout << t.getRandom() << endl;
	cout << t.getRandom() << endl;
	cout << t.getRandom() << endl;
	return 0;

}

/*
Input:
["RandomizedCollection","insert","insert","insert","insert","insert","insert","remove","remove","remove","remove"
,"getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
[[],[1],[1],[2],[1],[2],[2],[1],[2],[2],[2],[],[],[],[],[],[],[],[],[],[]]
Output:
[null,true,false,true,false,false,false,true,true,true,true,2,1,2,1,1,2,2,2,1,1]
Expected:
[null,true,false,true,false,false,false,true,true,true,true,1,1,1,1,1,1,1,1,1,1]
*/
/*
["RandomizedCollection","insert","insert","insert","insert","insert","insert","remove","remove","remove","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
[[],[1],[1],[2],[1],[2],[2],[1],[2],[2],[2],[],[],[],[],[],[],[],[],[],[]]
Output:
[null,true,false,true,false,false,false,true,true,true,true,1,2,1,2,1,2,2,1,2,1]
Expected:
[null,true,false,true,false,false,false,true,true,true,true,1,1,1,1,1,1,1,1,1,1]
*/

/*
if (mp.find(val) == mp.end()) return false;
auto last = nums.back();
if (last.first != val){
mp[last.first][last.second] = mp[val].back();
nums[mp[val].back()] = last;
}
mp[val].pop_back();
if (mp[val].empty()) mp.erase(val);
nums.pop_back();

*/