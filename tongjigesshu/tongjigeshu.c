#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int x;
	int count[10];
	int i;
	for (i = 0; i < 10; i++)//初始化count的值
	{
		count[i] = 0;
	}
	scanf("%d", &x);
	while (x != -1)
	{
		if (x >= 0 && x <= 9)
		{
			count[x]++;
		}
		scanf("%d", &x);
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d出现了%d次\n", i, count[i]);
	}
	return 0;
}