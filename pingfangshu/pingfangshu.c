#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//一个整数加上100后是一个完全平方数，再加上168后还是完全平方数，该数是多少
int main()
{
	int  i, j;
	int  m = 0;
	int x;
	for (i = 2; i <= 84; i += 2)
	{
		if (168 % i == 0) {
			j = 168 / i;
			if (i > j)
			{
				m = (i - j) / 2;
				x = m * m - 100;
				if ((m * m == x + 100) && (((m * m) + 168) == ((i + j) / 2) * ((i + j) / 2)))
				{
					printf("%d\n", x);
				}
			}
		}
	}
	return 0;
}