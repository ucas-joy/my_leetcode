/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Subscribe to see which companies asked this question
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
	 vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		 vector<Interval>res;
		 if (intervals.size() == 0) {
			 res.push_back(newInterval);
			 return res;
		 }
		 int tmp_end = newInterval.end;
		 Interval tmp_interval = newInterval;
		 int i;
		 for ( i = 0; i < intervals.size(); ++i) {
			 if (tmp_interval.end < intervals[i].start)
			 {
				 res.push_back(tmp_interval);
				 break;
			 }
			 if (tmp_interval.start <= intervals[i].end) {
				 tmp_interval.start = min(tmp_interval.start, intervals[i].start);
				 tmp_interval.end = max(tmp_interval.end, intervals[i].end);
			 }
			 else {
				 res.push_back(intervals[i]);
			 }
			/* if (i + 1 < intervals.size() && tmp_end < intervals[i + 1].start)
			 {
				 res.push_back(tmp_interval);
				 break;
			 }*/
		 }
		 if (i  == intervals.size())
		 {
			 res.push_back(tmp_interval);
		 }
		 
		 while (i < intervals.size())
		 {
			 res.push_back(intervals[i]);
			 i++;
		 }
		 return res;
	 }
 };
	int main()
	{
		// [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
//[1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
		//vector<Interval>res = { {1,2},{3,5},{6,7},{8,10},{12,16} };
		vector<Interval>res = { {1,3},{6,9} };
		//vector<Interval>res = { {1,5 }};
		//vector<Interval>res = { {1,5} };
		Interval t = Interval(2,5);
		Solution sol;
		vector<Interval> t1 = sol.insert(res, t);

		return 0;
	}