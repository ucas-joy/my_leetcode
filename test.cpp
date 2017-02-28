/*#include<iostream>
#include<string>
#include<algorithm>


class CVirtual {
public:
	virtual int GetNumber() {
		return m_nNumber;
	}
	virtual void SetNumber(int nNumber) {
		m_nNumber = nNumber;
	}
private:
	int m_nNumber;

};
int main221232()
{
	cout <<sizeof(CVirtual) << endl;
	return 0;
}
#include <iostream>
#include <set>
using namespace std;
int main4321()
{
	std::set<int> myset;
	std::set<int>::iterator it;

	// set some initial values:
	for (int i = 1; i <= 5; i++) myset.insert(i * 10);    // set: 10 20 30 40 50

	it = myset.find(21);
	if (it != myset.end())
	{
		cout << *it << endl;
	}
	else
	{
		cout << "not found" << endl;
	}

	return 0;
}
#include <iostream>
#include <map>

int main()
{
	std::map<char, int> mymap;

	// first insert function version (single parameter):
	mymap.insert(std::pair<char, int>('a', 100));
	mymap.insert(std::pair<char, int>('z', 200));

	std::pair<std::map<char, int>::iterator, bool> ret;
	ret = mymap.insert(std::pair<char, int>('z', 500));
	if (ret.second == false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	std::map<char, int>::iterator it = mymap.begin();
	mymap.insert(it, std::pair<char, int>('b', 300));  // max efficiency inserting
	mymap.insert(it, std::pair<char, int>('c', 400));  // no max efficiency inserting

													   // third insert function version (range insertion):
	std::map<char, int> anothermap;
	anothermap.insert(mymap.begin(), mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it = anothermap.begin(); it != anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}
#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
using namespace std;
int main435()
{
	string s = "eggad";
	string s3 = "daa";
	vector<int>s1 = { 1,2,3 };
	vector<int>s2 = { 1,2,3 };
	if (s1 == s2)
	{
		cout << "equal" << endl;
	}
	size_t found;
	found = s.rfind(s[4],4);
	{
		if (found != string::npos)
		{
			cout << "find" << endl;
		}
		else
		{
			cout << "not find" << endl;
		}
	}
	return 0;
}

#include<iostream>
#include<sstream>
#include<string>
using namespace  std;
int mainxasd()
{
	string s = "tmp";
	string s1 = "";
	

	/*stringstream ss;
	
	int i = 11;

	//ss << i;
	//s = s + ss.str();
	
	cout << s << endl;
	return 0;
}

#include <iostream>
#include<deque>
using namespace  std;
int main()
{
	int i = 1;
	int j = 123;
	while (j) {
		j /= 10;
		i *= 10;
	}
	cout << i << endl;
	return 0;
}
*/
//
//#include <iostream>
//#include"tree.h"
//using namespace std;
//
//int main(int argc, char argv[])
//{
//	BSNode *root = NULL;
//	BSTree bTree;
//	bTree.createTree(&root);
//	cout << 0 << endl;
//	system("pause");
//	bTree.preOrder(root);
//	system("pause");
//	bTree.inOrder(root);
//	system("pause");
//	bTree.postOrder(root);
//	system("pause");
//	return 0;
//}
//#include<iostream>
//#include<stack>
//using namespace std;
//int main()
//{
//	stack<int> s1;
//	s1.push(1);
//	s1.push(2);
//	stack<int> s2;
//	s2 = s1;
//	while (!s2.empty()) {
//		cout << s2.top();
//		s2.pop();
//	}
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n = 23;
//	int t = 0;
//	vector<int> tmp;
//	while (n != 0) {
//		t = n % 2;
//		tmp.push_back(t);
//		n = n / 2;
//	}
//	int j = 32 - tmp.size();
//	cout << j << endl;
//	for (int i = 0; i < tmp.size(); ++i) {
//		cout << tmp[i] ;
//	}
//	cout << endl;
//	for (int i = 0; i < j; ++i)
//	{
//		tmp.push_back(0);
//	}
//	cout << endl;
//	reverse(tmp.begin(), tmp.end());
//	for (int i = 0; i < tmp.size(); ++i) {
//		cout << tmp[i];
//	}
//	cout << endl;
//	for (int i = 0; i < tmp.size(); ++i) {
//		cout << tmp[i];
//	}
//	cout << endl;
//	return 0;
//}
//
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
////int main()
////{
////	string s = "abdcd";
////	s = s.substr(0, s.length() - 2); // abd
////	cout << s << endl;
////	return 0;
////}
//
//int main()
//{
//	int a = 6 ^ 5;
//	cout << a<< endl;
//}

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int a[4] = { 1,2,2,3 };
//	vector<int>b(a, a + 4);
//	b.erase(1);
//
//
//}

