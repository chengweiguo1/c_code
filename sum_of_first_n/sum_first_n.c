#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	double dividend , divisor;
	double sum = 0.0;
	double  t ;
	dividend = 1.0;
	divisor = 2.0;
	for (int i = 1; i <= n; i++)
	{
		sum += dividend / divisor;
		t = dividend;
		dividend = dividend+divisor;
		divisor = t;
	}

	printf("%.2f\n", sum);
	return 0;
}