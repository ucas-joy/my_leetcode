/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int findMin(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		if (len == 1)
			return nums[0];
		int begin = 0;
		int end = len - 1;
		while (begin < end) {
			if (nums[begin] < nums[end]) {
				return nums[begin];
			}
			int mid = begin + (end - begin) / 2;
			if ((nums[mid] >= nums[end])){
				begin = mid+1;
			}
			else{
				end = mid;
			}
		}
		return nums[begin];
	}
};
int main()
{
	int a[7] = { 4, 5, 6, 7, 0, 1, 2 };
	vector<int>b(a, a + 7);
	Solution sol;
	int i;
	i = sol.findMin(b);
	cout << i << endl;

}