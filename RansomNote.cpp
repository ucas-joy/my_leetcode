/*

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<string>
using namespace  std;
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		if (magazine.length() == 0 && ransomNote.length() == 0){
			return true;
		}
		if (ransomNote.length() > magazine.length()) {
			return false;
		}
		int hash1[256] = { 0 };
		int hash2[256] = { 0 };
		for (int i = 0; i < ransomNote.length(); ++i){
			hash1[ransomNote[i]]++;
		}
		for(int i = 0 ; i < magazine.length();++i){
			hash2[magazine[i]]++;
		}
		for (int i = 0; i < 256; ++i) {
			if (hash1[i] > hash2[i]) {
				return false;
			}
		}
		return true;

	}
};
int main3333333333333333333()
{
	Solution sol;
	string a = "fffbfg";
	string b = "effjfggbffjdgbjjhhdegh";
	bool is;
	is = sol.canConstruct(a, b);
	cout << is << endl;
	return 0;
}