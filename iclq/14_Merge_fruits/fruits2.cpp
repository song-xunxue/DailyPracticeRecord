//¼òµ¥Ä£ÄâµÄ¹ş·òÂüÊ÷

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T,ret=0;
	cin >> T;
	vector<int> v;
	while (T--)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	int n = v.size();
	sort(v.begin(), v.end());

	while (n > 1)
	{
		int sum = v[0]+v[1];
		ret += sum;
		v.erase(v.begin());
		v.erase(v.begin());
		n -= 2;
	}
	if (n == 1)
	{
		ret += v[0];
	}
	cout << ret << endl;
	
	return 0;
}