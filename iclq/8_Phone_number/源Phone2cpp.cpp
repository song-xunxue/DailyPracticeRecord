#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<cstdio> 
#include<cstring> 
#include<cmath> 
#include<cstdlib> 
#include<clocale> 
using namespace std;

unsigned char hash_str[250010];
struct table
{
	long long int tele_numb;
	int dupli_time;
};
struct table result[1510];

long long int str_trans(char* str0)
{
	char* p;
	long long int number = 0;
	int flag = 1, count = 0;
	p = str0;
	while (1)
	{
		if (*p == '\0')
		{
			break;
		}
		if (*p == 'Q' || *p == 'Z')
		{
			flag = 0;
			break;
		}
		if (*p == '-')
		{
			p++;
		}
		else if (count == 0 && *p != '3' && *p != '6' && *p != 'D' && *p != 'E' && *p != 'F' && *p != 'M' && *p != 'N' && *p != 'O')
		{
			flag = 0;
			break;
		}
		else
		{
			if (*p == 'A' || *p == 'B' || *p == 'C' || *p == '2')
			{
				number = number * 10 + 2;
				count++;
			}
			else if (*p == 'D' || *p == 'E' || *p == 'F' || *p == '3')
			{
				number = number * 10 + 3;
				count++;
			}
			else if (*p == 'G' || *p == 'H' || *p == 'I' || *p == '4')
			{
				number = number * 10 + 4;
				count++;
			}
			else if (*p == 'J' || *p == 'K' || *p == 'L' || *p == '5')
			{
				number = number * 10 + 5;
				count++;
			}
			else if (*p == 'M' || *p == 'N' || *p == 'O' || *p == '6')
			{
				number = number * 10 + 6;
				count++;
			}
			else if (*p == 'P' || *p == 'R' || *p == 'S' || *p == '7')
			{
				number = number * 10 + 7;
				count++;
			}
			else if (*p == 'T' || *p == 'U' || *p == 'V' || *p == '8')
			{
				number = number * 10 + 8;
				count++;
			}
			else if (*p == 'W' || *p == 'X' || *p == 'Y' || *p == '9')
			{
				number = number * 10 + 9;
				count++;
			}
			else if (*p == '1' || *p == '0')
			{
				number = number * 10 + *p - '0';
				count++;
			}
			p++;
		}

	}
	if (count != 7)
	{
		flag = 0;
	}
	if (flag == 0)
	{
		return 0;
	}
	else if (flag == 1)
	{
		return number;
	}
	else return -1;
}
int check_dupli(long long int stat, int j)
{
	long long int x, y, f;
	int k, flag = 1;
	f = stat / (long long int)1000000;
	if (f == 3)
	{
		x = (stat % (long long int)1000000) / 8;
	}
	else if (f == 6)
	{
		x = (long long int)125000 + (stat % (long long int)1000000) / 8;
	}
	y = stat % 8;
	if (((hash_str[x] >> y) & 1) == 0)
	{
		hash_str[x] = hash_str[x] | (1 << y);
		return 0;
	}
	else if (((hash_str[x] >> y) & 1) == 1)
	{
		for (k = 0; k < j; k++)
		{
			if (stat == result[k].tele_numb)
			{
				result[k].dupli_time++;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			result[j].tele_numb = stat;
			result[j].dupli_time++;
			return 1;
		}
		else if (flag == 0)
		{
			return 0;
		}
	}
	else return -1;
	return -1;
}

int cmp(const void* a, const void* b)
{
	return ((*(struct table*)a).tele_numb > (*(struct table*)b).tele_numb) ? 1 : -1;
}

int main()
{
	int t;
	long long int i, sta;
	char str[21];
	int count_error = 0, count_dupli = 0;
	printf("Error:\n");
	while (scanf("%s", str) != EOF)
	{
		t = getchar();

		sta = str_trans(str);

		if (sta == 0)
		{
			printf("%s\n", str);
			count_error++;
		}
		else
		{
			count_dupli = count_dupli + check_dupli(sta, count_dupli);
		}
	}
	if (count_error == 0)
	{
		printf("Not found.\n");
	}
	printf("\nDuplication:\n");
	if (count_dupli == 0)
	{
		printf("Not found.\n");
	}
	else
	{
		qsort(result, count_dupli, sizeof(struct table), cmp);
		for (i = 0; i < count_dupli; i++)
		{
			printf("%lld-", ((result[i]).tele_numb / 10000));
			printf("%04lld ", ((result[i]).tele_numb % 10000));
			printf("%d\n", (result[i]).dupli_time + 1);
		}
	}

}