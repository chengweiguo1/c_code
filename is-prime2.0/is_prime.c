#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>

int isPrime(int x, int knownprime[], int num_of_knownprime);
int main()
{
	int const num = 100;
	int prime[100] = { 2 };
	int count = 1;//素数的个数，同时为下一个素数进数组的下标
	int i;
	for (i = 3; count < num; i++)
	{
		if (isPrime(i, prime, count) == 1)
		{
			prime[count++] = i;
		}
	}
	for (i = 0; i < num; i++)
	{
		printf("%3d", prime[i]);
		if ((i + 1) % 5 )
		{
			printf("\t");
		}
		else {
			printf("\n");
		}
	}

	return 0;
}

int	isPrime(int x, int knownprime[], int num_of_knownprime)//判断素数，看一个数能否整除比他小的素数，不能则为素数
{
	int  ret = 1;
	for (int i = 0; i < num_of_knownprime; i++)
	{
		if (x % knownprime[i] == 0)
		{
			ret = 0;
			break;
		}
	}
	return ret;
}
		