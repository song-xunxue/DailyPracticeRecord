#include <iostream>
#include<cmath>
//#include <bit>
using namespace std;

//位图 不过本题不需要建立映射，直接二进制就行
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		long long x;
		cin >> x;
		if (x == 0)
		{
			cout << 1 << endl;
			continue;
		}
		//cout << bit_ceil(x) << endl; C++20 不支持没办法
		cout << ceil(log2(x)) << endl;
	}
	return 0;
}