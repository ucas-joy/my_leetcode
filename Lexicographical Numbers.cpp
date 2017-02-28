/*386. Lexicographical Numbers
Total Accepted : 195
Total Submissions : 1587
Difficulty : Medium
	Given an integer n, return 1 - n in lexicographical order.

	For example, given 13, return : [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9].

	*/
/*
public class Solution {
    public List<Integer> lexicalOrder(int n) {
    List<Integer>list=new ArrayList<Integer>(n);
        if(n<=9){
            for(int i=1;i<=n;i++){
                list.add(i);
            }
        }
        else{
            for(int i=1;i<=9;i++){
                list.add(i);
                doAdd(list, i, n);//每次doAdd都是把以i开头的数字都加入List中
            }
        }
        return list;
    }

    public static void doAdd(List<Integer>list,int start,int n){
            int moreBit=start*10;
            if(moreBit<=n){
                int ceil=n-moreBit;
                int ans;
                ceil=ceil>9?9:ceil;
                for(int i=0;i<=ceil;i++){
                    ans=moreBit+i;
                    list.add(ans);
                    doAdd(list, ans, n);
                }
            }
    }
}
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int>lexicalOrder(int n) {
		vector< int>lex;
		if (n < 10) {
			for (int i = 1; i < n; ++i) {
				lex.push_back(i);
			}
		}
		else
		{
			for (int i = 1; i < 9; ++i) {
				lex.push_back(i);
				add(lex, i, n);
			}
		}
		return lex;
	}
	void add(vector<int>&l, int start, int n) {
		int morebit = start * 10;
		if (morebit <= n) {
			int ce = n - morebit;
			int ans;
			ce = ce > 9 ? 9 : ce;
			for (int i = 0; i <= ce; ++i) {
				ans = morebit + i;
				l.push_back(ans);
				add(l, ans, n);
			}
		}
	}
};
int main()
{
	int n = 15;
	vector<int> ve;
	Solution sol;
	ve = (sol.lexicalOrder(n));
	int len = ve.size();
	int i = 0;
	while (i < len) {
		cout << ve[i] << endl;
		i++;
	}
	return 0;
}