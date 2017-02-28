/*
Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
class NumArray {
private:
	vector<int>& nums_;
	vector<int>BIT;
	int n;
public:
	NumArray(vector<int> &nums):nums_(nums) {
		n = nums_.size();
		BIT.resize(n + 1);
		int i;
		for (i = 0; i < n; ++i)
			_update(i, nums_[i]);
	}
	void _update(int i, int val)
	{
		i++;
		while (i <= n)
		{
			BIT[i] += val;
			i += i &(-i);
		}
	}
	void update(int i, int val) {
		_update(i, val - nums_[i]);
		nums_[i] = val;
	}
	int _sumRange(int i)
	{
		i++;
		int sum = 0;
		while (i > 0)
		{
			sum += BIT[i];
			i -= i &(-i);
		}
		return sum;
	}
	int sumRange(int i, int j) {
		return _sumRange(j) - _sumRange(i) + nums_[i];

	}

};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);