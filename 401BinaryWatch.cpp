/*
A binary watch has 4 LEDs on the top which represent the hours (0-11), 
and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.
For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<string>
#include<bitset>
using namespace std;
class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> times;

		if (num < 0 || num > 8)
			return times;

		for (int i = 0; i < 0x2FF; i++) {
			if (bitset<10>(i).count() == num)
				add(i, times);
		}

		return times;
	}

	void add(int i, vector<string>& t) {
		string s;
		int m = i & 0x3F;
		if (m > 59)
			return;
		int h = i >> 6 & 0xF;
		if (h > 11)
			return;

		t.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
	}
};
/*
vector<string> readBinaryWatch(int num) {
	vector<string>result;
	if (num <= 0 || num > 8)
	return result;
	//0x2FF表示的是10位中，1011  111111
	for (int i = 0; i < 0x2FF; i++) {
		if (bitset<10>(i).count() == num) {
		add(i, result);
		}
	}
}
	void add(int i, vector<string>&t)
	{
		string s;
		int m = i & 0x3F;//获取分钟数
		if (m > 59)
			return;
		int h = i >> 6 & 0xF; //右移6位，取出小时位
		if (h > 11)
			return;
		t.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
	}
	*/

int main()
{
	int i = 1;
	int j = 0;
	Solution sol;
	vector<string> tmp;
	tmp = sol.readBinaryWatch(i);
	int len = tmp.size();
	while (j < len)
	{
		cout << tmp[j] << endl;
		j++;
	}
	return 0;
}