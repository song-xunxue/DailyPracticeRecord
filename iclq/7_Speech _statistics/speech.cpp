#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	unordered_map<string, int> hash;
	int n;
	cin >> n;
	while (n--)
	{
		//我以为一条发言的字符去重需要超过10
		//int char_hash[58] = { 0 };
		string s;
		cin >> s;
		if (s.size() > 10)
		{
			//for (const auto& c : s)
			//{
			//	char_hash[c - 'A']++;
			//}
			//int cnt = 0;
			//for (const auto& v : char_hash)
			//{
			//	if (v) cnt++;
			//}
			//if (cnt > 10)
			hash[s]++;
		}
	}
	int ret = 0;
	for (const auto& v : hash)
	{
		//v是pair对象
		if (v.second)	ret++;
	}
	cout << ret << endl;
	return 0;
}