/*
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether
it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
Example 1: (From the famous "Die Hard" example)

Input: x = 3, y = 5, z = 4
Output: True
Example 2:

Input: x = 2, y = 6, z = 5
Output: False
Credits:
Special thanks to @vinod23 for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
//两个瓶子可能量出的水是两个瓶子容量最大公约数的倍数,所以只要判断z是否可以被x，y的最大公约数整除即可。
#include<iostream>
using namespace std;
class Solution {
public:
	bool canMeasureWater(int x, int y, int z) {
		if (x + y < z)
			return false;
		if (x + y == z || x == z || y == z)
			return true;

		return z % gcd(x, y) == 0;
	}
	int gcd(int x, int y){
		while (x != 0){
			int tmp = x;
			x = y % x;
			y = tmp;
		}
		return y;
	}
};
int main()
{
	int x = 3, y = 5, z = 4;
	Solution sol;
	bool f = sol.canMeasureWater(3, 5, 4);
	cout << f << endl;
	return 0;
}