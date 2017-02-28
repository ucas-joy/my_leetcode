/*
   QuestionEditorial Solution  My Submissions
Total Accepted: 67825
Total Submissions: 254958
Difficulty: Medium
Contributors: Admin
The set [1,2,3,бн,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		/*string result;
		if (n == 0)
			return result;
		while (n>0){
			result += (n + '0');
			--n;
		}
		reverse(result.begin(), result.end());
		int i, j;
		while (k >1){
			for (i = result.size() - 2; i >= 0; --i){
				if (result[i] <result[i + 1] )
					break;
			}
			if (i < 0){
				reverse(result.begin(), result.end());
			}
			for ( j = result.size() - 1; j > i && i >= 0; j--){
				if ((result[j] - '0') > (result[i] - '0'))
					break;
			}
			if (i >= 0){
				swap(result[i], result[j]);
				reverse(result.begin() + i + 1, result.end());
			}
			k--;
		}
		return result;*/
		/*string result;
		vector<int> res;
		int i = 1;
		while (i <= n){
			res.push_back(i);
			++i;
		}
		while (k > 1)
		{
			next_permutation(res.begin(), res.end());
			--k;
		}
		int j = 0;
		while (j < res.size()){
		   
			int tmp = res[j];
			result += (tmp + '0');
			++j;
		}
		return result;*/

	/*	k--;
		vector<int>nums;
		for (int i = 1; i <= n; i++){
			nums.push_back(i);
		}
		int fac = 1;
		for (int i = 2; i < n; i++){
			fac *= i;
		}
		string res;
		int round = n - 1;
		while (round >= 0){
			int index = k / fac;
			k %= fac;
			res += nums[index] + '0';
			nums.erase(nums.begin() + index);
			if (round){
				fac /= round;
			}
			round--;
		}
		return res;*/

		k--;
		vector<int>nums;
		for (int i = 1; i < n; ++i){
			nums.push_back(i);
		}
		int fab = 1;
		for (int i = 2; i < n; ++i){
			fab *= i;
		}
		string res;
		int round = n - 1;
		while (round >= 0){
			int index = k / fab;
			k %= fab;
			res += nums[index] + '0';
			nums.erase(nums.begin() + index);
			if (round){
				fab /= round;
			}
			round--;
		}
		return res;
	}
};

int main()
{
	int n =2 , k = 2;
	Solution sol;
	string result = sol.getPermutation(n, k);
	cout << result << endl;
	return 0;
}