#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int m, n;
	int i;
	scanf("%d %d", &m, &n);
	int cnt = 0;
	int sum = 0;
	if (m == 1)
	{
		m = 2;
	}
	for (i = m; i <= n; i++)
	{
		int isPrime = 1;
		for (int j = 2; j <= i/2; j++)
		{
			if (i % j == 0)
			{
				isPrime = 0;
				break;
			}
		}
		if (isPrime)
		{
			cnt++;
			sum += i;
		}
	}
	printf("%d %d\n", cnt, sum);
	return 0;
}