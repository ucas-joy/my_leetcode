/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	int cal(char ch, int a, int b) {
		int sum;
		switch (ch) {
		case '+': sum = b + a; break;
		case '-': sum = b - a; break;
		case '*': sum = b * a; break;
		case '/': sum =b / a; break;
		}
		return sum;
	}
	int op_priority(char ch) {
		int priority;
		switch (ch) {
		case'+':priority = 0; break;
		case'-':priority = 0; break;
		case'*':priority = 1; break;
		case'/':priority = 1; break;
		default:break;
		}
		return priority;
	}
	bool is_ops(char ch){
		return (ch == '-' || ch == '+' || ch == '/' || ch == '*');
	}
	int calculate(string s) {
		s.erase(remove(s.begin(), s.end(), ' '), s.end());
		stack<int>nums;
		stack<int>nums1;
		stack<char>ops;
		stack<char>tmp;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] >= '0' && s[i] <= '9'){
				string value = "";
				while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
					value += s[i++];
				}
				nums.push(stoi(value));
				while(!ops.empty() && op_priority(ops.top()) == 1){
					int a = nums.top();
					nums.pop();
					int b = nums.top();
					nums.pop();
					nums.push(cal(ops.top(), a, b));
					ops.pop();
				}
			}
			if (is_ops(s[i]))
			{
				ops.push(s[i]);
			}
			
		}
		while (!ops.empty()){
			tmp.push(ops.top());
			ops.pop();
		}
		while (!nums.empty()){
			nums1.push(nums.top());
			nums.pop();
		}
		while (!tmp.empty()){
			int a = nums1.top();
			nums1.pop();
			int b = nums1.top();
			nums1.pop();
			nums1.push(cal(tmp.top(), b, a));
			tmp.pop();
		}
		return nums1.top();
	}
};

int main()
{
	//string s = "     3+2*2";
	//string s = "1-1+1";
	//string s = "0-2147483647";
	string s = "1+1+1-2-3-4-5";
	Solution sol;
	int rest = sol.calculate(s);
	cout << rest << endl;
	return 0;
}