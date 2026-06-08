#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct cmp 
{  
	bool operator()(pair<int, int> a, pair<int, int> b) 
	{
		if (a.second < b.second)
			return true;
		else
			return false;
	}
};


int main()
{
	long T, ret=1;
	//ifstream inputFile("in.txt");

	//inputFile >> T;
	cin >> T;
	long long begin=0, end=0;
	vector<pair<int, int>> v;
	while (T--)
	{
		cin >> begin >> end;
		v.push_back({ begin,end });

	}
	sort(v.begin(), v.end(), cmp());
	int cur = v[0].second;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].first >= cur) {
			cur = v[i].second;
			ret++;
		}
	}
	cout << ret << endl;
	return 0;
}