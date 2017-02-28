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
//dp[i]����i��β�ģ��������ֵ����ҵ���
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
���Զ��棺���ص������ϳ����Σ��ڵ��ף���ѧУ�����;����ȣ�
���򶯹棺ʯ�Ӻϲ��� �ӷֶ�������ͳ�Ƶ��ʸ������ڱ�����ȣ�
���ζ��棺̰�Եľ�ͷ�������ֲ��������ۻ�Ļ��֣����������εȣ�
*/

/*
����ʵ����̫ǿ���ˣ�ע����ö���Ӵ�����ʱ��ֻҪö�ٴ�dict�ֵ�����̵��ʵ�����ʵĳ��ȾͿ����ˡ�
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