/*
The n-queens puzzle is the problem of placing n queens on an n��n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
[".Q..",  // Solution 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // Solution 2
"Q...",
"...Q",
".Q.."]
]
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<int> position(n, -1);//��������һά����洢�ʺ���С���λ�ã��±��ʾ�У���ӦԪ��ֵ��ʾ��,����ʼ��
		searchSolution(position, n, 0);//�������н�,�ӵ�0�п�ʼ�����õ�1���ʺ�ע�������±�ӡ�0����ʼ
		return result;
	}
private:
	vector<vector<string>> result;//��ſ��н��������һ����ά�ַ�������
	void searchSolution(vector<int>& position, int n, int row)//Ѱ�ҿ��н�
	{
		if (row == n)//row==n��ʾN���ʺ��Ѿ����õ��Ϸ�λ�ã�Ӧ�洢���н�
		{
			vector<string> temp(n, string(n, '.'));//����һ���ַ�����������������ʽ����ʼ��ΪN*N��'.'����
			for (int i = 0; i<n; i++){
				temp[i][position[i]] = 'Q';//��ÿһ�лʺ����λ���滻��'Q',��i���ʺ�λ�ڵ�i-1�У���position[i-1]��
			}
			result.push_back(temp);//�洢�����Խ�
		}
		else{
			position[row] = 0;//���û����ϣ����Ǽ������õ�row�еĻʺ󣬵�row�еĻʺ���ܵ���λ��Ϊ��0������N-1��
			while (position[row]<n)//�ӵ�0�п�ʼ������ֱ���ҵ����Ϸ�������λ��
			{
				if (checkValid(position, n, row))//�жϵ�ǰ��λ��position[row]�Ƿ�Ϸ�
					searchSolution(position, n, row + 1);//���Ϸ�����������õ�row+1�еĻʺ�
				position[row]++;//��λ����
			}
		}
	}
	//�����row�з��õĻʺ����λ���Ƿ�Ϸ�������˼�������ǰ���row-1�лʺ����λ�ý��бȽ�
	bool checkValid(vector<int>& position, int n, int row){
		for (int i = 0; i<row; i++)//��row�лʺ�����ǰ��Ļʺ���ͬһ�У�ͬһб��,������������Ѿ����⴦��ͬһ�У�
		{
			if (position[i] == position[row] || abs(position[i] - position[row]) == abs(i - row))
				return false;
		}
		return true;
	}

};
int main51()
{
	Solution sol;
	vector<vector<string>>res = sol.solveNQueens(4);
	cout << endl;
	return 0;
}
