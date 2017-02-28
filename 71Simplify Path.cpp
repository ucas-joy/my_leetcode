/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
class Solution {
public:
	string simplifyPath(string path) {
		string ans, now;
		vector<string>list;
		stringstream ss(path);
		while (getline(ss, now, '/')){
			if (now.length() == 0 || now == ".")
				continue;
			if (now == ".."){
				if (!list.empty()){
					list.pop_back();
				}
			}else{
				list.push_back(now);
			}
		}
		for (int i = 0; i < list.size(); ++i){
			ans += "/";
			ans += list[i];
		}
		if (ans.length() == 0) ans += "/";
		return ans;
	}
};

int main()
{
	string path = "/a/./b/../../c/";
	Solution sol;
	string s = sol.simplifyPath(path);
	cout << s << endl;
	return 0;

}