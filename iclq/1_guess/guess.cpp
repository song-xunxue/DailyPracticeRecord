#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

// 类似二分查找
int main()
{
    while (1)
    {
        int left = 0, right = 10;
        int x;
        int flag=0;//中间检测标志位
        while (1)
        {
            if (scanf("%d", &x) != 1) break; // 检查输入是否成功
            if (x == 0) break;
            string s;
            cin.ignore(); // 忽略换行符
            getline(cin, s);
            if (s.back() == 'w')
            {
                if (x > right) {
                    flag = 1;
                    break;
                } // 更新左边界
                left = x+1;
            }
            else if (s.back() == 'h')
            {
                if (x < left)
                {
                    flag = 1;
                    
                }
                right = x-1; // 更新右边界
            }
            else
            {
           
                if (x < left || x > right) {
                    flag = 1;
                    break;
                }
                break;
            }
        }
        if (x == 0) break;
        if(flag)    cout << "Tom is dishonest" << endl;
        else
        {
            cout << "Tom may be honest" << endl;
        }
        
    }
    return 0;
}
