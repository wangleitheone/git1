#include "画图形.h"
#include<graphics.h>
#include<stdio.h>
#include<string>
#define KEY_DOWN(vk_c) (GetAsyncKeyState(vk_c)&0x8000)
int peoplexy[2] = { 0 };		 //存放人物所在坐标
int n = 1;//标记人物朝向
void draw_map(int a[10][10])//将地图画出，使用数组储存地图信息，0为空白，
{
	int y,x;
	for ( y = 0; y < 10; y++)
	{
		for (x = 0; x < 10; x++)
		{
			switch (a[y][x])
			{
			case 0:
				background(x, y);
				break;
			case 1://1为墙壁
				wall(x, y);
				break;
			case 2://2为箱子
				box(x, y);
				break;
			case 3://3为人
				people(x, y);
				peoplexy[0] = y;
				peoplexy[1] = x;
				break;
			case 4://4为目标点
				point(x, y);
				break;
			case 7://7为人与目标点重合
				people(x, y);
				peoplexy[0] = y;
				peoplexy[1] = x;
				break;
			case 6://6为箱子与目标点重合
				box2(x, y);
				break;
			}
		}
	}
}
void change_map(int b,int a[10][10])//更换地图数据
{
	int a1[10][10] = {
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,1,1,1,0,0,0,0,
		0,0,0,1,4,1,0,0,0,0,
		0,0,0,1,0,1,1,1,1,0,
		0,1,1,1,2,0,2,4,1,0,
		0,1,4,0,2,3,1,1,1,0,
		0,1,1,1,1,2,1,0,0,0,
		0,0,0,0,1,4,1,0,0,0,
		0,0,0,0,1,1,1,0,0,0,
		0,0,0,0,0,0,0,0,0,0
	};
	int a2[10][10] = {
		1,1,1,1,1,0,0,0,0,0,
		1,0,0,0,1,0,0,0,0,0,
		1,0,2,3,1,0,1,1,1,0,
		1,0,2,2,1,0,1,4,1,0,
		1,1,1,0,1,1,1,4,1,0,
		0,1,1,0,0,0,0,4,1,0,
		0,1,0,0,0,1,0,0,1,0,
		0,1,0,0,0,1,1,1,1,0,
		0,1,1,1,1,1,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0
	};
	int a3[10][10] = {					////由于手动输入数据太费时间，所以只输入了三关地图数据演示一下
		0,0,0,0,0,0,0,0,0,0,
		0,1,1,1,1,1,0,0,0,0,
		0,1,1,0,0,1,0,0,0,0,
		0,1,0,3,2,1,0,0,0,0,
		0,1,1,2,0,1,1,0,0,0,
		0,1,1,0,2,0,1,0,0,0,
		0,1,4,2,0,0,1,0,0,0,
		0,1,4,4,6,4,1,0,0,0,
		0,1,1,1,1,1,1,0,0,0,
		0,0,0,0,0,0,0,0,0,0
	};
	int *p=&a[0][0];
	switch (b)
	{
	case 1:
		p = &a1[0][0]; break;
	case 2:
		p = &a2[0][0]; break;
	case 3:
		p = &a3[0][0]; break;
	}
	int y , x ;
	for (y=0; y<10; y++)
	{
		for (x = 0; x<10; x++)
		{
			a[y][x] = *p;
			p++;
		}

	}
	
}
int key()//追踪键盘输入信息
{
		if (KEY_DOWN(VK_DOWN))
		{
			return 1;
		}
		else if (KEY_DOWN(VK_UP))
		{
			return 2;
		}
		else if (KEY_DOWN(VK_LEFT))
		{
			return 3;
		}
		else if (KEY_DOWN(VK_RIGHT))
		{
			return 4;
		}
		else if (KEY_DOWN(VK_ESCAPE))//esc键退出游戏
		{
			return 5;
		}
		else if (KEY_DOWN(VK_SPACE))//space键回退一步
		{
			return 6;
		}
		else if (KEY_DOWN(0x59)|| KEY_DOWN(0x79))
		{
			return 7;
		}
		else if (KEY_DOWN(0x4e) || KEY_DOWN(0x6e))
		{
			return 8;
		}
}
void judge(int a, int map[10][10], int peoplexy[2])
{
	int y = peoplexy[0];
	int x = peoplexy[1];
	switch (a)
	{
	case 1://向下
		if (n != 1)
		{
			people(x, y);
			n = 1;
			break;
		}
		if (map[y+1][x] == 0 || map[y + 1][x] == 4)//目标方向为空或为目标点
		{
			people2(x, y);
			if (map[y][x] == 7)//人与目标点重合
			{
				point(x, y);
			}
			else
			{
				background(x, y);
			}
			people2(x, y + 1);
			people(x, y + 1);
			peoplexy[0] = y + 1;
			map[y][x] -= 3;
			map[y + 1][x] += 3;
		}
		else if ((map[y + 1][x] == 2 || map[y + 1][x] == 6) && (map[y + 2][x] == 0 || map[y + 2][x] == 4))  //目标方向为箱子，箱子旁边为空地或目标点
		{
			people2(x, y);
			if (map[y][x] == 7)
			{
				point(x, y);
			}
			else if (map[y][x] == 3)
			{
				background(x, y);
			}
			people2(x, y + 1);
			people(x, y + 1);
			peoplexy[0] = y + 1;
			if (map[y + 2][x] == 0)
			{
				box(x, y + 2);
			}
			else if (map[y + 2][x] == 4)
			{
				box2(x, y + 2);
			}
			map[y][x] -= 3;
			map[y + 1][x] += 1;
			map[y + 2][x] += 2;
		}
		break;
	case 2://向上
		if (n != 2)
		{
			people11(x, y);
			n = 2;
			break;
		}
		if (map[y - 1][x] == 0 || map[y - 1][x] == 4)//目标方向为空或为目标点
		{
			people1(x, y);
			if (map[y][x] == 7)//人与目标点重合
			{
				point(x, y);
			}
			else
			{
				background(x, y);
			}
			people1(x, y - 1);
			people11(x, y - 1);
			peoplexy[0] = y - 1;
			map[y][x] -= 3;
			map[y - 1][x] += 3;
		}
		else if ((map[y - 1][x] == 2 || map[y - 1][x] == 6) && (map[y - 2][x] == 0 || map[y - 2][x] == 4))  //目标方向为箱子，箱子旁边为空地或目标点
		{
			people1(x, y);
			if (map[y][x] == 7)
			{
				point(x, y);
			}
			else if (map[y][x] == 3)
			{
				background(x, y);
			}
			people1(x, y - 1);
			people11(x, y - 1);
			peoplexy[0] = y - 1;
			if (map[y - 2][x] == 0)
			{
				box(x, y - 2);
			}
			else if (map[y - 2][x] == 4)
			{
				box2(x, y - 2);
			}
			map[y][x] -= 3;
			map[y - 1][x] += 1;
			map[y - 2][x] += 2;
		}
		break;
	case 3://向左
		if (n != 3)
		{
			people33(x, y);
			n = 3;
			break;
		}
		if (map[y][x - 1] == 0 || map[y][x - 1] == 4)//目标方向为空或为目标点
		{
			people3(x, y);
			if (map[y][x] == 7)//人与目标点重合
			{
				point(x, y);
			}
			else
			{
				background(x, y);
			}
			people3(x - 1, y);
			people33(x - 1, y);
			peoplexy[1] = x - 1;
			map[y][x] -= 3;
			map[y][x - 1] += 3;
		}
		else if ((map[y][x - 1] == 2 || map[y][x - 1] == 6) && (map[y][x - 2] == 0 || map[y][x - 2] == 4))  //目标方向为箱子，箱子旁边为空地或目标点
		{
			people3(x, y);
			if (map[y][x] == 7)
			{
				point(x, y);
			}
			else if (map[y][x] == 3)
			{
				background(x, y);
			}
			people3(x - 1, y);
			people33(x - 1, y);
			peoplexy[1] = x - 1;
			if (map[y][x - 2] == 0)
			{
				box(x - 2, y);
			}
			else if (map[y][x - 2] == 4)
			{
				box2(x - 2, y);
			}
			map[y][x] -= 3;
			map[y][x - 1] += 1;
			map[y][x - 2] += 2;
		}
		break;
	case 4://向右
		if (n != 4)
		{
			people44(x, y);
			n = 4;
			break;
		}
		if (map[y][x + 1] == 0 || map[y][x + 1] == 4)//目标方向为空或为目标点
		{
			people4(x, y);
			if (map[y][x] == 7)//人与目标点重合
			{
				point(x, y);
			}
			else
			{
				background(x, y);
			}
			people4(x + 1, y);
			people44(x + 1, y);
			peoplexy[1] = x + 1;
			map[y][x] -= 3;
			map[y][x + 1] += 3;
		}
		else if ((map[y][x + 1] == 2 || map[y][x + 1] == 6) && (map[y][x + 2] == 0 || map[y][x + 2] == 4))  //目标方向为箱子，箱子旁边为空地或目标点
		{
			people4(x, y);
			if (map[y][x] == 7)
			{
				point(x, y);
			}
			else if (map[y][x] == 3)
			{
				background(x, y);
			}
			people4(x + 1, y);
			people44(x + 1, y);
			peoplexy[1] = x + 1;
			if (map[y][x + 2] == 0)
			{
				box(x + 2, y);
			}
			else if (map[y][x + 2] == 4)
			{
				box2(x + 2, y);
			}
			map[y][x] -= 3;
			map[y][x + 1] += 1;
			map[y][x + 2] += 2;
		}
		break;
	}
}
int judge1(int map[10][10])//通过地图上是否有箱子判断游戏是否完成
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (map[y][x] == 2)
			{
				return 1;
			}
		}
	}
	return 0;
}
void caption()//游戏说明
{
	char *data[6] = {
		"游戏介绍：" ,
		"Eas键退出；上下左右键控",
		"制人物移动；空格键可重新",
		"开始当前关卡,将箱子推到小",
		"红球标记的位置后，按Y继",
		"续下一关，N退出游戏。"
	};
	settextstyle(14, 0, "宋体");
	settextcolor(RGB(0, 255, 255));
	for ( int i = 0; i <= 5; i++)
	{
		outtextxy(515, 100+20*i, data[i]);
	}
}

