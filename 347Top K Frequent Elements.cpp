/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<map>
#include<queue>
#include <unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> map;
		int len = nums.size();
		for (int i = 0; i < len; ++i)
		{
			map[nums[i]]++;
		}
		vector<int>res;
		priority_queue<pair<int, int>> mq;
		unordered_map<int, int>::iterator it;
		for (it = map.begin(); it != map.end(); ++it){
			mq.push(make_pair(it->second, it->first));
		}
		while (k > 0){
			res.push_back(mq.top().second);
			mq.pop();
			k--;
		}
		return res;
	}
};

int main347()
{
	int a[6] = { 1,1,1,2,2,3 };
	vector<int>b(a, a + 6);
	vector<int>res;
	Solution sol;
	res = sol.topKFrequent(b, 2);
	int i = 0; 
	for (i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	return 0;
}