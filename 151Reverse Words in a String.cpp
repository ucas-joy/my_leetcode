/*Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update(2015 - 02 - 12) :
	For C programmers : Try to solve it in - place in O(1) space.

	click to show clarification.

	Subscribe to see which companies asked this question

	*/

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	void reverseWords(string &s) {
		if (s.length() == 0)
			return;
		string tmp;
		int len = s.length();
		int j = 0;
		while (j < len && s[j] == ' '){
			j++;
		}
		while (len > j && s[len-1] == ' ')
		{
			len--;
		}
		if (j == len){
			s = "";
			return;
		}
		stack<string>st;
		while (j <len){
			if (s[j] != ' ')
				tmp += s[j];
			else if((j < len-1)&&(s[j] == ' ' && s[j+1]!= ' ')){
					st.push(tmp);
					tmp ="";
			}
			
			j++;
		}
		while (!st.empty()&&tmp.size() != 0){
			tmp =tmp +' '+st.top();
			st.pop();
		}
		s = tmp;
		return;
	}
};

int main()
{
	string	s = "   a   b ";
	Solution sol;
	sol.reverseWords(s);
	cout << s << endl;
	cout << s.length() << endl;
	return 0;
}