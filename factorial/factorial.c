#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
int main()
{
	int n;
	int fact = 1;
	scanf("%d", &n);
	/*for (int i = n; n > 1; n--)
	{
		fact *= n;
	}
	*/
	for (int i = 1; i <= n; i++)
	{
		fact *= i;
	}
	printf("%d", fact);
}