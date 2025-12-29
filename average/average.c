
#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
int main()
{
	int sum = 0, count = 0;
	int num ;
	double average = 0;
	printf("请输入整数\n");
	scanf("%d", &num);
	while(num!=-1)
	{ 
		count++;
		sum += num;
		scanf_s("%d", &num);
	}
	average = 1.0*sum / count;
	printf("平均值是%f\n", average);
	return  0;
}