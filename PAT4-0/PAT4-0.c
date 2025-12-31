#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int  main()
{
	int a;
	scanf("%d", &a);
	int i, j, k;
	int count = 0;
	for (i = a; i <= a + 3; i++)
	{
		for (j = a; j <= a + 3; j++)
		{
			for (k = a; k <=a + 3; k++)
			{
				if (i!= j && j != k && i != k)
				{
					printf("%d%d%d",i, j, k);
					count++;
					if (count == 6)
					{
						printf("\n");
						count = 0;
					}
					else {
						printf(" ");
					}
				}
			}
		}
	}
	return  0;
}