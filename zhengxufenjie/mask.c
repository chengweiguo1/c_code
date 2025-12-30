#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
	int x ;
	scanf("%d", &x);
	int mask = 1;
	//int  cnt = 0;
	int t = x;
	while (t > 9)
	{
		t /= 10;
		//cnt++;
		mask *= 10;
		//printf("%d\n", cnt);
	}
	//mask = pow(10, cnt - 1);
	printf("%d\n",mask);
	while (mask>0)
	{
		int d = x / mask;	//13425/10000->1
		printf("%d", d);
		if (mask > 9)
		{
			printf(" ");
		}
		x %= mask;		//13425%10000->3425
		mask /= 10;		//10000/10->1000

	}

}