/*
A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

For 1-byte character, the first bit is a 0, followed by its unicode code.
For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.
This is how the UTF-8 encoding would work:

Char. number range  |        UTF-8 octet sequence
(hexadecimal)    |              (binary)
--------------------+---------------------------------------------
0000 0000-0000 007F | 0xxxxxxx
0000 0080-0000 07FF | 110xxxxx 10xxxxxx
0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

Note:
The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. 
This means each integer represents only 1 byte of data.

Example 1:

data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.

Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
Example 2:

data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.

Return false.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.
Subscribe to see which companies asked this question
*/
/*
����⿼������UTF-8���룬���ֻ����������õ�ͨ�õı����ʽ�Ĳ�����Ϊ�˽��ASCIIֻ�ܱ�ʾӢ���ַ��ľ����ԣ���ͳһUnicode��ʵ�ַ�ʽ���������ժ��ά���ٿ�UTF-8���룺

����UTF-8�����е������ֽ�B�����B�ĵ�һλΪ0����B�����ı�ʾһ���ַ�(ASCII��)��
���B�ĵ�һλΪ1���ڶ�λΪ0����BΪһ�����ֽ��ַ��е�һ���ֽ�(��ASCII�ַ�)��
���B��ǰ��λΪ1������λΪ0����BΪ�����ֽڱ�ʾ���ַ��еĵ�һ���ֽڣ�
���B��ǰ��λΪ1������λΪ0����BΪ�����ֽڱ�ʾ���ַ��еĵ�һ���ֽڣ�
���B��ǰ��λΪ1������λΪ0����BΪ�ĸ��ֽڱ�ʾ���ַ��еĵ�һ���ֽڣ�
��ˣ���UTF-8�����е������ֽڣ����ݵ�һλ�����ж��Ƿ�ΪASCII�ַ�������ǰ��λ��
���жϸ��ֽ��Ƿ�Ϊһ���ַ�����ĵ�һ���ֽڣ�����ǰ��λ�����ǰ��λ��Ϊ1����
��ȷ�����ֽ�Ϊ�ַ�����ĵ�һ���ֽڣ����ҿ��ж϶�Ӧ���ַ��ɼ����ֽڱ�ʾ��
����ǰ��λ�����ǰ��λΪ1�������жϱ����Ƿ��д�������ݴ���������Ƿ��д���

��ô������������������ǿ��������жϵ�һλ�������0�Ļ�����˵����ASCII�룬����ֱ��������
�жϷ�����ֻҪ�ȶ�������10000000С������һλ�϶���0��Ȼ�������������һλ��1�������
���ڵ�һλ��1ֻ�Ǹ���ʶ����������������1�ĸ������Ǳ�ʾ������ֽڵĸ�����
���ǿ���ͳһ�ӵ�һλ��ʼ����1�ĸ�����Ȼ���ȥ1���Ǻ�����ֽڵĸ�����
����İ취����������ִ��ڵ���128�����ʾ��һλ��1��Ȼ���ȥ128������õ��������ڵ���64��
���ʾ�ڶ�λ��1���������ƾͿ��Եõ������ĸ���������Ҫע��10000000������ǲ��Ϸ��ģ�
������ֱ�ӷ���false�����ǵõ���cnt�ĸ�����ֻҪ��֤������ֽ��Ƿ�����10��ͷ�������ɣ�
��֤����Ҳ�ܼ򵥣�ֻҪ�������10000000 ~ 10111111��Χ֮�䣬��һ����10��ͷ�ģ�
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool validUtf8(vector<int>& data) {
		for (int i = 0; i < data.size(); ++i){
			if (data[i] < 0b10000000) {
				continue;
			}
			else{
				int cnt = 0, val = data[i];
				for (int j = 7; j >= 1; --j) {
					if (val >= pow(2, j))++cnt;
					else break;
					val -= pow(2, j);
				}
				if (cnt == 1) return false;
				for (int j = i + 1; j < i + cnt; ++j){
					if (data[j] > 0b10111111 || data[j] < 0b10000000) return false;
				}
				i += cnt - 1;
			}
		}
		return true;
	}
};


/*
bool validUtf8(vector<int>& data) {
		for (int i = 0; i < data.size(); ++i) {
			if (data[i] < 0b10000000) {
				continue;
			}
			else {
				int cnt = 0, val = data[i];
				for (int j = 7; j >= 1; --j) {
					if (val >= pow(2, j))++cnt;
					else break;
					val -= pow(2, j);
				}
				if (cnt == 1) return false;
				for (int j = i + 1; j < i + cnt; ++j) {
					if (data[j] > 0b10111111 || data[j] < 0b10000000) return false;
				}
				i += cnt - 1;
			}
		}
		return true;
	}
*/
