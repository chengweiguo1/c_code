#define _CRC_SSECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n;
	int i = 0;
	double sum = 0.0;
	double sign = 1.0;
	//scanf("%d", &n);
	n = 10000;
	for (i = 1; i <= n; i++)
	{
		sum += sign/i;
		sign = -sign;
	}
	printf("前%d项和为%f\n", n, sum);
	return 0;
}
