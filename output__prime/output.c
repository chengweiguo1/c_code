#define  _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
int main()
{
	//输出 100以内的素数，在判断是不是素数的基础上循环嵌套
	int x = 100;

	for (x= 2; x < 100; x++)
	{
		
		int isPrime = 1;
		for (int i = 2; i < x; i++)
		{
			if (x % i == 0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime == 1)
		{
			printf("%d\n",x);
		}
		/*else {
			printf("不是素数");
		}*/
	}
}