#include <iostream>
#include <vector>
using namespace std;
//void Print(const vector<int >& v)
//{
//	cout << " 挖坑之后：";
//	for (const auto& vv : v)
//	{
//		cout << vv << " ";
//	}
//	cout << endl;
//}
int main()
{
	int n, h, cnt = 0;
	long long ret = 0;
	cin >> n >> h;
	vector<int> hu(n, h);
	for (auto& i : hu)
	{
		int m;
		cin >> m;
		i -= m;
		//cout << i << " ";
		if (i)	cnt++;//统计非零数
	}
	//cout << endl;
	//3 2 3 1 2 3 2 0 1 2 1 2
	//贪心+滑动窗口
	//int cmt = 5;
	while (cnt)
	{
		int left = 0, right = 0;
		while (left < n && hu[left] == 0) left++;
		right = left;
		// 找到最长的非零区间
		while (right < n && hu[right] != 0) right++;
		cout <<" 挖坑区间："<< left << " " << right << endl;
		for (int i = left; i < right; i++)
		{
			hu[i]--;
			if (!hu[i])	cnt--;
		}
		//Print(hu);
		ret++;
	}
	cout << ret << endl;
	return 0;
}


