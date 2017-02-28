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
ע�⣺
0��points���ظ����ֵĵ㡣
1��int maxNum = 0;
��ʼ�����Է�points.size() == 0�������
2��mp[INT_MIN] = 0;
��֤poins��ֻ��һ����㣬����points��ֻ���ظ�Ԫ��ʱ��mp��û��Ԫ�ء������ּ��������
3��int duplicate = 1;
duplicate��¼�ظ������������ʼ��Ϊ1������ΪҪ�ѵ�ǰ�ĵ�points[i]�ӽ�ȥ��
4��float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y) / (points[j].x - points[i].x);
����б�ʣ����ֱ�ߺ�y��ƽ�У���ȡINT_MAX, �����ȡ(float)(points[j].y - points[i].y) / (points[j].x - points[i].x)
һ��ʼ��(float)(points[j].y - points[i].y) / (points[j].x - points[i].x)д��(float)((points[j].y - points[i].y) / (points[j].x - points[i].x))һֱ�Ͳ��ԣ������������ף�ע��ע�⣡


*/

