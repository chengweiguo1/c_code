#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int dividend, divisor;
	scanf("%d/%d", &dividend, &divisor);
	int t;
	int a = dividend;
	int b= divisor;
	while (b > 0)//辗转相除法求最大公因数 
	{
		t = a % b;
		a = b;
		b = t;
		
	}
	printf("%d/%d", dividend / a, divisor / a);
	return 0;
}