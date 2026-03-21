//#include "1_20.h"
//#include "21_40.h"

#include "41-60.h"
#include <chrono>
int main()
{
	vector<vector<int>> nums = { {1, 3},{2, 6},{8,10} ,{15,18} };
	Solution sp;
	//cout << sp.totalNQueens(4) << endl;
	auto ans=sp.merge(nums);
	for (auto& it : ans)
	{
		for (auto& x : it)
		{
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}