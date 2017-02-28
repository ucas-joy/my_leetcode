/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string>result;
		generate(result, "", n, n);
		return result;
	}
	void generate(vector<string>&v, string s, int left, int right)
	{
		if (left == 0 && right == 0)
			v.push_back(s);
		if (left > 0){
			generate(v, s + "(", left-1, right);
		}
		if (right > 0 && left < right){
			generate(v, s + ")", left, right-1 );
		}		
	}
};
int main()
{
	vector<string>s;
	Solution sol;
	s = sol.generateParenthesis(3);
	int i = 0;
	while (i < s.size())
	{
		cout << s[i] << endl;
		i++;
	}
	return 0;

}