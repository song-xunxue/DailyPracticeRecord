#include <iostream>
#include <vector>

using namespace std;

// 计算蓄水量的函数
long long calculateWater(const vector<int>& height,int n) 
{
    vector<int> left_max(n), right_max(n);
    left_max[0] = height[0];
    right_max[n - 1] = height[n - 1];

    // 计算每个位置左边的最大高度
    for (int i = 1; i < n; ++i) 
    {
        left_max[i] = max(left_max[i - 1], height[i]);
    }
    // 计算每个位置右边的最大高度
    for (int i = n - 2; i >= 0; --i) //n-1是最好一个位置，不需要维护
    {
        right_max[i] = max(right_max[i + 1], height[i]);
    }
    long long water = 0;
    // 计算每个位置的蓄水量
    for (int i = 0; i < n; ++i) 
    {
        water += min(left_max[i], right_max[i]) - height[i];
    }
    return water;
}

//双指针维护，计算一个位置左右的最大高度
int main() {
    int m;
    cin >> m;

    while (m--) 
    {
        int n;
        cin >> n;
        vector<int> height(n);
        for (int i = 0; i < n; ++i) 
        {
            cin >> height[i];
        }
        cout << calculateWater(height,n) << endl;
    }
    return 0;
}
