#include<stdio.h>
int main()
{
	int money = 0, cash = 0,change=0;
	scanf_s("%d %d",&money,&cash );
	if (money <= cash)
	{
		change = cash - money;
		printf("Ó¦ÕÒÁã%dÔª", change);
	}
	else {
		printf("Óà¶î²»×ã");
	}

	return  0;
}