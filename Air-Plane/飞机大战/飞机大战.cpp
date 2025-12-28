
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<wchar.h>

#pragma comment(lib,"Winmm.lib")

#ifndef RGBA
#define RGBA(r, g, b, a) ((COLORREF)((((BYTE)(r)) | ((WORD)((BYTE)(g)) << 8)) | (((DWORD)(BYTE)(b)) << 16)) | (((DWORD)(BYTE)(a)) << 24)))
#endif 

#ifndef _UNICODE
#define _UNICODE
#endif // !_UNICODE


#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 800
#define PLANE_SIZE 50
#define ENEMY_NUM 8
#define ENEMY_SPEED 1.0
#define BULLET_NUM 10
#define PI 3.14

int playerHP = 100;
const int MAX_HP = 100;
bool isGameOver = false;
typedef  struct pos
{
	int x;
	int y;
}POS;

typedef struct plane
{
	POS planePOS;
	POS planeBullets[BULLET_NUM];
	int bulletLen;
	int bulletSpeed;
}PLANE;

PLANE myPlane;
PLANE enemyPlanes[ENEMY_NUM];
int enemyPlaneLen;
static time_t startTime, endTime;
IMAGE img[4];
int score = 0;

void initGame();
void drawGame();
void updateGame();
void updateBullets();
void checkBulletBound();
void updateEnemyPlanes();
void drawHPBar();
void drawGameOver();
void checkPlayerEnemyHit();

