#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int one, two, five;
	int x = 2;
	//scanf("%d", &x);
	for (one = 1; one < x * 10; one++)
	{
		for (two = 1; two < x * 10 / 2; two++)
		{
			for (five = 1; five < x * 10 / 5; five++)
			{
				if (one + two * 2 + five * 5 == x*10)
				{
					printf("用%d个一角和%d个两角和%d个五角可以凑出%d元\n", one, two, five, x);
					goto out;
				}
			}
		}
	}
out:
	return 0;
}