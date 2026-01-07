#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	const int number = 25;
	int isPrime[25];
	int i;
	for (i = 0; i < number; i++)//初始化数组
	{
		isPrime[i] = 1;
	}
	int  x = 2;
	while (x<number)
	{
		if (isPrime[x]) {
			for (i = 2; i * x < number; i++)
			{
				isPrime[i * x] = 0;
			}
		}
		x++;
	}
	for (i = 2; i < number; i++)
	{
		if (isPrime[i])
		{
			printf("%d\t", i);
		}
	}
	return 0;
}