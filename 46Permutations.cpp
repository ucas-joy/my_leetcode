/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int>path,tmp;
		sort(nums.begin(), nums.end());
		tmp = nums;
		reverse(tmp.begin(), tmp.end());
		if (nums.size() == 0)
			return res;
		path = nums;
		res.push_back(path);
		int len = nums.size();
		int i = len - 2;
		int k;
		while (i >= 0){
			for (i = len - 2; i >= 0; i--){
				if (path[i] < path[i + 1])
					break;
			}
			for (k = path.size() - 1; i >= 0 && k > i; --k){
				if (path[i] < path[k])
					break;
			}
			if (i >= 0) {
				swap(path[i], path[k]);
				reverse(path.begin() + i + 1, path.end());
				res.push_back(path);
			}
			if (path == tmp)
				break;
		}
		return res;
	}
};
int main46()
{
	int a[3] = { 1,2,3 };
	vector<int>b(a, a + 3);
	Solution sol;
	vector<vector<int>> res = sol.permute(b);
	int row = res.size();
	int colum = res[0].size();
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < colum; ++j)
		{
			cout << res[i][j] << endl;
		}
		cout << endl;
	}
	return 0;
}