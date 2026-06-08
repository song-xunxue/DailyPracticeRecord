#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

typedef long long ll;

int main() 
{
	int n;
	cin >> n;
	vector<ll> x(n), y(n);
	for (int i = 0; i < n; ++i) 
	{
		cin >> x[i] >> y[i];
	}

	// 计算纵坐标的最优值 y_final
	vector<ll> y_sorted = y;
	sort(y_sorted.begin(), y_sorted.end());
	ll y_final = y_sorted[n / 2]; // 中位数 偶数就是后一位，不是取的平均，这里题目没讲清楚

	// 计算纵坐标距离和
	ll y_dist = 0;
	for (int i = 0; i < n; ++i) 
	{
		y_dist += abs(y[i] - y_final);
	}

	// 计算横坐标的最优排列
	vector<ll> x_sorted = x;
	sort(x_sorted.begin(), x_sorted.end());
	vector<ll> z(n);
	for (int i = 0; i < n; ++i) 
	{
		z[i] = x_sorted[i] - i; // z_i = x_{(i)} - (i-1) 注意 i 从 0 开始，所以是 i
	}
	sort(z.begin(), z.end());
	ll k = z[n / 2]; // z_i 的中位数 

	// 计算横坐标距离和
	ll x_dist = 0;
	for (int i = 0; i < n; ++i) 
	{
		x_dist += abs(z[i] - k);
	}

	// 总距离和
	ll total_dist = y_dist + x_dist;
	printf("%lld\n", total_dist);

	return 0;
}