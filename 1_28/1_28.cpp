#define _CRT_SECURE_NO_WARNINGS 1；
#include <stdio.h>
int divide(int a, int b, int* result);
int main()
{
	int a = 5;
	int b = 0;
	int c;
	if (divide(a, b, &c))
	{
		printf("a/b=%d", c);
	}
	else {
		printf("除数不能为零");
	}
	
	return 0;
}
int divide(int a, int b, int* result)
{
	
	int ret=1;
	if (b == 0)
	{
		ret = 0;
	}
	else {
		*result = a / b;
	}
	return ret;
}

