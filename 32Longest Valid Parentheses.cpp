/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

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
	int longestValidParentheses(string s) {
		vector<bool>a(s.length(), false);
		stack<int>st;
		for (int i = 0; i < s.length(); ++i){
			if(s[i] == '('){
				st.push(i);
			}else if(s[i] == ')' && !st.empty()){
				a[i] = true;
				a[st.top()] = true;
				st.pop();
			}
		}
		int cur_len = 0; 
		int max_len = 0;
		for (int i = 0; i < s.length(); ++i){
			if (a[i]) ++cur_len;
			else cur_len = 0;
			max_len = max(cur_len, max_len);
		}
		return max_len;
	}
};
int main32()
{
	string s = ")()())";
	Solution sol;
	int t = sol.longestValidParentheses(s);
	cout << t << endl;
	return 0;
}