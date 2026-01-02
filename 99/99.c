#define CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i ,j;
	for (i = 1; i <= 9; i++)
	{
		int count = 0;
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d", i, j, i * j);
			if (i * j < 10)
			{
				printf("   ");
			}
			else {
				printf("  ");
			}
			count++;
		}
		printf("\n");
	}
	return 0;
}