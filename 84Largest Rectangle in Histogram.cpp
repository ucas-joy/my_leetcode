#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int ret = 0;
		stack<int>stk;
		for (int i = 0; i < heights.size(); ++i)
		{
			if (stk.empty() || heights[i] > stk.top())
			{
				stk.push(heights[i]);
			}else{
				int count = 0;
				while (!stk.empty() && heights[i] < stk.top()){
					count++;
					ret = max(ret, stk.top() * count);
					stk.pop();
				}
				while (count--){
					stk.push(heights[i]);
				}
				stk.push(heights[i]);
			}
		}
		int count = 1;
		while (!stk.empty()){
			ret = max(ret, stk.top() *count);
			count++;
			stk.pop();
		}
		return ret;
	}
};
int main84()
{
	vector<int>a = { 2,1,5,6,2,3 };
	Solution sol;
	int s = sol.largestRectangleArea(a);
	cout << s << endl;
	return 0;
}

