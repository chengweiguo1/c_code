#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<stdalign.h>
int main()
{
	int x = 0;
	//x = 789;
	int ret = 0;
	int digit;
	scanf("%d", &x);
	while (x>0)
	{
		digit = x % 10;
		x /= 10;
		ret = ret * 10 + digit;
		//printf("%d", ret);
	}
	printf("%d", ret);
	return 0;
}