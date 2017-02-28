/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	//vector<string> restoreIpAddresses(string s) {
	//	vector<string>res;
	//	if (s.length() == 0)
	//		return res;
	//	string ret;
	//	if (s.length() == 12) {
	//		for (int i = 0; i < 12; i += 3)
	//		{
	//			ret += s.substr(i, 3) + '.';
	//		}
	//		ret = ret.substr(0, ret.length() - 1);
	//		res.push_back(ret);
	//		return res;
	//	}
	//	for (int i = 0; i < s.length(); ++i)
	//	{

	//	}
	//}
	//void help(vector<string>&res, string&ret,string &tmp,string &s, int bas)
	//{
	//	if (ret.length() == s.length() + 3)
	//	{
	//		res.push_back(ret);
	//		return;
	//	}
	//	for (int i = bas; i < s.length(); ++i)
	//	{

	//	}
	//	if(isvalid(tmp))
	//	{

	//	}
	//}
	//bool isvalid(string &s){
	//	if (s.length() <= 3 && s.length>0){
	//		int t = stoi(s);
	//		return (t >= 0 && t <= 255);
	//	}
	//	return false;
	//}

			/*vector<string> ret;
			string ans;
			for(int a = 1; a <=3 ;++a)
				for(int b = 1; b <= 3 ; ++b)
					for(int c = 1; c <= 3; ++c)
						for(int d = 1 ; d <= 3; ++d)
							if (a + b + c + d == s.length())
							{
								int A = stoi(s.substr(0, a));
								int B = stoi(s.substr(a, b));
								int C = stoi(s.substr(a + b, c));
								int D = stoi(s.substr(a + b + c, d));
								if (A <= 255 && B <= 255 && C <= 255 && D <= 255)
								{
									if ((ans = to_string(A) + '.' + to_string(B) + '.' + to_string(C) + '.' + to_string(D)).length() == s.length() + 3)
										ret.push_back(ans);
								}
						
							}
			return ret;
	}*/
};

//class Solution {
//public:
//	vector<string> restoreIpAddresses(string s) {
//		vector<string> res;
//		helper(s, 0, 4, "", res);
//		return res;
//	}
//
//	void helper(string s, int pos, int count, string curr, vector<string>& res) {
//		// count = 0 means all '.' has been added
//		// pos = s.size() means has reached the end of the string
//		if (count == 0 && pos == s.size()) {
//			res.push_back(curr.substr(1));
//			return;
//		}
//		// '.' has been run out of but not reached the end so there is no correct answers
//		if (count == 0) {
//			return;
//		}
//
//		// if the s[pos] = 0, the '.' has to be added directly after curr
//		if (s[pos] == '0') {
//			helper(s, pos + 1, count - 1, curr + ".0", res);
//			return;
//		}
//		int num = 0;
//		for (int i = 0; i < 3 && pos + i < s.size(); i++) {
//			num = num * 10 + s[pos + i] - '0';
//			// as long as num is less than 255, add '.' and go to the next stage
//			if (num <= 255) {
//				helper(s, pos + i + 1, count - 1, curr + '.' + s.substr(pos, i + 1), res);
//			}
//		}
//	}
//};


/*
class Solution {
public:
vector<string> restoreIpAddresses(string s) {
vector<string> result;
dfs(s, 0, "", result);
return result;
}

void dfs(string s, int n, string out, vector<string>& result) {
if (n == 4) {
if (s.empty()) result.push_back(out);
}
else {
//current number must be 1/2/3 number consisted of
for (int k = 1; k < 4; k++) {
if (s.size() < k) break;
int val = stoi(s.substr(0, k));
if (val > 255 || k != std::to_string(val).size()) continue;
dfs(s.substr(k), n + 1, out + s.substr(0, k) + (n == 3 ? "" : "."), result);
}
}
}
};
*/