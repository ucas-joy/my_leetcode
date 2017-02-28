/*
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less 
than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	int longestSubstring(string s, int k) {
		int n = s.length();
		int res = 0;
		int i = 0;
		while (i + k < n){
			int hash[26] = { 0 }, max_idx = i, mask = 0;
			for (int j = i; j < n; ++j){
				int t = s[j] - 'a';
				++hash[t];
				if (hash[t] < k){
					mask |= (1 << t);
				}else{
					mask &= (~(1 << t));
				}
				if (mask == 0){
					res = max(res, j - i + 1);
					max_idx = j;
				}
			}
			i = max_idx + 1;
		}
		return res;
	}
};