//#include<iostream>
//#include<string>
//#include<string>
//#include<bitset>
//using namespace std;
//
//int main()
//{
//	bitset<3>bs(6);
//
//	cout << "bs[0] is" << bs[0] << endl;
//	cout << "bs[1] is" << bs[1] << endl;
//	cout << "bs[2] is" << bs[2] << endl;
//	cout << bs << endl;
//	cout << endl;
//	string strVal("011");
//	bitset<3>bs1(strVal);
//	cout << "bs1[0]is" << bs1[0] << endl;
//	cout << "bs1[1]is" << bs1[1] << endl;
//	cout << "bs1[2]is" << bs1[2] << endl;
//	cout << endl;
//	cout << bs1 << endl;
//
//	cout << "bs1.any() =" << bs1.any() << endl;
//
//	bitset<3>bsNone;
//	cout << "bsNone.none()" << bsNone.none() << endl;
//
//	cout << "bs1.count()= " << bs1.count() << endl;
//
//	cout << "bs1.size()" << bs1.size() << endl;
//
//	bitset<3>bsFlip = bs1.flip();
//	cout << "bsFilp" << bsFlip << endl;
//
//	unsigned long val = bs1.to_ullong();
//	cout << val << endl;
//
//	return 0;
//
//
//}


//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>

//using namespace std;
//int main()
//{
//	string x = "abc";
//	reverse(x.begin(), x.end());
//	cout << x << endl;
//}

//#include<iostream>
//#include<queue>
//#include<string>
//#include<vector>
//#include<map>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	priority_queue<pair<string, int> >mq;
//	mq.push(make_pair("a", 10));
//	mq.push(make_pair("d", 40));
//	mq.push(make_pair("c", 30));
//	
//	cout << mq.size() << endl;
//	cout << (mq.top()).first << (mq.top().second) << endl ;
//
//	priority_queue<pair<int, int>>mq1;
//	mq1.push(make_pair(40, 3));
//	mq1.push(make_pair(55, 1));
//	mq1.push(make_pair(50, 2));
//
//	cout << mq1.size() << endl;
//	cout << (mq1.top()).first <<" " <<  (mq1.top()).second << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main(void)
//{
//	int i = 2;
//	int n = 1 << 2;
//	int n1 = 1 >> 1;
//	cout << n1 << endl;
//	cout << endl;
//	cout << n << endl;
//	int j;
//	for (j = 0; j < n; j++)
//	{
//		cout << (j ^ j >> 1) << endl;;
//	}
//	return 0;
////}
//
//#include<iostream>
//using namespace std;
//int main(void)
//{ 
//	int i= (2 * (3 - (4 * 5)));
//	cout << i << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//int main(void)
//{
//	string s = "123456789";
//	string t = s.substr(5);
//	cout << t << endl;
//	return 0;
//}	
//字母全排列
//#include <stdio.h>
//int main()
//{
//	char a[5] = "ABCD";
//	int i, j, k;
//	int t = 1 << 4;
//	//printf("t= %d", t);
//	for (i = 0; i < t; i++)
//	{
//		char b[5] = { 0 };
//		char * p = b;
//		j = i;
//		k = 0;
//		while (j)
//		{
//			if (j & 1)
//				*(p++) = a[k];
//			j = j >> 1;
//		//	printf("j = %d\n", j);
//			++k;
//		}
//		printf("%s\n", b);
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<vector>
//#include<set>
//using namespace std;
//
//int main()
//{
//	set<vector<int>> s2;
//	vector<int>s;
//	s.push_back(1);
//	s.push_back(1);
//	s.push_back(2);
//	s2.insert(s);
//	s.clear();
//	s.push_back(1);
//	s.push_back(1);
//	s.push_back(2);
//	s2.insert(s);
//	cout << s2.size() << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	string s = "bdac";
//	sort(s.begin(), s.end());
//	cout << s << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<vector>
//#include<map>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	map<string, int>mp;
//	mp.insert(make_pair("aaa", 1));
//	mp.insert(make_pair("bbb", 2));
//	map<string, int>::iterator it;
//	for (it = mp.begin(); it != mp.end(); ++it)
//	{
//		cout <<"first = "<< it->first <<"   , second = "<< it->second ;
//		cout << endl;
//	}
//	return 0;
//
//}

