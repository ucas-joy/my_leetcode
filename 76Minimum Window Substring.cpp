/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

Subscribe to see which companies asked this question
*/


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//class Solution {
//public:
//	string minWindow(string s, string t) {
//		string res;
//		if (t.length() > s.length())
//			return res;
//		/*if(t.length() == s.length()&& s == t)
//		{
//			return t;
//		}*/
//		int slen = s.length();
//		int tlen = t.length();
//		vector<int>hash(256, 0);
//		vector<int>tmp_hash;
//		for (int i = 0; i < tlen; ++i){
//			hash[t[i]]++;
//		}
//	//	res = s;
//		tmp_hash = hash;
//		int minL = slen;
//		int tmp_i;
//		int j = 0;
//		int k = 0;
//		tmp_i = remove(hash,s, j);
//		for (int i = j; i < slen; ){
//			j = remove(hash, s, i);
//			i = j;
//			while (k < tlen && i < slen) {
//				i = remove(hash, s, i);
//				if (hash[s[i]] > 0) {
//					hash[s[i]]--;
//					k++;
//					++i;
//				}else
//				{
//					++i;
//				}
//			}
//			if (k == tlen){
//				if (i - j <= minL){
//					minL = i - j;
//					res = s.substr(j, minL);
//				}
//				k = 0;
//				hash = tmp_hash;
//				tmp_i = j;
//				tmp_i = tmp_i + 1;
//				j = tmp_i;
//				i = j;
//			}
//		}
//		return res;
//		
//	}
//	int remove(vector<int>&hash, string s ,int i)
//	{
//		while (i < s.length() && hash[s[i]] == 0){
//			i++;
//		}
//		return i;
//	}
//};

/*class Solution {
public:
	string minWindow(string s, string t) {
		int M = t.size();
		int src[128] = { 0 }, target[128] = { 0 };
		for (auto item : t) target[item]++;

		int cur_len = 0, min_len = INT_MAX, valid_count = 0;
		string result = "";

		char ch;

		int i = 0, j = 0;
		for (; i < s.size(); i++) {
			ch = s[i];
			// add s[i]
			if (src[ch] < target[ch] && target[ch]>0) valid_count++;
			cur_len++;
			src[ch]++;

			// check if we can pop any from j
			ch = s[j];
			while (target[ch] == 0 || src[ch] > target[ch]) {
				src[ch]--;
				j++;
				cur_len--;
				ch = s[j];
			}

			if (cur_len < min_len && valid_count >= M) {
				min_len = cur_len;
				result = s.substr(i - cur_len + 1, cur_len);
			}
		}

		return result;
	}
};
class Solution {
public:
	string minWindow(string s, string t) {
		int c[128] = { 0 };
		bool flag[128] = { false };
		for (int i = 0; i < t.length(); ++i){
			flag[t[i]] = true;
			++c[t[i]];
		}
		int cnt = 0, l = 0, minl = 0, minsize = s.size() + 1;
		for (int r = 0; r < s.length(); ++r)
		{
			if (flag[s[r]])
			{
				if (--c[s[r]] >= 0)
					++cnt;
				while (cnt == t.size())
				{
					if (r - l + 1 < minsize)
					{
						minl = l, minsize = r - l + 1;
					}
					if (flag[s[l]])
					{
						if (++c[s[l]] > 0)
							--cnt;
					}
					++l;
				}
			}
		}
		if (minsize > s.size())
	        return "";
         return s.substr(minl, minsize);

	}
};*/
class Solution {
public:
	string minWindow(string s, string t) {
		int c[128] = { 0 };
		bool flag[128] = { false };
		for (int i = 0; i < t.length(); ++i)
		{
			flag[t[i]] = true;
			c[t[i]]++;
		}
		int cnt = 0, l = 0, minl = 0, minsize = s.length() + 1;
		for (int r = 0; r < s.length(); ++r)
		{
			if (flag[s[r]])
			{
				if (--c[s[r]] >= 0)
					cnt++;
				while (cnt == t.size())
				{
					if (r - l + 1 < minsize)
					{
						minl = l, minsize = r - l + 1;

					}
					if (flag[s[l]])
					{
						if (++c[s[l]] > 0)
							--cnt;
					}
					++l;
				}
			}
		}
		if (minsize > s.size())
			return "";
		return s.substr(minl, minsize);
	}
};
int main()
{
	//string s = "ADOBECODEBANC"; //"BANC"
	//string 	t = "ABC";      
	//string s = "bba";
	//string t = "ba";
	string s = "a";
	string t = "a";
	Solution sol;
	string res = sol.minWindow(s, t);
	cout << res << endl;
	return 0;

}