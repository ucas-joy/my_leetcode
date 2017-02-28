/*Remove the minimum number of invalid parentheses in order to make the input string valid.Return all possible results.

Note: The input string may contain letters other than the parentheses(and).

	Examples :
	"()())()" ->["()()()", "(())()"]
	"(a)())()" ->["(a)()()", "(a())()"]
	")(" ->[""]
	Credits :
	Special thanks to @hpplayer for adding this problem and creating all test cases.

	Subscribe to see which companies asked this question*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	void DFS(string s, char ch, int last)
	{
		for (int i = 0, cnt = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == ')') s[i] == ch ? cnt++ : cnt--;
			if (cnt <= 0) continue;
			for (int j = last; j <= i; j++)
			{
				if (s[j] == ch && (j == last || s[j - 1] != ch))
					DFS(s.substr(0, j) + s.substr(j + 1), ch, j);
			}
			return;
		}
		reverse(s.begin(), s.end());
		if (ch == ')') return DFS(s, '(', 0);
		ans.push_back(s);
	}

	vector<string> removeInvalidParentheses(string s) {
		DFS(s, ')', 0);
		return ans;
	}
private:
	vector<string> ans;
};
int main301()
{
	string s = "()())()";
	Solution sol;
	vector<string> res = sol.removeInvalidParentheses(s);
	cout << res.size() << endl;
	return 0;
}

