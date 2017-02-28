/*
372. Super Pow   QuestionEditorial Solution  My Submissions
Total Accepted: 9401
Total Submissions: 29088
Difficulty: Medium
Contributors: Admin
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:

a = 2
b = [3]

Result: 8
Example2:

a = 2
b = [1,0]

Result: 1024
Credits:
Special thanks to @Stomach_ache for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	/*int superPow(int a, vector<int>& b) {
		if (b.size() == 0)
			return 1;
		if (b.size() == 1 && b[0] == 0 && a == 0)
			return 1;
		if (a == 0 && b.size() != 0)
			return 0;
		int len = b.size();
		int tmp ;
		int tmp_len = len;
		long long int tmp_a ,mod_a;
		vector<int>tmp_v;
		mod_a = a % 1377;
		for (int i = 0; i < len; i++){
			int t = b[i] * pow(10, tmp_len - 1);
			tmp_a = mod_a;
			tmp = 1;
			while (t){
				if (t & 1) tmp = (tmp *tmp_a)%1377;
				tmp_a = tmp_a % 1377;
				tmp_a *= tmp_a ;
				tmp_a = tmp_a %1377;
				t = t / 2;
			}
			tmp = tmp % 1377;
			tmp_v.push_back(tmp);
			tmp_len--;
		}
		int result = tmp_v[0];
		for (int i = 1; i < tmp_v.size(); ++i){
			result = (result * tmp_v[i]) % 1377;
		}
		return result;
	}*/

	int superPow(int a, int k)
	{
		if (k == 0) return 1;
		int ans = 1;
		for (int i = 1; i <= k; i++) ans = (ans*a) % 1337;
		return ans;
	}

	int superPow(int a, vector<int>& b) {
		if (b.empty()) return 1;
		a = a % 1337;
		int lastBit = b.back();
		b.pop_back();
		return (superPow(superPow(a, b), 10) * superPow(a, lastBit)) % 1337;
	}
	
};

int main()
{
	int a = 2147483647;
	int b[3] = { 2,0,0 };
	vector<int>c(b, b + 3);
	Solution sol;
	int res = sol.superPow(a, c);
	cout << res << endl;
	return 0;
}