/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k.
For example, there won't be input like 3a or 2[4].

Examples:
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	string decodeString(string s) {
		string res = "";
		if (s.length() == 0)
			return res;
		string k = "";
		stack<char>st;
		stack<int>num;
		int len = s.length() ;
		int i = 0;
		int numleft = 0;
		bool flag = false;
		//string tmp_num = "";
		char s1 = NULL;
		while (i < len){
			string tmp = "";
			string tmp_num = "";		
			while (numleft == 0 && s[i] >= 'a' && s[i] <= 'z'){
				res = res + s[i];
				i++;
			}
			while (s[i] >= '0' && s[i] <= '9'){
				tmp_num = tmp_num + s[i];
				i++;
				flag = true;
			}
			if (flag == true) {
				num.push(atoi(tmp_num.c_str()));
			}
		    if (s[i] == '['){
				numleft++;
				st.push(s[i]);
			}
			else if (s[i] >= 'a' && s[i] <= 'z'){
				st.push(s[i]);
			}
			else if(s[i] == ']'){
				while (st.top() != '[') {
	                s1 = st.top();
					tmp = s1 + tmp;
					st.pop();
				}
				st.pop();
				numleft--;
				if (numleft == 0){
					int time = num.top();
					num.pop();
					while (time--) {
						res = res + tmp;
					}
				}
				else{
					int time = num.top();
					num.pop();
					
					while (time--) {
						for(int v = 0 ; v < tmp.length();++v)
							st.push(tmp[v]);
					}
				}
			}	
			i++;
			flag = false;
		}
		string tmp2 = "";
		while (!st.empty()){
			char s2 = st.top();
			tmp2 = s2 + tmp2;
			st.pop();
		}
		if (tmp2.length() > 0){
			res = res + tmp2;
		}
		return res;
	}
};

int main()
{
	//string s = "3[a2[c]]";//return "accaccacc".
	//string s = "2[abc]3[cd]ef"; //return "abcabccdcdcdef".
	//string s = "100[leetcode]"; 
	//string s = "sd2[f2[e]g]i";  //"sdfeegfeegi"
	string s = "2[2[2[b]]]"; //"bbbbbbbb"
	Solution sol;
	string res = sol.decodeString(s);
	cout << res << endl;
	return 0;
}