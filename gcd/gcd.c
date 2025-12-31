#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>



int  main()
{
	int  a, b;
	int t;
	scanf("%d %d", &a, &b);
	//a = 12; b = 18;
	while (b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	printf("gcd=%d", a);
	return 0;
}