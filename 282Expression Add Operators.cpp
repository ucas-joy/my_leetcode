/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between 
the digits so they evaluate to the target value.

Examples:
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
Credits:
Special thanks to @davidtan1890 for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems


*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	vector<string> addOperators(string num, int target) {
		vector<string>res;
		string temp;
		helper(res, num, temp, target, 0, 0, 0);
		return res;
	}
	void helper(vector<string>&res, const string &nums,string temp,const int target , int start, long long pre_val, long long cur_res){
		if (start == nums.size()) {
			if (cur_res == target) {
				res.push_back(temp);
			}
			return;
		}
		for (int i = 1; i + start <= nums.size(); ++i) {
			string num = nums.substr(start, i);
			if (num.size() > 1 && num[0] == '0') {
				return;
			}
			long long cur = stoll(num);
			if (start == 0) {
				helper(res, nums, num, target, i, cur, cur);
			}else{
				helper(res, nums, temp + "+" + num, target, start + i, cur, cur_res + cur);
				helper(res, nums, temp + "-" + num, target, start + i, -cur, cur_res - cur);
				helper(res, nums, temp + "*" + num, target, start + i, pre_val*cur, cur_res - pre_val + pre_val*cur);
			}
		}
	}
};
int main282()
{
	/*
	"123", 6 -> ["1+2+3", "1*2*3"]
	"232", 8 -> ["2*3+2", "2+3*2"]
	"105", 5 -> ["1*0+5","10-5"]
	"00", 0 -> ["0+0", "0-0", "0*0"]
	*/
	string num = "123";
	Solution sol;
	vector<string>s = sol.addOperators(num, 6);
	cout << endl;
	return 0;
}