#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n;
	//scanf("%d", &n);
	n = 3;
	int first = 1;
	for (int i = 1; i < n; i++)
	{
		first *= 10;
	}
	//printf("%d\n", first);
	
	for (int i = first; i < first * 10; i++)//第一层循环遍历
	{
		int t = i;
		int sum = 0;
		for (; t>0 ;)//第二层循环分解遍历来的i，为了防止i被破坏，新建一个变量t来存i
		{
			int d = t % 10;//取末位
			t /= 10;//除去末位剩余的部分
			int  p = d;
			for (int i=1;i<n;i++)//这层循环是求末尾的n次幂
			{
				p *= d;
			}
			sum += p;
		}
		if (sum == i)
		{
			printf("%d\n", i);
		}
	}
}