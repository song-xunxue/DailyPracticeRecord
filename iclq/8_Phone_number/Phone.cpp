#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
unordered_map<char, int> change;
bool compareFirstChar(const std::string& lhs, const std::string& rhs) {
	return lhs[0] < rhs[0];
}
//
//int main()
//{
//	//电话号码的第一个数字应当永远是 3 或者 6,否则错误
//	// 此外，如果电话号码中出现了 Q 和 Z，同错
//	// 3: DEF
//	// 6: MNO
//	string s;
//	vector<string> err;
//	unordered_map<string, int> hash;
//	int val = 2,epoch=8;
//	char c = 'A';
//	while (epoch--)
//	{
//		int r = 3;
//		while (r--)
//		{
//			if (c == 'Q' || c == 'Z') c++;
//			change[c] = val;
//			c++;
//		}
//		val++;
//	}
//	//for (char c = 'A'; c <= 'Z'; c++)
//	//{
//	//	cout<<c<<":"<<change[c] << endl;
//	//}
//
//	//开始读取
//	while (getline(cin, s))
//	{
//		if (s.size() == 0)	break;
//		char fri = s[0];
//		if (fri != '3' && fri != '6'
//			&& fri !='D' && fri != 'E' && fri != 'F'
//			&& fri !='M' && fri != 'N' && fri != 'O')
//		{
//			err.push_back(s);
//			continue;
//		}
//		for (const auto& c : s)
//		{
//			if (c == 'Q' || c == 'Z')
//			{
//				err.push_back(s);
//				continue;
//			}
//		}
//		//转数字串
//		for(auto& c:s)
//		{
//			if (change[c])
//			{
//				c = (char)change[c];
//				cout << s << endl;
//
//			}
//		}
//		cout <<  s << endl;
//		hash[s]++;
//
//	}
//	
//	cout << "Error:" << endl;
//	if (err.size())
//	{
//		for (const auto& c : err)
//		{
//			cout << c << endl;
//		}
//	}
//	else
//	{
//		cout << "Not found" << endl;
//	}
//	cout << "Duplication:" << endl;
//	if (hash.size())
//	{
//		for (auto& c : hash)
//		{
//			cout << "hash:" << c.first << " " << c.second << endl;
//		}
//		vector<string> sequence;
//		for (const auto& c : hash)
//		{
//			if (c.second > 1)
//			{
//				sequence.push_back(c.first);
//			}
//		}
//		if (!sequence.size())
//		{
//			cout << "Not found" << endl;
//			return 0;
//		}
//		//仿函数实现升序
//		sort(sequence.begin(),sequence.end(),compareFirstChar);
//
//		for (const auto& c : sequence)
//		{
//			cout << c << " " << endl;	
//		}
//	}
//	else
//	{
//		cout << "Not found" << endl;
//	}
//
//	return 0;
//}