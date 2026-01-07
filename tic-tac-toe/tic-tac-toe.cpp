#define _CRT_SECURE_NO_WARNINGS 1；
#include  <stdio.h>
int  main()
{
	const int size = 3;
	int block[size][size];
	int i,j;
	int result = -1;//-1没人赢，1是x赢，0是o赢
	int numofO;
	int numofX;
	//输入数组
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			scanf("%d", &block[i][j]);
		}
	}
	//判断行
	for (i = 0; i < size && result == -1; i++)
	{
		numofO = numofX = 0;
		for (j = 0; j < size; j++)
		{
			if (block[i][j] == 1)
			{
				numofX++;
			}
			else
			{
				numofO++;
			}
		}
		if (numofX == size)
		{
			result = 1;
		}
		else if (numofO == size)
		{
			result = 0;
		}
	}
	//判断列
	for (j = 0; j < size && result == -1; j++)
	{
		numofO = numofX = 0;
		for (i = 0; i < size; i++)
		{
			if (block[i][j] == 1)
			{
				numofX++;
			}
			else
			{
				numofO++;
			}
		}
		if (numofX == size)
		{
			result = 1;
		}
		else if (numofO == size)
		{
			result = 0;
		}
	}
	//判断对角线-左上到右下
	numofO = numofX = 0;
	for (i = 0; i < size; i++)
	{
		if (block[i][i] == 1)
		{
			numofX++;
		}
		else {
			numofO++;
		}
		if (numofX == size)
		{
			result = 1;
		}
		else if (numofO == size)
		{
			result = 0;
		}
	}
	//右上到坐下
	numofO = numofX = 0;
	for (i = 0; i < size; i++)
	{
		if (block[i][size-i-1] == 1)
		{
			numofX++;
		}
		else {
			numofO++;
		}
		if (numofX == size)
		{
			result = 1;
		}
		else if (numofO == size)
		{
			result = 0;
		}
	}
	if (result == 1)
	{
		printf("Xwin\n");
	}
	else if (result == 0)
	{
		printf("Owin\n");
	}
	else
	{
		printf("none win\n");
	}
	return 0;
}