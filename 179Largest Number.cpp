/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	static bool cmp(const string s1, const string s2) {
		return (s1 + s2 )> (s2 + s1);
	}
	string largestNumber(vector<int>& nums) {
		if (nums.size() == 0)
			return "";
		vector<string>res(nums.size());
		stringstream tmp;
		for (int i = 0; i < nums.size(); ++i){
			res[i] = to_string(nums[i]);
		}
		sort(res.begin(), res.end(), cmp);
		string result;
		for (int i = 0; i < res.size(); ++i){
			result += res[i];
		}
		string::iterator it;
		for(it = result.begin();it != result.end() && *it == '0';){
			it = result.erase(it);
		}
		if (result.length() == 0)
			result += "0";
		return result;
	}
	
};
int main()
{
	//int a[5] = { 3, 30, 34, 5, 9 };
	int a[4] = { 0,0,0,0 };
	vector<int>b(a, a + 4);
	Solution sol;
	string s = sol.largestNumber(b);
	cout << s << endl;
	return 0;
}