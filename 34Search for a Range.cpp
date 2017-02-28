/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

Subscribe to see which companies asked this question
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int>result;
		result.push_back(-1);
		result.push_back(-1);
		if (nums.size() == 0)
			return result;
		int start = 0;
		int end = nums.size() - 1;
		while (start <= end){
			int mid = (start + end) / 2;
			if (nums[mid] == target){
				vector<int> res;
				int tmp = mid;
				while(tmp - 1 >= 0 && nums[tmp - 1] == target){
					tmp--;
				}
				res.push_back(tmp);
				tmp = mid;
				while (tmp + 1 <= end && nums[tmp + 1] == target){
					tmp++;
				}
				res.push_back(tmp );
				return res;
			}
			else if (nums[mid] < target){
				start = mid + 1;
			}
			else{
				end = mid - 1;
			}

		}
		return result;
	}
};

int main()
{
	int a[6] = { 5, 7, 7, 8, 8, 10 };
	vector<int>b(a, a + 6);
	vector<int>ret;
	Solution sol;
	ret = sol.searchRange(b, 8);
	int i = 0;
	int len = ret.size();
	while (i < len)
	{
		cout << ret[i] << endl;
		i++;
	}
	return 0;
}