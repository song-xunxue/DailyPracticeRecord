#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct cmp
{
	bool operator()(pair<int,int> a, pair<int, int> b) {
		if(a.second>0 && b.second>0)
			return a.first < b.first;
		else if(a.second < 0 && b.second < 0)
		{
			return (a.first+a.second) > (b.first+b.second);//对于负收益的，打损耗小的优先
		}
		else
		{
			return a.second > b.second;
		}
		//return a.first < b.first;

	}
};

int main()
{
	ifstream inputFile("in.txt");
	int T;
	cin >> T;
	//inputFile >> T;
	vector<pair<int, int>> nums;
	while (T--)
	{
		int a, b;
		cin >> a >> b;
		//inputFile >> a >> b;
		nums.push_back({ a, b });
	}
	sort(nums.begin(), nums.end(), cmp());

	long long current = 0;//攻击力 又被 long long 坑了一把
	long long ret=0;//氪金
	for (auto& v : nums)
	{
		//cout << v.first << " " << v.second << endl;
		////cout << current << " " << ret << endl<<endl;
		long long first = v.first;
		if (first > current)
		{
			//cout << " 氪金：" << first - current << endl;
			ret += (first - current);
			current += (first - current);
		}
		current+=v.second;
	}

	cout << ret << endl;

	return 0;
}