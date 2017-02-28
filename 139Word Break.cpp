/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;
class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		if (wordDict.size() == 0)
			return false;
		vector<bool>dp(s.length() + 1, false);
		dp[0] = true;
		int min_len = INT_MAX;
		int max_len = INT_MIN;
		for (auto ss : wordDict){
			min_len = min(min_len,(int)ss.length());
			max_len = max(max_len, (int)ss.length());
		}
		for (int i = 0; i < s.size(); ++i)  if (dp[i]) {
			for (int len = min_len; i + len <= s.length() && len <= max_len; ++len){
				if (wordDict.find(s.substr(i, len)) != wordDict.end()){
					dp[i + len] = true;
				}
			}
			if (dp[s.length()]) return true;
		}
		return dp[s.length()];
	}
};

/*
We use a boolean vector dp[]. dp[i] is set to true if a valid word (word sequence) ends there.
The optimization is to look from current position i back and only substring and do dictionary look up in case the
preceding position j with dp[j] == true is found.
*/
//dp[i]是以i结尾的，可以在字典中找到。
/*
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (dict.size() == 0) return false;
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 1; i <= s.size(); i++){
			for (int j = i - 1; j >= 0; j--){	
				if (dp[j]) {
					string word = s.substr(j, i - j);
					if (dict.find(word) != dict.end()) {
						dp[i] = true;
						break;
					}
				}
			}
		}
		return dp[s.size()];
	}
};
*/
int main()
{
	/*
	"aaaaaaa"
	["aaaa","aa"]
	*/
	string s = "aaaaaaa";
	unordered_set<string>t = { "aaaa","aa" };
	//string s = "leetcode";
	//unordered_set<string>t = { "leet","code" };
	//string s = "catlencat";
	//unordered_set<string>t = { "cat","len" };
	Solution sol;
	bool is = sol.wordBreak(s, t);
	cout << is << endl;
	return 0;
}

/*
线性动规：拦截导弹，合唱队形，挖地雷，建学校，剑客决斗等；
区域动规：石子合并， 加分二叉树，统计单词个数，炮兵布阵等；
树形动规：贪吃的九头龙，二分查找树，聚会的欢乐，数字三角形等；
*/

/*
动规实在是太强大了！注意在枚举子串长度时，只要枚举从dict字典中最短单词到最长单词的长度就可以了。
*/
/*
class Solution {
public:
	
	bool wordBreak(string s, unordered_set<string> &dict) {
		// write your code here
		vector<bool> dp(s.length() + 1, false);
		dp[0] = true;
		int min_len = INT_MAX, max_len = INT_MIN;
		for (auto &ss : dict) {
			min_len = min(min_len, (int)ss.length());
			max_len = max(max_len, (int)ss.length());
		}
		for (int i = 0; i < s.length(); ++i) if (dp[i]) {
			for (int len = min_len; i + len <= s.length() && len <= max_len; ++len) {
				if (dict.find(s.substr(i, len)) != dict.end())
					dp[i + len] = true;
			}
			if (dp[s.length()]) return true;
		}
		return dp[s.length()];
	}
};
*/