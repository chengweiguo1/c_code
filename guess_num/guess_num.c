#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	srand((unsigned int)time(NULL));
	int  num = rand() % 100;//要100以内的数
	int  guess = 0;
	int count = 0;
	printf("请猜一个100以内的整数\n");
	while (num != guess)
	{

		count++;
		scanf_s("%d", &guess); 
		if (guess>num)
		{
			printf("猜大了，请重新输入\n");
		}
		else if (guess < num)
		{
			printf("猜小了，请重新输入\n");
		}
	}
	printf("恭喜你猜对了，本次共用了%d次\n", count);

	return 0;
}