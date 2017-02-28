/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<ctype.h>
using namespace std;
class Solution {
public:
	int cal(char ch, int a, int b) {
		int sum;
		switch (ch) {
		case '+': sum = b + a; break;
		case '-': sum = b - a; break;
		case '*': sum = b * a; break;
		case '/': sum = b / a; break;
		}
		return sum;
	}
	int evalRPN(vector<string>& tokens) {
		if (tokens.size() == 0)
			return 0;
		stack<int>nums;
		for (int i = 0; i < tokens.size(); ++i){
			string tmp = tokens[i];
			int j = 0;
			int sign = 1;
			if (tmp[j] == '-' && tmp.length() > 1){
				sign = -1;
				j++;
			}
			if (tmp[j] == '+' && tmp.length() > 1){
				j++;
			}
			if(tmp[j] >= '0' && tmp[j] <= '9'){
				string result;
				while (j < tmp.size() && (tmp[j] >= '0'&& tmp[j] <= '9')) {
					result += tmp[j];
					++j;
				}
				int num = stoi(result)*sign;
				nums.push(num);
			}
			if (tmp[j] == '+' || tmp[j] == '-' || tmp[j] == '/' || tmp[j] == '*'){
				int a = nums.top();
				nums.pop();
				int b = nums.top();
				nums.pop();
				nums.push(cal(tmp[j], a, b));
			}
		}
		return nums.top();
	}
};

int main()
{
	//["2", "1", "+", "3", "*"]
	//string a = "2";
	//string b = "1";
	//string c = "+";
	//string d = "3";
	//string e = "*";
	string a = "3";
	string b = "-4";
	string c = "+";
	vector<string> tmp;
	tmp.push_back(a);
	tmp.push_back(b);
	tmp.push_back(c);

	int result;
	Solution sol;
	result = sol.evalRPN(tmp);
	cout << result << endl;
	return 0;
}