/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/



#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };

class Solution {
public:
	int maxPoints(vector<Point>& points) {
		unordered_map<float, int>mp;
		int maxNum = 0;
		for (int i = 0; i < points.size(); ++i){
			mp.clear();
			mp[INT_MIN] = 0;
			int duplicate = 1;
			for (int j = 0; j < points.size(); ++j){
				if (i == j)
					continue;
				if (points[i].x == points[j].x && points[i].y == points[j].y){
					duplicate++;
					continue;
				}
				float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y) / (points[j].x - points[i].x);
				mp[k]++;
			}
			unordered_map<float, int>::iterator it;
			for (it = mp.begin(); it != mp.end(); ++it)
			{
				if (it->second + duplicate > maxNum)
					maxNum = it->second + duplicate;
			}
		}
		return maxNum;
	}
};

/*
注意：
0、points中重复出现的点。
1、int maxNum = 0;
初始化，以防points.size() == 0的情况。
2、mp[INT_MIN] = 0;
保证poins中只有一个结点，还有points中只有重复元素时，mp中没有元素。这两种极端情况。
3、int duplicate = 1;
duplicate记录重复点的数量，初始化为1，是因为要把当前的点points[i]加进去。
4、float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y) / (points[j].x - points[i].x);
计算斜率，如果直线和y轴平行，就取INT_MAX, 否则就取(float)(points[j].y - points[i].y) / (points[j].x - points[i].x)
一开始把(float)(points[j].y - points[i].y) / (points[j].x - points[i].x)写做(float)((points[j].y - points[i].y) / (points[j].x - points[i].x))一直就不对，后来才想明白，注意注意！


*/