//测试bitmap
//#include<iostream>
//#include<string>
//#include<vector>
//#include<map>
//#include<bitset>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	//cout <<  << endl; 
////	cout << 'A'-'0' << endl;
//	bitset<32>bs('AC');	
//	cout << "bs[0] is " << bs[0] << endl;
//	cout << "bs[1] is " << bs[1] << endl;
//    cout << "bs[2] is " << bs[2] << endl;
//	cout << "bs[3] is " << bs[3] << endl;
//	cout << "bs[4] is " << bs[4] << endl;
//	cout << "bs[5] is " << bs[5] << endl;
//	cout << "bs[6] is " << bs[6] << endl;
//	cout << "bs[7] is " << bs[7] << endl;
//	cout << "bs[8] is " << bs[0] << endl;
//	cout << "bs[9] is " << bs[1] << endl;
//	cout << "bs[10] is " << bs[2] << endl;
//	cout << "bs[11] is " << bs[3] << endl;
//	cout << "bs[12] is " << bs[4] << endl;
//	cout << "bs[13] is " << bs[5] << endl;
//	cout << "bs[14] is " << bs[6] << endl;
//	cout << "bs[15] is " << bs[7] << endl;
//	return 0;
//}
// 测试 substr 
//#include<iostream>
//#include<string>
//#include<vector>
//#include<map>
//#include<bitset>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	string s = "abcdefg";
//	int i = 0;
//	cout << s.length();
//	while (i < s.length() - 5) {
//		cout << s.substr(i, 5) << endl; 
//		i++;
//	}
//		return 0;
//}
//测试set ， 用于去重
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<set>
//using namespace std;
//
//int main()
//{
//	set<vector<int>> st;
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	sort(v.begin(), v.end());
//	st.insert(v);
//	v.clear();
//	v.push_back(2);
//	v.push_back(1);
//	v.push_back(3);
//	sort(v.begin(), v.end());
//	st.insert(v);
//	cout << st.size() << endl;
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<set>
//using namespace std;
//int main1111()
//{
//	int nums[3] = { 1,2,2 };
//	int first = max(nums[0], max(nums[1], nums[2]));
//	int second;
//	int third = min(nums[0], min(nums[1], nums[2]));
//	for (int j = 0; j < 3; ++j)
//	{
//		if (nums[j] >= third && nums[j] < first)
//		{
//			second = nums[j];
//		}
//	}
//	
//	cout << first << endl;
//	cout << second << endl;
//	cout << third << endl;
//}
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	string word = "abcdef";
//	cout << word.length() << endl;
//	cout << word[5] << endl;
//	return 0;
//}

//test 判断一个数是什么类型
//#include <typeinfo.h>
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	int a1 = 11;
//	cout << to_string(a1) << endl ;
//	cout << typeid(to_string(a1)).name() << endl;
//	int b[4] = { 1,2,3,4 };
//	vector<int>a(b, b + 4);
//
//	return 0;
//}

//#include <typeinfo.h>
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int> a(10);
//	cout << a[0] << endl;
//	cout << a[1] << endl;
//	cout << a[2] << endl;
//	cout << a[3] << endl;
//	cout << a[4] << endl;
//	return 0;
//}
// pow 函数的简单使用
//#include <typeinfo.h>
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	cout << pow(2, 3) << endl;
//	cout << pow(2, 0) << endl;
//	cout << pow(0, 0) << endl;
//
//	return 0;
//}