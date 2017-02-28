/*Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is :

[
	[2, 4],
	[3, 4],
	[2, 3],
	[1, 2],
	[1, 3],
	[1, 4],
]
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int>nums;
		for (int m = 1; m <= n; ++m) {
			nums.push_back(m);
		}
		vector<vector<int>>result;
		vector<int>sub1;
		if (nums.size() == 0)
		{
			return result;
		}
		int i, j, k1;
		int num = 1 << nums.size();
		for (i = 0; i < num; ++i) {
			vector<int>sub;
			k1 = 0;
			j = i;
			while (j) {
				if (j & 1) {
					sub.push_back(nums[k1]);
				}
				j >>= 1;
				k1++;
			}
			if (sub.size() == k)
			{
				result.push_back(sub);
			}
			
		}
		return result;
	}*/

		/*vector<vector<int>>result;
		if (n == 0 || k == 0)
			return result;
		vector<int>nums;
		for (int m = 1; m <= n; ++m){
			nums.push_back(m);
		}
		int num = 1 << n;
		int i, j, k1;
		for (i = 0; i < n; ++i){
			vector<int>sub1;
			j = i;
			k1 = 0;
			while (j){
				if (j & 1){
					sub1.push_back(nums[k1]);
				}
				j >>= 1;
				++k1;
			}
			if (sub1.size() == k){
				result.push_back(sub1);
			}
		}
		return result;
	}*/
class Solution {
public:
	void helper(int n, int k, int start, vector<vector<int>>& res, vector<int>& temp) {

		if (k == 0) {
			res.push_back(temp);
			return;
		}
		for (int i = start; i + k - 1 <= n; i++) {
			temp.push_back(i);    //push the combinations
			helper(n, k - 1, i + 1, res, temp);
			temp.pop_back();        //backtrack and pop_back

		}
	}
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> temp;
		int start = 1;
		helper(n, k, start, res, temp);
		return res;
	}
};
int main()
{
	int n = 4, k = 2;
	Solution sol;
	vector<vector<int>> t = sol.combine(n, k);
	int row = t.size();
	int col = t[0].size();
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}