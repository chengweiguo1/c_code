#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int scan_result=scanf("%d", &a);
//	if (scan_result != 1)
//	{
//		if (scan_result == EOF)
//		{
//			printf("错误");
//		}
//		else {
//			printf("错误，输入一个整数");
//		}
//		return 1;
//	}
//	int m = 0, n = 0;
//	m = a / 16;
//	n = a % 16;
//	printf("%d", m * 10 + n);
//	return 0;
//}
int main()
{
	int a = 0;
	int scan_result = scanf("%d", &a);
	if (scan_result != 1)
	{
		if (scan_result == EOF)
		{
			printf("错误");
		}
		else {
			printf("错误，输入一个整数");
		}
		return 1;
	}
	printf("%x", a);//十六进制输出格式
	
	return 0;

}