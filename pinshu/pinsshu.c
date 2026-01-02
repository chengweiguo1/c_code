#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a, n;
	scanf("%d %d", &a, &n);
	int  sum = 0;
	int t = 0;
	for (int i = 1; i <= n;i++)
	{
		t = t * 10 + a;
		sum += t;
	}
	printf("sum=%d", sum);
	return 0;
}