/*mplement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Subscribe to see which companies asked this question
*/


#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
	int strStr(string haystack, string needle) {

		if (haystack.length() == 0 && needle.length() == 0)
		{
			return 0;
		}
		if (needle.length() == 0){
			return 0;
		}
		int len = needle.length();
		int len1 = haystack.length();
		if (len > len1)
			return -1;
		if (len == len1){
		if (haystack == needle) {
				return 0;
			}
		else {
			return -1;
			}		
		}
		int index;
		string tmp = "";
		int i = 0;
		int j = 0;
		for (; i < len1; ++i) {
			index = i;
			int t = i;
			while (j < len && t< len1) {
				tmp += haystack[t++];
				j++;
			}
			
			if (tmp == needle)
			{
				return index;
			}
			else{
				tmp = "";
				j = 0;
			}
		}
		return -1;
	}
};

int main222()
{
	string s1 = "";
	string s2 = "";
	Solution sol;
	int i;
	i = sol.strStr(s1, s2);
	cout << i << endl;
	return 0;
}