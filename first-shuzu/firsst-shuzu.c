#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int x;
	int number[100];
	scanf("%d", &x);
	double sum = 0;
	int cnt = 0;
	double ave = 0;
	while (x != -1)
	{
		number[cnt] = x;
		sum += x;
		cnt++;
		scanf("%d", &x);
	}
	if (cnt > 0)
	{
		ave = sum / cnt;
		printf("average=%f\n", ave);
		for (int i = 0; i < cnt; i++)
		{
			if (number[i] > ave)
			{
				printf("%d\n", number[i]);
			}
		}
	}
	return 0;
}