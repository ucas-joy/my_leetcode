/*
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses
could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius 
standard of heaters.

Note:
Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
Subscribe to see which companies asked this question

Show Tags

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		if (heaters.size() == 1){
			return max(abs(heaters[0] - houses[0]), abs(heaters[0] - houses[houses.size() - 1]));
		}
		sort(heaters.begin(), heaters.end());
		int minR = 0;
		for (int i = 0; i < houses.size(); ++i){
			auto larger = lower_bound(heaters.begin(), heaters.end(), houses[i]);
			int curR = INT_MAX;
			if (larger != heaters.end())
				curR = *larger - houses[i];
			if (larger != heaters.begin()){
				auto smaller = larger - 1;
				curR = min(curR, houses[i] - *smaller);
			}
			minR = max(minR, curR);
		}
		return minR;
	}
};
int main475()
{
	vector<int> houses = { 1,2,3,4 };
	vector<int>heater = { 1,4 };
	Solution sol;
	int t = sol.findRadius(houses, heater);
	cout << t << endl;
	return 0;
}