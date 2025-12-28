#include<easyx.h>
#include<stdio.h>
int main() {
	initgraph(600, 700);
	circle(320, 240, 200);
	getchar();
	closegraph();
	return 0;
}