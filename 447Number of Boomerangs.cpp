/*
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the
distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
Subscribe to see which companies asked this question
*/

#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		if (points.size() == 0)
			return 0;
		int time = 0;
		for (int i = 0; i < points.size(); ++i)
		{
			vector<int>dist;
			for (int j = 0; j < points.size(); ++j)
			{
				if (i == j) continue;
				dist.push_back((points[i].first - points[j].first)*(points[i].first - points[j].first) + (points[i].second - points[j].second)*(points[i].second - points[j].second));
			}

			sort(dist.begin(), dist.end());
			
			int cnt = 1;
			for (int i = 0; i < dist.size() - 1; ++i) {
				if (dist[i] == dist[i + 1]) {
					cnt++;
				}
				else
				{
					time += cnt * (cnt - 1);
					cnt = 1;
				}
			}
			time += cnt *(cnt - 1);
		}
		return time; 
		
	}
};
int main()
{
	//vector<pair<int, int>> a = { {0,0},{1,0},{2,0} };
	//[[5,5],[4,7],[6,5],[6,9],[3,7],[4,5],[2,5],[4,4],[3,0]]
	vector<pair<int, int>>a = { {5,5},{4,7},{6,5},{6,9},{3,7},{4,5},{2,5},{4,4},{3,0} };
	Solution sol;
	int t = sol.numberOfBoomerangs(a);
	cout << t << endl;
	return 0;

}