#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//提交记得把那个打印调试给注释完，我一直以为哪里有问题，最后发现有一个换行没有注释掉

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));
    vector<int> maxns(n, 1);//行
    vector<int> maxms(m, 1);

    // 读取输入并计算每行和每列的最大值
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> nums[i][j];
            maxns[i] = max(maxns[i], nums[i][j]);
            maxms[j] = max(maxms[j], nums[i][j]);//这个不好处理了
        }
    }
   
    vector<vector<int>> lawns(n);//初始草坪
    // 检查是否可以修剪成输入的图案
    for (int i = 0; i < n; ++i) {
        lawns[i].resize(m, maxns[i]);
        //cout <<"maxns[i]:" << maxns[i] << endl;
        for (int j = 0; j < m; ++j) {
            //cout << lawns[i][j] << "-->";

            if (lawns[i][j] > maxms[j]) {
                lawns[i][j] = maxms[j];
            }
            //cout << lawns[i][j] << " ";
        }
        //cout << endl;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (lawns[i][j] !=nums[i][j]) {
                cout << "NO" << endl;
                //cout << i << " " << j << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    return 0;
}



	//for (const auto& v : maxms)
	//{
	//	cout << v << endl;
	//}
	//for (const auto& v : maxns)
	//{
	//	cout << v << endl;
	//}
	//检查
	//for (const auto& v : nums)
	//{
	//	for (const auto& vv : v)
	//	{
	//		cout << vv<<" ";
	//	}
	//	cout << endl;
	//}

