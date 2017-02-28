/*Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
	Assume the length of given string will not exceed 1, 010.

		Example :

		Input :
		"abccccdd"

		Output :
		7

		Explanation :
		One longest palindrome that can be built is "dccaccd", whose length is 7.
		*/


#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	int longestPalindrome(string s) {
		if (s.length() == 0)
			return 0;
		int hash[128] = { 0 };
		int len = s.length() - 1;
		for (int i = 0; i <= len; ++i){		
			if (hash[s[i] - '0'] == 0){
				hash[s[i] - '0']++;
			}
			else{
				hash[s[i] - '0']--;
			}
		}
		int count = 0;
		for (int i = 0; i < 128; ++i) {
			if (hash[i]!= 0) {
				count++;
			}
		}
		if (count == 0){
			return s.length();
		}
		else{
			return s.length() - count + 1;
		}
		
	}
};
int main()
{
	string a = "bbaacd";
	int i;
	Solution sol;
	i = sol.longestPalindrome(a);
	cout << i << endl;
	return 0;
}