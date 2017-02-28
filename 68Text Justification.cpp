/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words,
the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
"This    is    an",
"example  of text",
"justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	string getAline(vector<string>&words, int maxWidth, int start, int end)
	{
		//处理words.size() == 0 的情况
		if (start > end) return string(maxWidth, ' ');
		//处理只有一个单词的情况
		if (start == end) return words[start] + string(maxWidth - words[start].size(), ' ');
		string ret = "";
		int totLen = 0;
		//统计单词的长度
		for (int i = start; i <= end; ++i)
			totLen += words[i].size();
		int space = (maxWidth - totLen) / (end - start);//每个间隔的单词数
		int rest = (maxWidth - totLen) % (end - start);//需要额外增加空格的间隔数
		//如果是最后一行特殊处理
		if (end == words.size() - 1) 
		{ space = 1, rest = 0; }
		//处理出该行字符串
		ret += words[start];
		for (int i = start + 1; i <= end; ++i) {
			ret += string(space, ' ');
			if (i - start <= rest) //如果有多余的空格，就先在前面间隔部分填满
			{ ret += ' '; }
			ret += words[i];
		}
		//最后一行特殊处理
		ret += string(maxWidth - ret.size(), ' ');
		return ret;

	}
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int len = -1, prev = 0;  // len = -1 表示处理第一次计算的时候， prev = 0 表示该行的起点位置
		string line = "";
		vector<string> ret;
		for (int i = 0; i < words.size(); ++i) {
			if (len + 1 + words[i].size() <= maxWidth){
				len += 1 + words[i].size(); //在紧凑的情况仍然不足maxWidth
			}
			else{
				ret.push_back(getAline(words, maxWidth, prev, i - 1)); // 处理 位置从prev  到  i-1 这一行
				//新的一行
				len = words[i].size();
				prev = i;
			}
		}
		ret.push_back(getAline(words, maxWidth, prev, words.size() - 1));
		return ret;
	}
};
int main68()
{
	vector<string> words = { "This", "is", "an", "example", "of", "text", "justification." };
	Solution sol;
	vector<string> t = sol.fullJustify(words, 16);
	
	return 0;
}
/*
class Solution {
public:
	string getAline(vector<string>&words, int maxWidth, int start, int end){
		if (start > end) return string(maxWidth, ' ');
		if (start == end) return words[start] + string(maxWidth - words[start].size(), ' ');
		string ret = "";
		int totLen = 0;
		for (int i = start; i <= end; ++i)
		{
			totLen += words[i].size();
		}
		int space = (maxWidth - totLen) / (end - start);
		int rest = (maxWidth - totLen) % (end - start);
		if (end == words.size() - 1) space = 1, rest = 0;
		ret += words[start];
		for (int i = start + 1; i <= end; ++i)
		{
			ret += string(space, ' ');
			if (i - start <= rest) ret += ' ';
			ret += words[i];
		}
		ret += string(maxWidth - ret.size(), ' ');
		return ret;
	}
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int len = -1, prev = 0;
		string line = "";
		vector<string>ret;
		for (int i = 0; i < words.size(); ++i){
			if (len + 1 + words[i].size <= maxWidth){
				len += 1 + words[i].size();
			}
			else{
				ret.push_back(getAline(words, maxWidth, prev, i - 1));
				len = words[i].size();
				prev = i;
			}
		}
		ret.push_back(getAline(words, maxWidth, prev, words.size() - 1));
		return ret;
	}
};
*/