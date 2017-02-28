/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.

Credits:
*/
#include<iostream>
#include<algorithm>
using namespace std;
//这题真心没意思！！！！！！！！！！
class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int res = (D - B) * (C - A) + (H - F) * (G - E);
		int A1 = max(A, E), B1 = max(B, F), C1 = min(C, G), D1 = min(D, H);
		if (D1 <= B1 || C1 <= A1) return res;
		return res - (D1 - B1) * (C1 - A1);
	}
};