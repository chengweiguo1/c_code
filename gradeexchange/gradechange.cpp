#include<stdio.h>
int main()
{
	int grade = 0;
	scanf_s("%d", &grade);
	int num = grade / 10;
	switch (num)
	{
	case  10:
	case 9:
		printf("A");
		break;
	case 8:
		printf("B");
		break;
	case 7:
		printf("C");
		break;
	case 6:
		printf("D");
		break;
	default:
		printf("E");
		break;
	}
	return  0;
}