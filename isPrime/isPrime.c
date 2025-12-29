#define  _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
int main()
{
	int x;
	scanf("%d", &x);
	int isPrime = 1;
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
		{
			isPrime = 0;
			break;//
		}
	}
	if (isPrime == 1)
	{
		printf("是素数");
	}
	else
	{
		printf("不是素数");
	}
	return 0;
}