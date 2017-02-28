/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument,
please click the reload button  to reset your code definition.
*/

#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	bool isNumber(string s) {
		if (s.size() == 0)
			return false;
		bool has_dig1 = false, has_dot = false, has_dig2 = false, has_e = false, has_sig2 = false, has_dig3 = false;
		int i = 0;
		while (i < s.length() && s[i] == ' ') ++i;
		if ((i < s.length())&&(s[i] == '+' || s[i] == '-')) ++i;
		while ((i < s.length()) && (isdigit(s[i]))) { has_dig1 = true, ++i; };
		if ((i < s.length()) && s[i] == '.') { has_dot = true, ++i;}
		while ((i < s.length()) && (isdigit(s[i]))) { has_dig2 = true, ++i; };
		if ((i < s.length()) && s[i] == 'e') { has_e = true, ++i; }
		if ((i < s.length()) && (s[i] == '+' || s[i] == '-')) {  has_sig2 = true,++i }
		while ((i < s.length()) && (isdigit(s[i]))) { has_dig3 = true, ++i; };
		while (i < s.length() && s[i] == ' ') ++i;

		if (!has_dig1 && !has_dig2) return false;
		if (has_e && !has_dig3) return false;
		if (!has_e && has_sig2) return false;
		return i == s.size();
	}
};
int main()
{
//	string s = "1 a ";
	string s = " 0";
	Solution sol;
	bool is = sol.isNumber(s);
	cout << is << endl;
	return 0;
}
/*
string s1 = "0"; // True
string s2 = " 0.1 "; // True
string s3 = "abc"; // False
string s4 = "1 a"; // False
string s5 = "2e10"; // True

string s6 = "-e10"; // False
string s7 = " 2e-9 "; // True
string s8 = "+e1"; // False
string s9 = "1+e"; // False
string s10 = " "; // False

string s11 = "e9"; // False
string s12 = "4e+"; // False
string s13 = " -."; // False
string s14 = "+.8"; // True
string s15 = " 005047e+6"; // True

string s16 = ".e1"; // False
string s17 = "3.e"; // False
string s18 = "3.e1"; // True
string s19 = "+1.e+5"; // True
string s20 = " -54.53061"; // True

string s21 = ". 1"; // False
*/


/*
class Solution {
public:
    bool isNumber(string s) {
        bool num = false, numAfterE = true, dot = false, exp = false, sign = false;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                if (i < n - 1 && s[i + 1] != ' ' && (num || dot || exp || sign)) return false;
            } else if (s[i] == '+' || s[i] == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ') return false;
                sign = true;
            } else if (s[i] >= '0' && s[i] <= '9') {
                num = true;
                numAfterE = true;
            } else if (s[i] == '.') {
                if (dot || exp) return false;
                dot = true;
            } else if (s[i] == 'e') {
                if (exp || !num) return false;
                exp = true;
                numAfterE = false;
            } else return false;
        }
        return num && numAfterE;
    }
};

*/