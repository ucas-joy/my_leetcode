/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*class Solution {
public:
	bool isSmall(string &a, string &b)// 字典序 a 在b前面
	{
		bool flag;
		if (a == b){
			flag =  false;
		}
		for (int i = 0; i < a.size(); ++i){
			if (a[i] == b[i])  continue;
			if (a[i] < b[i])
			{
				flag =  true;
				break;
			}
			else
			{
				flag =  false;
				break;
			}
		}
		return flag;
	}
	// 当前字符tmp 在字符中的位置 后还存在比 tmp 小的  就返回true
	//"bacd" tmp == b 的时候， 就要 编程acdb。  tmp < 最后一个值。 
	bool hasSmall(string& res, char tmp){
		bool flag = false;
		string::iterator it;
		for (it = res.begin(); it != res.end(); ++it){
			if (*it == tmp){
				break;
			}
		}
		for (it = it + 1; it != res.end(); ++it)
		{
			if (*it < tmp)
			{
				flag = true;
			}
		}
		return flag;
	}
	string remove(string &res, char tmp)
	{
		string::iterator it;
		for (it = res.begin(); it != res.end(); ++it){
			if (*it == tmp){
				res.erase(it);
				break;
			}
		}
		return res;
	}
	string removeDuplicateLetters(string s) {
		string res;
		if (s.length() == 0)
			return res;
		int hash[256] = { 0 };
		char tmp = s[0];
		for (int i = 0; i < s.length(); ++i) {
			hash[s[i]]++;
			if (hash[s[i]] == 1) {
				res += s[i];
				tmp = s[i];
			}
			if (hash[s[i]] > 1) {
				if (tmp < s[i]) {
					string tmp_res = res;
					tmp_res = remove(tmp_res, s[i]);
					tmp_res = tmp_res + s[i];
					res = tmp_res;
				}
				else
				{
					if (hasSmall(res, s[i]))
					{
						string tmp_res = res;
						tmp_res = remove(tmp_res, s[i]);
						tmp_res = tmp_res + s[i];
						if (isSmall(tmp_res, res))
						{
							res = tmp_res;
						}
					}
				}

			}
			
		}
		return res;
	}
	};
*/
class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<int> cand(256, 0);
		vector<bool> visited(256, false);
		for (char c : s)
			cand[c]++;
		string result = "0";
		for (char c : s) {
			cand[c]--;
			if (visited[c]) continue;
			char tmp = result.back();
			while (c < result.back() && cand[result.back()]) {
				visited[result.back()] = false;
				result.pop_back();
			}
			result += c;
			visited[c] = true;
		}
		return result.substr(1);
	}
};
int main316()
{
     // string s = "cbacdcbc";
	//string s = "bcabc";
	//string s = "dbede"; // bde
	string s = "beeaddbeb";  //"adbe"
	Solution sol;
	string t = sol.removeDuplicateLetters(s);
	cout << t << endl;
	return 0;
}