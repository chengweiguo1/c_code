#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	double x;
	int n;
	scanf("%lf %d", &x, &n);
	double ret = 1.0;
	if (x == 0 && n < 0)
	{
		printf("0不能做分母，无意义");
		return 1;
	}
	int negative = 1;
	if (n < 0) {
		n = -n;
		negative = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		ret *= x;
	}
	if (negative == 0)
	{
		ret = 1 / ret;
	}
	printf("%lf\n", ret);
	return 0;
}