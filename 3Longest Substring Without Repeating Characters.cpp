/*Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, 
"pwke" is a subsequence and not a substring.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxL = 0;
		int count = 0;
		//map<char, int>mp;
		if (s.length() == 0)
			return 0;
		//map<char, int>::iterator it;
		int hash[256] = { 0 };
		for (int i = 0; i < s.length(); ++i){
			if (hash[s[i]] == 0)
			{
				hash[s[i]] = i + 1;
				count++;
			}
			else if (hash[s[i]] != 0)
			{
				maxL = max(maxL, count);
				i = hash[s[i]]-1;
				memset(hash, 0, sizeof(hash));
				count = 0;
			}
			/*it = mp.find(s[i]);
			if(it == mp.end())
			{
				count++;
				mp.insert(make_pair(s[i], i));
			}
			else
			{
				maxL = max(maxL, count);
				i = it->second;
				mp.clear();
				count = 0;
			}*/
		}
		maxL = max(maxL, count);
		return maxL;
	}
};
int main()
{
	string s = "dvdf";
	Solution sol;
	int i;
	i = sol.lengthOfLongestSubstring(s);
	cout << i << endl;
	return 0;
}