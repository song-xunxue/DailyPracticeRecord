//北理工的恶龙
//背景：
//最近，北理工出现了一只恶龙，它长着很多 头，而且还会吐火，它将会把北理工烧成废墟，
// 于是，校长下令召集全校所有勇士杀死这只恶龙。要杀死这只龙，必须把它所有的头都砍掉，
// 每个勇士只能砍一个龙头，龙的每个头大小都不一样，一个勇士只有在身高不小于龙头的直径的情况下才能砍下它。
// 而且勇士们要求，砍下一个龙头必须得到和自己身高厘米数一样的学分。校长想花 最少的学分数 杀死恶龙，
// 于是找到你寻求帮助。
//
//输入：
//第一行 龙头数 n, 勇士人数 m （ 1 <= n, m <= 100 ） 
// 接下来 n 行，每行包含一个整数，表示龙头的直径 
// 接下来 m 行，每行包含一个整数，表示勇士的身高 l
//
//输出：
//如果勇士们能完成任务，输出校长需要花的最小费用；否则输 出 “bit is doomed!”

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		for (int j = 1; j < n - i; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				Swap(&arr[j - 1], &arr[j]);
				flag = 1;
			}
		}
		if (flag = 0)
			//一次交换都没有，快速结束排序
			break;
	}
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	if (n > m)
	{
		printf("bit is doomed!\n");
		return 0;
	}
	int* arr1 = (int*)malloc(sizeof(int) * n);
	int* arr2 = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&arr1[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d",&arr2[i]);
	}
	BubbleSort(arr1, n);
	BubbleSort(arr2, m);
	//统计杀死的龙的数量
	int count = 0;
	int credit = 0;//学分总数
	for (int i = 0; i < m;i++)
	{
		//从低向高匹配
		if (arr1[count] <= arr2[i])
		{
			//printf("%d->%d %d\n",count, arr1[count], arr2[i]);
			count++;
			credit += arr2[i];
			
		}
		if (count == n)	break;
	}
	if (count != n)
	{
		printf("bit is doomed!\n");
		return 0;
	}
	printf("%d\n", credit);
	return 0;
}