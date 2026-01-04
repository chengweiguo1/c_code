#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int g, s, b;
	int  count = 0;
	for (b = 1; b < 5; b++)
	{
		for (s = 1; s < 5; s++)
		{
			for (g = 1; g < 5; g++)
			{
				if (g != s && g != b && s != b)
				{
					printf("%d%d%d\n", b, s, g);
					count++;
				}
			}
		}
	}
	printf("一共%d个三位数", count);
	return 0;
}