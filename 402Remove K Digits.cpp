/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ¡Ý k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<string>
using namespace std;
/*
class Solution {
public:
	string removeKdigits(string num, const int k) {
		if (num.size() <= k) {
			return "0";
		}
		if (num == "0") {
			return num;
		}
		string res;
		// We always choose to pop out the largest value in the stack.
		int deleted = 0;
		for (int i = 0; i < num.size(); ++i) {
			if (res.empty() && num[i] == '0') {
				// Lead value cannot be 0. So skip to the next value.
				continue;
			}
			if (deleted == k || res.empty() || num[i] >= res.back()) {
				// 3 conditions:
				//   1, We have deleted enough value, so simply insert all remains.
				//   2, No available value right now, in this case num[i] != '0' by default,
				//      so insert it.
				//   3, The next value is larger, so insert it as it should have a higher priority 
				//      to delete the the current top one in stack.
				res.push_back(num[i]);
				continue;
			}
			// Pop all previous string out.
			// We meet a value smaller than the current stack top, so delete the current stack top.
			res.pop_back();
			--i;
			++deleted;
		}
		// res: first element is not 0, but its length maybe longer or shorter as deleted may not equal to k.
		res = res.substr(0, num.size() - k);
		return res.empty() ? "0" : res;
	}
};*/

class Solution {
public:
	string removeKdigits(string num, const int k) {
		if (num.length() <= k)
			return "0";
		if (k == 0)
			return num;
		string res;
		int deleted = 0;
		for (int i = 0; i < num.length(); ++i) {
			if (res.empty() && num[i] == '0')
				continue;
			if (deleted == 3 || res.empty() || num[i] > res.back()) {
				res.push_back(num[i]);
				continue;
			}
			res.pop_back();
			--i;
			++deleted;
		}
		res = res.substr(0, num.size() - k);
		return res.empty() ? "0" : res;
	}
};
int main()
{
	string num = "1432219";  // "1219"
	int k = 3;
	Solution sol;
	string tmp = sol.removeKdigits(num, 3);
	cout << tmp << endl;
	return 0;
}