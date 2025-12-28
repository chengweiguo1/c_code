#include<stdio.h>
int  main()
{
	int x;
	int  count = 0;
	scanf_s("%d", &x);
	while (x > 0)
	{
		x /= 10;
		count++;
	}
	printf("%d\n", count);
}