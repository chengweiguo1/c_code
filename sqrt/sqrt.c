#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int x;
	int n = 1;
	scanf("%d", &x);
	while (n * n <= x) {
		n++;
	}
	printf("%d", n-1);
	return 0;
}