#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void sum(int begin, int end)
{
	int sum = 0;
	for (int i = begin; i <= end; i++)
	{
		sum += i;
	}
	printf("sum=%d\n", sum);
}
int main()
{
	sum(1, 10);
	sum(20, 30);
	sum(35, 45);
	return 0;
}