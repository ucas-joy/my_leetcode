/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), 
where h is the height of the person and k is the number of people in front of this person who have a height 
greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		if (people.size() == 0)
			return{};
		sort(people.begin(), people.end(), cmp);
		vector<pair<int, int>> ret;
		int n = people.size();
		for (int i = 0; i < n; i++)
		{
			ret.insert(ret.begin() + people[i].second, people[i]);
		}
		return ret;

	}
	static bool cmp(pair<int, int>p1, pair<int, int>p2)
	{
		return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
	}
};
int main()
{//[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
	vector<pair<int, int>>ret,res;
	ret.push_back(make_pair(7,0));
	ret.push_back(make_pair(4,4));
	ret.push_back(make_pair(7,1));
	ret.push_back(make_pair(5,0));
	ret.push_back(make_pair(6,1));
	ret.push_back(make_pair(5,2));
	Solution sol;
	res = sol.reconstructQueue(ret);
	return 0;
}