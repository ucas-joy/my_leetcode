/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
*/
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool level(char c1, char c2) {
		if (c2 == '(' || c2 == ')')return false;
		else return true;
	}
	int calculate(string s) {
		stack<int>nums;
		stack<char>exp;
		int i = 0;
		int len = s.length();
		while (i < len){
			if (s[i] == '('){
				exp.push(s[i]);
			}
			if (s[i] >= '0' && s[i] <= '9'){
				string value = "";
				while(i < len &&s[i] >= '0' && s[i] <= '9'){
					value += s[i++];
				}
				nums.push(stoi(value));			
			}
		   if (s[i] == '+' || s[i] == '-'){
				while (!exp.empty() && level(s[i], exp.top()))
				{
					int a = nums.top();
					nums.pop();
					int b = nums.top();
					nums.pop();
					exp.top() == '+' ? nums.push(a + b) : nums.push(b - a);
					exp.pop();
				}
				exp.push(s[i]);
			}
			 if (s[i] == ')'){
				while (exp.top() != '('){
					int left = nums.top();
					nums.pop();
					int right = nums.top();
					nums.pop();
					char exps = exp.top();
					exp.pop();
					exps == '+' ? nums.push(left + right) : nums.push(right - left);
					}
				exp.pop();
				}
				
				i++;
			}
			
		while (!exp.empty()){
			int left = nums.top();
			nums.pop();
			int right = nums.top();
			nums.pop();
			char exps = exp.top();
			exp.pop();
			exps == '+' ? nums.push(left + right) : nums.push(right - left);
		}
		return nums.top();
		
	}
		/*	bool level(char c1, char c2) {
				if (c2 == '(' || c2 == ')')return false;
				else return true;
			}
			int calculate(char ch, int a, int b) {
				if (ch == '+')return b + a;
				else return b - a;
			}
			int calculate(string s) {
				s.erase(remove(s.begin(), s.end(), ' '), s.end());
				if (s.length() == 0)return 0;
				if (s.length() == 1)return s[0] - '0';
				stack<int>val;
				stack<char>op;

				for (int i = 0; i < s.length(); i++) {

					if (s[i] <= '9' && s[i] >= '0') {
						string value = "";
						while (i < s.length() && s[i] >= '0' && s[i] <= '9')value += s[i++];
						val.push(stoi(value));
					}
					if (s[i] == '(')op.push('(');
					if (s[i] == ')') {
						while (op.top() != '(') {
							int a = val.top(); val.pop();
							int b = val.top(); val.pop();
							val.push(calculate(op.top(), a, b));
							op.pop();
						}
						op.pop();
					}
					if (s[i] == '-' || s[i] == '+') {

						while (!op.empty() && level(s[i], op.top())) {
							int a = val.top();
							val.pop();
							int b = val.top();
							val.pop();
							val.push(calculate(op.top(), a, b));
							op.pop();
						}

						op.push(s[i]);
					}
				}
				while (!op.empty()) {
					int a = val.top();
					val.pop();
					int b = val.top();
					val.pop();
					val.push(calculate(op.top(), a, b));
					op.pop();
				}
				return val.top();

			}
		*/
};

int main224()
{
	//string s = "(1+(4+5+2)-3)+(6+8)";
//	string s = "2147483647";
//	string s = "(1)";
	string s = "1-11";
	int result;
	Solution sol;
	result = sol.calculate(s);
	cout << result << endl;
	return 0;
}