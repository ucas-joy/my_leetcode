/*
There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end 
coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and 
end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot 
at x if xstart ¡Ü x ¡Ü xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely.
The problem is to find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 
(bursting the other two balloons).
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	static bool cmp(pair<int, int>&one, pair<int, int>&two)
	{
		return one.second < two.second;
	}
	int findMinArrowShots(vector<pair<int, int>>& points) {
		if (points.size() == 0)
			return 0;
		if (points.size() == 1)
			return 1;
		sort(points.begin(), points.end(), cmp);
		int tmp_start = points[0].first;
		int tmp_last = points[0].second;
		int count = 0;
		bool flag = false;
		for (int i = 1; i < points.size(); ++i)
		{
			if (tmp_last > points[i].first){
				tmp_start = max(tmp_start, points[i].first);
				tmp_last = min(tmp_last, points[i].second);
			}
			else  if (tmp_last == points[i].first){
				if (flag == false){
					tmp_last = points[i].second;
					flag = true;
				}
				else{
					tmp_start = points[i].first;
					tmp_last = points[i].second;
					count++;
					flag = false;
				}
			}
			else
			{
				count++;
				tmp_start = points[i].first;
				tmp_last = points[i].second;
			}
		}
		return count+1;
	}
};
int main()
{
	vector<pair<int, int>> res = { {9,12}, {1,10}, {4,11}, {8,12}, {3,9}, {6,9},{6,7}};
	//[[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
	//vector<pair<int,int>> res = { {1,2},{2,3},{3,4},{4,5} };
	Solution sol;
	int t = sol.findMinArrowShots(res);
	cout << t << endl;
	return 0;
}