int main()
{
	initgraph(700, 500);
	int num = 1;                     //关卡计数
	int map[10][10] = { 0 };         //存放地图数据
	getpeople_img();
	getbackgroundimg();
	getboximg();
	getbox2img();
	getwallimg();
	getpointimg();
	while (1)
	{
		ABC:int k = 1;
		change_map(num,map);		//更换地图
		cleardevice();				//清空屏幕，当前坐标点重置至(0,0)；
		caption();
		draw_map(map);				//重新画出地图
		while (k)					//游戏进行
		{
			int s = key();			//接收键盘操作
			judge(s, map, peoplexy);	//判断键盘操作并执行执行
			Sleep(100);					
			k = judge1(map);						//判断游戏是否完成
			if (s == 5)
			{
				goto abc;
			}
			else if (s == 6)
			{
				goto ABC;
			}
		}
		while (1)//是否进入下一关
		{
			settextcolor(YELLOW);
			setbkmode(TRANSPARENT);
			settextstyle(26, 15, "宋体");
			char *s[4] = { "恭喜过关！","是否进入下一关？"
				,"Y","N"
			};
			outtextxy(180, 160, s[0]);
			outtextxy(130, 200, s[1]);
			outtextxy(150, 240, s[2]);
			outtextxy(310, 240, s[3]);
			int n = key();
			if (n == 7)
			{
				break;
			}
			else if (n == 8)
			{
				goto abc;
			}
		}
		num++;						//关卡完成后关卡数+1		
	}
	abc:closegraph();

}