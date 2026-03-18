//#include "1_20.h"
//#include "21_40.h"

#include "41-60.h"

int main()
{
	vector<int> nums = { 1,1,2 };
	Solution sp;
	auto it = sp.permuteUnique(nums);
	for (auto& v : it)
	{
		for (auto& x : v)
		{
			cout << x << " ";
		}
		puts("");
	}


	return 0;
}