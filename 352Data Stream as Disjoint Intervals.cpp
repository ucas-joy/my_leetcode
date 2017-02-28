/*
Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?

Credits:
Special thanks to @yunhong for adding this problem and creating most of the test cases.

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

class SummaryRanges {
public:
	/** Initialize your data structure here. */
	SummaryRanges() {

	}
	static bool cmp(Interval &a, Interval &b)
	{
		return a.start < b.start;
	}
	void addNum(int val) {
		Interval tmp(val, val);
		vector<Interval>res;
		sort(v.begin(), v.end(), cmp);
		int i;
		for(i = 0 ; i < v.size(); ++i){
			if (tmp.end +1< v[i].start){
				res.push_back(v[i]);
				
			}else if(tmp.end + 1 == v[i].start){
				tmp.end = v[i].end;
			}else if(tmp.start - 1 == v[i].end){
				tmp.start = v[i].start;
			}else if(tmp.start > v[i].end + 1){
				res.push_back(v[i]);
			}
			else{
				tmp.start = min(tmp.start, v[i].start);
				tmp.end = max(tmp.end, v[i].end);
			}
		}
		res.push_back(tmp);
		sort(res.begin(), res.end(), cmp);
		v = res;
	}
	vector<Interval> getIntervals() {
		return v;
	}
private:
	vector<Interval>v;
};
int main()
{
	SummaryRanges t;
	t.addNum(1);
	t.addNum(3);
	t.addNum(2);
	t.addNum(7);
	t.addNum(6);
	vector<Interval> s = t.getIntervals();
	cout << endl;
	return 0;
}