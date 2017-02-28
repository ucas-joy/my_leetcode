/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2)
			return;
		int len = nums.size();
		int i,k;
		for ( i = len - 2; i >= 0; i--){
			if (nums[i] < nums[i + 1])
				break;
		}
		if (i < 0){
			reverse(nums.begin(), nums.end());
			return;
		}
		for (k = nums.size() - 1; i >= 0 && k > i; --k){
			if (nums[i] < nums[k])
				break;
		}
		if (i >= 0){
			swap(nums[i], nums[k]);
			reverse(nums.begin() + i + 1, nums.end());
			return;
		}
	}
};

int main31()
{
	int a[3] = {2,3,1};
	vector<int>b(a, a + 3);
	Solution sol;
	sol.nextPermutation(b);
	int i = 0;
	while (i < 3)
	{
		cout << b[i] << " ";
		i++;
	}
	return 0;
}