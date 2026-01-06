#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int search(int key, int a[], int length);

	int a[] = { 2,4,6,7,1,3,5,9,11,13,23,14,32 };
	int x;
	printf("请输入一个数:");
	scanf("%d", &x);
	int location;
	location = search(x, a, sizeof(a) / sizeof (a[0]));
	if (location == -1)
	{
		printf("未找到\n");
	}
	else {
		printf("数字%d是第%d个数字\n", x, location);
	}
	return 0;
}
int search( int key, int a[], int length)
{
	int ret = -1;
	for (int i = 0; i < length; i++)
	{
		if (key == a[i])
		{
			ret = i;
			break;
		}
	}
	return ret;
}