void initGame()
{
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	score = 0;

	playerHP = MAX_HP;
	isGameOver = false;//初始游戏未结束

	srand((unsigned)time(NULL));
	myPlane.bulletLen = 0;
	myPlane.bulletSpeed = 3;
	myPlane.planePOS = { SCREEN_WIDTH / 2 - PLANE_SIZE / 2+20,SCREEN_HEIGHT - PLANE_SIZE };

	enemyPlaneLen = 3;
	for (int i = 0; i < enemyPlaneLen; i++)
	{
		enemyPlanes[i].planePOS.x = rand() % (SCREEN_WIDTH - PLANE_SIZE) + PLANE_SIZE / 2;
		enemyPlanes[i].planePOS.y = rand() % 200 - PLANE_SIZE / 2;
		enemyPlanes[i].bulletLen = 0;
		enemyPlanes[i].bulletSpeed = 3;
	}

	startTime = NULL;
	PlaySound(_T("D:/code/vs/飞机大战/飞机大战/bgm.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	
}

void drawHPBar()
{
	//生命值条背景
	setfillcolor(RGB(100, 100, 100));
	solidrectangle(50, 20, 350, 40);

	//生命值条
	setfillcolor(RGB(255, 0, 0));
	int hpBarWidth = (playerHP * 300) / MAX_HP;
	solidrectangle(50, 20, 50 + hpBarWidth, 40);

	//生命值文字
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	settextstyle(20, 0, _T("微软雅黑"));
	TCHAR hpText[20];
	swprintf_s(hpText,_countof(hpText), _T("血量: %d/%d"), playerHP, MAX_HP);
	outtextxy(150, 40, hpText);
}

void drawGameOver()
{
	setfillcolor(RGBA(0, 0, 0, 180);
	solidrectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	settextcolor(RED);
	settextstyle(60, 0, _T("微软雅黑"));
	outtextxy(SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT / 2 - 50, _T("游戏结束"));

	settextcolor(WHITE);
	settextstyle(30, 0, _T("微软雅黑"));
	TCHAR scoreText[30];
	swprintf_s(scoreText,_countof(scoreText), _T("最终分数:%d"), score);
	outtextxy(SCREEN_WIDTH / 2 - 80, SCREEN_HEIGHT / 2 + 20, scoreText);

	settextstyle(20, 0, _T("微软雅黑"));
	outtextxy(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 80, _T("按esc退出"));
}

void checkPlayerEnemyHit()
{
	if (isGameOver)return;
	for (int i = 0; i < enemyPlaneLen; i++)
	{
		int pLeft = myPlane.planePOS.x - PLANE_SIZE / 2;
		int pTop = myPlane.planePOS.y - PLANE_SIZE / 2;
		int pRight = myPlane.planePOS.x + PLANE_SIZE / 2;
		int pBottom = myPlane.planePOS.y + PLANE_SIZE / 2;

		int eLeft = enemyPlanes[i].planePOS.x - PLANE_SIZE / 2;
		int eTop = enemyPlanes[i].planePOS.y - PLANE_SIZE / 2;
		int eRight = enemyPlanes[i].planePOS.x + PLANE_SIZE / 2;
		int eBottom = enemyPlanes[i].planePOS.y + PLANE_SIZE / 2;
	
		if (pLeft < eRight && pRight > eLeft && pTop < eBottom && pBottom > eTop)
		{
			playerHP -= 10;  // 每次碰撞扣10血
			if (playerHP < 0) playerHP = 0;  // 血量最低为0

			enemyPlanes[i].planePOS.x = rand() % (SCREEN_WIDTH - PLANE_SIZE) + PLANE_SIZE / 2;
			enemyPlanes[i].planePOS.y = rand() % 100 - PLANE_SIZE;

			if (playerHP == 0)
			{
				isGameOver = true;
				PlaySound(NULL, NULL, 0);  // 停止背景音乐
				break;
			}
		}
	}
}
void drawGame()
{
	BeginBatchDraw();//开始批量贴图
	putimage(0, 0, &img[0]);
	if (!isGameOver)
	{
		putimage(myPlane.planePOS.x - PLANE_SIZE / 2, myPlane.planePOS.y - PLANE_SIZE / 2, &img[2]);

		//绘制敌机
		for (int i = 0; i < enemyPlaneLen; i++)
		{
			putimage(enemyPlanes[i].planePOS.x - PLANE_SIZE / 2, enemyPlanes[i].planePOS.y - PLANE_SIZE / 2, &img[1]);
		}

		// 绘制心形子弹
		for (int i = 0; i < myPlane.bulletLen; i++)
		{
			setfillcolor(RED);
			int x0 = myPlane.planeBullets[i].x;
			int y0 = myPlane.planeBullets[i].y;
			int size = 1; // 心形大小
			// 心形参数方程
			for (double t = 0; t < 2 * PI; t += 0.01)
			{
				double x = size * (16 * pow(sin(t), 3));
				double y = size * (13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t));
				fillcircle(x0 + x, y0 - y, 1); // 逐点绘制心形
			}
		}
		drawHPBar();
	}
	else
	{
		drawGameOver();
	}
	

	/*int bulleW = PLANE_SIZE / 4;
	int bulleH = PLANE_SIZE / 4;
	for (int i = 0; i < myPlane.bulletLen; i++)
	{
		putimage(
			myPlane.planeBullets[i].x - bulleW/2,
			myPlane.planeBullets[i].y - bulleH/2, 
			&img[3]);
	}*/

	/*RECT rect = { 0,PLANE_SIZE,SCREEN_WIDTH,SCREEN_HEIGHT };*/
	setbkmode(TRANSPARENT);//文字背景透明
	settextcolor(WHITE);//文字设为白色
	TCHAR scoreStr[30];
	swprintf_s(scoreStr, _countof(scoreStr),_T("分数：%d"), score);
	outtextxy(150, 55, scoreStr);

	//显示子弹数量（调试用）
	/*char bulletStr[30] = { 0 };
	sprintf_s(bulletStr, "子弹数：%d", myPlane.bulletLen);
	RECT bulletRect = { 0, 30, SCREEN_WIDTH, SCREEN_HEIGHT };
	drawtext(bulletStr, &bulletRect, DT_TOP | DT_CENTER);*/
	
	//显示当前子弹坐标（调试用）     
	/*if (myPlane.bulletLen > 0) {
		char posStr[50] = { 0 };
		sprintf_s(posStr, "子弹1坐标:(%d,%d)", myPlane.planeBullets[0].x, myPlane.planeBullets[0].y);
		RECT posRect = { 0, 60, SCREEN_WIDTH, SCREEN_HEIGHT };
		drawtext(posStr, &posRect, DT_TOP | DT_CENTER);
	}*/
	EndBatchDraw();//结束批量贴图

}

void updateBullets()//更新子弹位置
{
	for (int i = 0; i < myPlane.bulletLen; i++)
	{
		myPlane.planeBullets[i].y -= myPlane.bulletSpeed;
	}
}

void checkBulletBound()
{
	int newLen = 0;
	for (int i = 0; i < myPlane.bulletLen; i++)
	{
		if (myPlane.planeBullets[i].y + PLANE_SIZE / 4 > 0)
		{
			myPlane.planeBullets[newLen++] = myPlane.planeBullets[i];
		}
	}
	myPlane.bulletLen = newLen;
}

void updateEnemyPlanes()
{
	for (int i = 0; i < enemyPlaneLen; i++)
	{
		//敌机向下移动
		enemyPlanes[i].planePOS.y += ENEMY_SPEED;
		if (enemyPlanes[i].planePOS.y - PLANE_SIZE / 2 > SCREEN_HEIGHT)
		{
			enemyPlanes[i].planePOS.x = rand() % (SCREEN_WIDTH - PLANE_SIZE) + PLANE_SIZE / 2;
			enemyPlanes[i].planePOS.y = rand() % 100 - PLANE_SIZE;
		}
	}
	//子弹敌机碰撞检测
	for (int i = 0; i < enemyPlaneLen; i++)
	{
		for (int j=0;j<myPlane.bulletLen;j++)
			if (abs(enemyPlanes[i].planePOS.x - myPlane.planeBullets[j].x) < PLANE_SIZE / 2 &&
				abs(enemyPlanes[i].planePOS.y - myPlane.planeBullets[j].y) < PLANE_SIZE / 2) {
				score+=10;//击中敌机，加分
				//重置敌机位置
				enemyPlanes[i].planePOS.x = rand() % (SCREEN_WIDTH - PLANE_SIZE) + PLANE_SIZE / 2;
				enemyPlanes[i].planePOS.y = rand() % 100 - PLANE_SIZE;
				
				//移除击中的子弹
					for (int k = j; k < myPlane.bulletLen - 1; k++)
					{
						myPlane.planeBullets[k] = myPlane.planeBullets[k + 1];
					}
				myPlane.bulletLen--;
				break;
			}
	}
	checkPlayerEnemyHit();
}
void updateGame()
{	
	if (isGameOver) return;
	//我机边界检测
	if (GetAsyncKeyState('W') & 0x8000 &&  myPlane.planePOS.y-PLANE_SIZE/2>0)
	{
		myPlane.planePOS.y -= 4;
	}
	if (GetAsyncKeyState('S') & 0x8000 && myPlane.planePOS.y + PLANE_SIZE / 2 < SCREEN_HEIGHT)
	{
		myPlane.planePOS.y += 4;
	}if (GetAsyncKeyState('A') & 0x8000 && myPlane.planePOS.x - PLANE_SIZE / 2 > 0)
	{
		myPlane.planePOS.x -= 4;
	}if (GetAsyncKeyState('D') & 0x8000 && myPlane.planePOS.x + PLANE_SIZE / 2 < SCREEN_WIDTH)
	{
		myPlane.planePOS.x += 4;
	}
	//子弹发射（非阻塞检测）
	static DWORD lastShootTime = 0;
	if (GetAsyncKeyState(' ') & 0x8000)
	{
		if (GetTickCount() - lastShootTime > 200 && myPlane.bulletLen < BULLET_NUM)
		{
			POS bulletPos;
			bulletPos.x = myPlane.planePOS.x;
			bulletPos.y = myPlane.planePOS.y - PLANE_SIZE / 2; // 飞机顶部发射
			myPlane.planeBullets[myPlane.bulletLen] = bulletPos;
			myPlane.bulletLen++;
			lastShootTime = GetTickCount();
			// 控制台日志（验证）
			printf("发射子弹！总数：%d，坐标：(%d,%d)\n", myPlane.bulletLen, bulletPos.x, bulletPos.y);
		}
	}
	/*if (_kbhit())
	{
		char key = _getch();
		if (key=='j'&&myPlane.bulletLen<BULLET_NUM)
		{
			POS bulletPos;
			bulletPos.x = myPlane.planePOS.x;
			bulletPos.y = myPlane.planePOS.y - PLANE_SIZE / 2;
			myPlane.planeBullets [myPlane.bulletLen]= bulletPos; 
			myPlane.bulletLen++;
		}
	}*/
	//更新子弹
	updateBullets();
	checkBulletBound();
	updateEnemyPlanes();
}


int  main()
{
	loadimage(&img[0], _T("background.jpg"), SCREEN_WIDTH, SCREEN_HEIGHT);
	loadimage(&img[1], _T("cjx.jpg"), PLANE_SIZE, PLANE_SIZE);
	loadimage(&img[2], _T("wy.jpg"), PLANE_SIZE, PLANE_SIZE);
	//loadimage(&img[3], "heart.jpg", PLANE_SIZE / 4);
	/*if (loadimage(&img[3], _T("D:/code/vs/飞机大战/heart.jpg"), PLANE_SIZE / 4, PLANE_SIZE / 4) == NULL) {
		MessageBox(NULL, _T("子弹图加载失败！"), _T("错误"), MB_OK);
		return 1;
	}*/

	initGame(); 
	while (1)
	{
		drawGame();
		updateGame();
		Sleep(1000 / 60);
		
		//按esc退出
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			PlaySound(NULL, NULL, 0);
			break;
		}
	}

	closegraph();
	return 0;
}
