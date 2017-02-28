/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

	1         3     3      2      1
	\       /     /       / \      \
	 3    2     1        1   3      2
	/     /       \                  \
   2     1         2                  3
Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int numTrees(int n) {
		vector<int>dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; ++i){
			int t = i;
			while (t >= 1){
				dp[i] += dp[i - t] * dp[t-1];
				t--;
			}
		}
		return dp[n];
	}
};
int main()
{
	int n = 3;
	Solution sol;
	int s = sol.numTrees(n);
	cout << s << endl;
	return 0;
}