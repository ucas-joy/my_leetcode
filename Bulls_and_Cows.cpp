/*
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is.
Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess
match your secret number exactly in both digit and position (called "bulls") and how many digits match
the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess,
use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
*/







#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
	string getHint(string secret, string guess) {
		string hits = "";
		string Cret = "";
		string Wcet = "";
		int hash1[256] = { 0 };
		int hash2[256] = { 0 };
		if (secret.length() == 0 && guess.length() == 0) {
			return hits;
		}
		int CLoc = 0;
		int WLoc = 0;
		for (int i = 0; i < secret.length(); ++i) {
			if (secret[i] == guess[i]) {
				CLoc++;
			}
			else {
				Cret += secret[i];
				Wcet += guess[i];
			}
		}
		for (int i = 0; i < Cret.length(); ++i) {
			hash1[Cret[i]]++;
		}
		for (int i = 0; i < Wcet.length(); ++i) {
			hash2[Wcet[i]]++;
		}
		for (int i = 0; i < 256; ++i) {
			if (hash2[i] > 0 && hash1[i] > 0) {
				WLoc += (hash1[i] >= hash2[i] ? hash2[i] : hash1[i]);
			}
		}
		std::stringstream  ss , ss1;
		ss << CLoc;
		hits = hits + ss.str();
		hits.push_back('A');
		ss1 << WLoc;
		hits = hits + ss1.str();
		hits.push_back('B');
		return hits;
	}
};
int main010101()
{
	string s1 = "00112233445566778899";
	string s2 = "16872590340158679432";
	Solution sol;
	string s;
	s = sol.getHint(s1, s2);
	cout << s << endl;
	return 0;
}