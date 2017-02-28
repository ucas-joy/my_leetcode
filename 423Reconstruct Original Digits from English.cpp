/*
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	string originalDigits(string s) {
		int hash[10] = { 0 };
		int i;
		int len = s.length();
		for (i = 0; i < len; ++i){
			if (s[i] == 'z')++hash[0];
			if (s[i] == 'w')++hash[2];
			if (s[i] == 'u')++hash[4];
			if (s[i] == 'x')++hash[6];
			if (s[i] == 'g')++hash[8];

			if (s[i] == 'h')++hash[3];
			if (s[i] == 'f')++hash[5];
			if (s[i] == 's')++hash[7];
			if (s[i] == 'o')++hash[1];
			if (s[i] == 'i')++hash[9];
		}
		hash[3] = hash[3] - hash[8];
		hash[5] = hash[5] - hash[4];
		hash[7] = hash[7] - hash[6];
		hash[9] = hash[9]- hash[5] - hash[6] - hash[8];
		hash[1] = hash[1] - hash[0]- hash[2] - hash[4];
		string res;
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < hash[i]; ++j){
				res += to_string(i);
			}
		}
		return res;
	}

};
int main()
{
	string s = "fviefuro";
	Solution sol;
	string res = sol.originalDigits(s);
	cout << res << endl;
	return 0;
}