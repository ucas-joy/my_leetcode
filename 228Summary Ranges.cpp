/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string>result;
		if (nums.size() == 0)
			return  result;
		int begin, end;
		begin = end = nums[0];
		for (int i = 1; i < nums.size(); ++i){
			if (end == nums[i] || nums[i] == end + 1){
				end = nums[i];
			}else{
				result.push_back(format(begin, end));
				begin = end = nums[i];
			}
		}
		result.push_back(format(begin, end));
		return result;
	}
	string format(int begin, int end){
		char buf[32];
		if (begin == end){
			sprintf(buf, "%d", end);
		}
		else{
			sprintf(buf, "%d->%d", begin, end);
		}
		return string(buf);
	}
};

int main()
{
	int a[6] = { 0,1,2,4,5,7 };
	vector<int>b(a, a + 6);
	Solution sol;
	vector<string> res = sol.summaryRanges(b);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	return 0;
}