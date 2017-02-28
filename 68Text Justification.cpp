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
		//����words.size() == 0 �����
		if (start > end) return string(maxWidth, ' ');
		//����ֻ��һ�����ʵ����
		if (start == end) return words[start] + string(maxWidth - words[start].size(), ' ');
		string ret = "";
		int totLen = 0;
		//ͳ�Ƶ��ʵĳ���
		for (int i = start; i <= end; ++i)
			totLen += words[i].size();
		int space = (maxWidth - totLen) / (end - start);//ÿ������ĵ�����
		int rest = (maxWidth - totLen) % (end - start);//��Ҫ�������ӿո�ļ����
		//��������һ�����⴦��
		if (end == words.size() - 1) 
		{ space = 1, rest = 0; }
		//����������ַ���
		ret += words[start];
		for (int i = start + 1; i <= end; ++i) {
			ret += string(space, ' ');
			if (i - start <= rest) //����ж���Ŀո񣬾�����ǰ������������
			{ ret += ' '; }
			ret += words[i];
		}
		//���һ�����⴦��
		ret += string(maxWidth - ret.size(), ' ');
		return ret;

	}
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int len = -1, prev = 0;  // len = -1 ��ʾ�����һ�μ����ʱ�� prev = 0 ��ʾ���е����λ��
		string line = "";
		vector<string> ret;
		for (int i = 0; i < words.size(); ++i) {
			if (len + 1 + words[i].size() <= maxWidth){
				len += 1 + words[i].size(); //�ڽ��յ������Ȼ����maxWidth
			}
			else{
				ret.push_back(getAline(words, maxWidth, prev, i - 1)); // ���� λ�ô�prev  ��  i-1 ��һ��
				//�µ�һ��
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