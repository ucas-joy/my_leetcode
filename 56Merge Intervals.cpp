/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
	static bool cmp(Interval &one, Interval &two){
		return one.start < two.start;
	}
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval>res;
		if (intervals.size() == 0) {
			return res;
		}
		if (intervals.size() == 1){
			res.push_back(intervals[0]);
			return res;
		}
		sort(intervals.begin(), intervals.end(), cmp);
		Interval tmp_interval = intervals[0];
		for (int i = 1; i < intervals.size(); ++i){
			if (tmp_interval.end >= intervals[i].start)
			{
				tmp_interval.start = min(tmp_interval.start, intervals[i].start);
				tmp_interval.end = max(tmp_interval.end, intervals[i].end);
			}
			else{
				res.push_back(tmp_interval);
				tmp_interval = intervals[i];
			}
		}
		res.push_back(tmp_interval);
		return res;
	}
};
int main()
{
	//Given [1,3],[2,6],[8,10],[15,18],
//	return[1, 6], [8, 10], [15, 18].
	//vector<Interval>a = { {1,3},{2,6},{8,10},{15,18} };
	vector<Interval>a = { {1,4},{4,5} };
	Solution sol;
	vector<Interval>b = sol.merge(a);
	return 0;
}