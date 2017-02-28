/*
Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/
#include<iostream>
#include <vector>
using namespace std;
class NumArray {
public:
	NumArray(vector<int> &nums) {
		if (nums.empty()) {
			return;
		}
		else
		{
			int len = nums.size();
			sums.push_back(nums[0]);
			for (int i = 1; i < len; ++i) {
				sums.push_back(sums[i - 1] + nums[i]);
			}
		}
	}

	int sumRange(int i, int j) {
		if (i == 0) {
			return sums[j];
		}
		else
		{
			int len = sums.size();
			if (i < 0 || i > len || j< 0 || j > len) {
				return 0;
			}
			return sums[j] - sums[i - 1];
		}
		}
	
private:
	vector<int>sums;

};
int main()
{
	vector<int>a =  { -2,0,3,-5,2,-1 };
	NumArray A(a);
	cout << A.sumRange(0, 2) << endl;
	cout << A.sumRange(2, 5) << endl;
	cout << A.sumRange(0, 5) << endl;
}

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);