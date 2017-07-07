#include "��ͼ��.h"
#include<graphics.h>
#include<stdio.h>
#define KEY_DOWN(vk_c) (GetAsyncKeyState(vk_c)&0x8000)
int peoplexy[2] = { 0 };		 //���������������
int n = 1;//������ﳯ��
void draw_map(int a[10][10])//����ͼ������ʹ�����鴢���ͼ��Ϣ��0Ϊ�հף�
{
	int y,x;
	for ( y = 0; y < 10; y++)
	{
		for (x = 0; x < 10; x++)
		{
			if (a[y][x]==1)//1Ϊǽ��
			{
				wall(x,y);
			}
			else if (a[y][x] == 2)//2Ϊ����
			{
				box(x,y);
			}
			else if (a[y][x] == 3)//3Ϊ��
			{
				people(x,y);
				peoplexy[0] = y;
				peoplexy[1] = x;
			}
			else if (a[y][x] == 4)//4ΪĿ���
			{
				point(x,y);
			}
			else if (a[y][x] == 5)//5Ϊ����Ŀ����غ�
			{
				people(x, y);
				peoplexy[0] = y;
				peoplexy[1] = x;
			}
			else if(a[y][x] == 6)//6Ϊ������Ŀ����غ�
			{
				box2(x, y);
			}
			else if(a[y][x] == 0)
			{
				background(x, y);
			}
		}
	}
}
void change_map(int b,int a[10][10])//������ͼ����
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
	int a3[10][10] = {
		0,0,0,0,0,0,0,0,0,1,
		0,0,0,1,1,1,0,0,0,0,
		0,0,0,1,4,1,0,0,0,0,
		0,0,0,1,2,1,1,1,1,0,
		0,1,1,1,3,0,2,4,1,0,
		0,1,4,2,0,0,1,1,1,0,
		0,1,1,1,1,2,1,0,0,0,
		0,0,0,0,1,4,1,0,0,0,
		0,0,0,0,1,1,1,0,0,0,
		0,0,0,0,0,0,0,0,0,0
	};
	int a4[10][10] = {
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,1,1,1,0,0,0,0,
		0,0,0,1,4,1,0,0,0,0,
		0,0,0,1,2,1,1,1,1,0,
		0,1,1,1,3,0,2,4,1,0,
		0,1,4,2,0,0,1,1,1,0,
		0,1,1,1,1,2,1,0,0,0,
		0,0,0,0,1,4,1,0,0,0,
		0,0,0,0,1,1,1,0,0,0,
		1,0,0,0,0,0,0,0,0,0
	};
	int a5[10][10] = {
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,1,1,1,0,0,0,0,
		0,0,0,1,4,1,0,0,0,0,
		0,0,0,1,2,1,1,1,1,0,
		0,1,1,1,3,0,2,4,1,0,
		0,1,4,2,0,0,1,1,1,0,
		0,1,1,1,1,2,1,0,0,0,
		0,0,0,0,1,4,1,0,0,0,
		0,0,0,0,1,1,1,0,0,0,
		0,0,0,0,0,0,0,0,0,1
	};
	int a6[10][10] = {
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,1,1,1,0,0,0,0,
		0,0,0,1,4,1,0,0,0,0,
		0,0,0,1,2,1,1,1,1,0,
		0,1,1,1,3,0,2,4,1,0,
		0,1,4,2,0,0,1,1,1,0,
		0,1,1,1,1,2,1,0,0,0,
		0,0,0,0,1,4,1,0,0,0,
		0,0,0,0,1,1,1,0,0,0,
		0,0,0,0,0,0,0,0,0,0
	};
	int a7[10][10] = {
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,1,1,1,0,0,0,0,
		0,0,0,1,4,1,0,0,0,0,
		0,0,0,1,2,1,1,1,1,0,
		0,1,1,1,3,0,2,4,1,0,
		0,1,4,2,0,0,1,1,1,0,
		0,1,1,1,1,2,1,0,0,0,
		0,0,0,0,1,4,1,0,0,0,
		0,0,0,0,1,1,1,0,0,0,
		0,0,0,0,0,0,0,0,0,0
	};
	int a8[10][10] = {
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,1,1,1,0,0,0,0,
		0,0,0,1,4,1,0,0,0,0,
		0,0,0,1,2,1,1,1,1,0,
		0,1,1,1,3,0,2,4,1,0,
		0,1,4,2,0,0,1,1,1,0,
		0,1,1,1,1,2,1,0,0,0,
		0,0,0,0,1,4,1,0,0,0,
		0,0,0,0,1,1,1,0,0,0,
		0,0,0,0,0,0,0,0,0,0
	};
	int a9[10][10] = {
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,1,1,1,0,0,0,0,
		0,0,0,1,4,1,0,0,0,0,
		0,0,0,1,2,1,1,1,1,0,
		0,1,1,1,3,0,2,4,1,0,
		0,1,4,2,0,0,1,1,1,0,
		0,1,1,1,1,2,1,0,0,0,
		0,0,0,0,1,4,1,0,0,0,
		0,0,0,0,1,1,1,0,0,0,
		0,0,0,0,0,0,0,0,0,0
	};
	int a10[10][10] = {
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,1,1,1,0,0,0,0,
		0,0,0,1,4,1,0,0,0,0,
		0,0,0,1,2,1,1,1,1,0,
		0,1,1,1,3,0,2,4,1,0,
		0,1,4,2,0,0,1,1,1,0,
		0,1,1,1,1,2,1,0,0,0,
		0,0,0,0,1,4,1,0,0,0,
		0,0,0,0,1,1,1,0,0,0,
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
	case 4:
		p = &a4[0][0]; break;
	case 5:
		p = &a5[0][0]; break;
	case 6:
		p = &a6[0][0]; break;
	case 7:
		p = &a7[0][0]; break;
	case 8:
		p = &a8[0][0]; break;
	case 9:
		p = &a9[0][0]; break;
	case 10:
		p = &a10[0][0];break;
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
int key()//׷�ټ���������Ϣ
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
		else if (KEY_DOWN(VK_ESCAPE))//esc���˳���Ϸ
		{
			return 5;
		}
		else if (KEY_DOWN(VK_SPACE))//space������һ��
		{
			return 6;
		}
}
void judge(int a, int map[10][10], int peoplexy[2])
{
	int y = peoplexy[0];
	int x = peoplexy[1];
	switch (a)
	{
	case 1://����
		if (n != 1)
		{
			people(x, y);
			n = 1;
			break;
		}
		if (map[y+1][x] == 0)//Ŀ�귽��Ϊ��
		{
			if (map[y][x] == 5)//����Ŀ����غ�
			{
				people2(x, y);
				people2(x, y + 1);
				people(x, y + 1);
				point(x, y);
				peoplexy[0] = y + 1;
				map[y][x] = 4;
				map[y + 1][x] = 3;
			}
			else
			{
				people2(x, y);
				background(x, y);
				people2(x, y + 1);
				people(x, y + 1);
				peoplexy[0] = y + 1;
				map[y][x] = 0;
				map[y + 1][x] = 3;
			}
		}
		else if (map[y + 1][x] == 4)//Ŀ�귽��ΪĿ���
		{
			if (map[y][x] == 5)//����Ŀ����غ�
			{
				people2(x, y);
				point(x, y);
				people2(x, y + 1);
				people(x, y + 1);
				peoplexy[0] = y + 1;
				map[y][x] = 4;
				map[y + 1][x] = 5;
			}
			else
			{
				people2(x, y);
				background(x, y);
				people2(x, y + 1);
				people(x, y + 1);
				peoplexy[0] = y + 1;
				map[y][x] = 0;
				map[y + 1][x] = 5;
			}
		}
		else if ((map[y+1][x] == 2|| map[y + 1][x] == 6) && map[y+2][x] != 1)//Ŀ�귽��Ϊ���ӣ������Ա߲�Ϊǽ��
		{
			if (map[y][x] == 5&& map[y + 1][x] == 2&& map[y + 2][x] == 0)//����Ŀ����غ�,���Ӳ���Ŀ����غϣ����ӷ���ΪĿ���
			{
				people2(x, y);
				point(x, y);
				people2(x, y + 1);
				people(x, y + 1);
				peoplexy[0] = y + 1;
				box(x, y + 2);
				map[y][x] = 4;
				map[y + 1][x] = 3;
				map[y + 2][x] = 2;
			}
			else if(map[y][x] == 5 && map[y + 1][x] == 2 && map[y + 2][x] == 4)//����Ŀ���غϣ����Ӳ���Ŀ���غϣ����ӷ���ΪĿ���
			{
				people2(x, y);
				point(x, y);
				people2(x, y + 1);
				people(x, y + 1);
				peoplexy[0] = y + 1;
				box2(x, y+2);
				map[y][x] = 4;
				map[y + 1][x] = 3;
				map[y + 2][x] = 6;
			}
			else if (map[y][x] == 5 && map[y + 1][x] == 6 && map[y + 2][x] == 0)//����Ŀ���غϣ�������Ŀ���غϣ����ӷ���ΪĿ���
			{
				people2(x, y);
				point(x, y);
				people2(x, y + 1);
				people(x, y + 1);
				peoplexy[0] = y + 1;
				box(x, y + 2);
				map[y][x] = 4;
				map[y + 1][x] = 5;
				map[y + 2][x] = 2;
			}
			else if (map[y][x] == 5 && map[y + 1][x] == 6 && map[y + 2][x] == 4)//����Ŀ���غϣ�������Ŀ���غϣ����ӷ���ΪĿ���
			{
				people2(x, y);
				point(x, y);
				people2(x, y + 1);
				people(x, y + 1);
				peoplexy[0] = y + 1;
				box2(x, y + 2);
				map[y][x] = 4;
				map[y + 1][x] = 5;
				map[y + 2][x] = 6;
			}
			else if (map[y][x] == 3 && map[y + 1][x] == 2 && map[y + 2][x] == 0)//�˲���Ŀ���غϣ����Ӳ���Ŀ���غϣ����ӷ���ΪĿ���
			{
				people2(x, y);
				background(x, y);
				people2(x, y + 1);
				people(x, y + 1);
				peoplexy[0] = y + 1;
				box(x, y + 2);
				map[y][x] = 0;
				map[y + 1][x] = 3;
				map[y + 2][x] = 2;
			}
			else if (map[y][x] == 3 && map[y + 1][x] == 2 && map[y + 2][x] == 4)//�˲���Ŀ���غϣ����Ӳ���Ŀ���غϣ����ӷ���ΪĿ���
			{
				people2(x, y);
				background(x, y);
				people2(x, y + 1);
				people(x, y + 1);
				peoplexy[0] = y + 1;
				box2(x, y + 2);
				map[y][x] = 0;
				map[y + 1][x] = 3;
				map[y + 2][x] = 6;
			}
			else if (map[y][x] == 3 && map[y + 1][x] == 6 && map[y + 2][x] == 0)//�˲���Ŀ���غϣ�������Ŀ���غϣ����ӷ���ΪĿ���
			{
				people2(x, y);
				background(x, y);
				people2(x, y + 1);
				people(x, y + 1);
				peoplexy[0] = y + 1;
				box(x, y + 2);
				map[y][x] = 0;
				map[y + 1][x] = 5;
				map[y + 2][x] = 2;
			}
			else if (map[y][x] == 3 && map[y + 1][x] == 6 && map[y + 2][x] == 4)//�˲���Ŀ���غϣ�������Ŀ���غϣ����ӷ���ΪĿ���
			{
				people2(x, y);
				background(x, y);
				people2(x, y + 1);
				people(x, y + 1);
				peoplexy[0] = y + 1;
				box2(x, y + 2);
				map[y][x] = 0;
				map[y + 1][x] = 5;
				map[y + 2][x] = 6;
			}
		}
		break;
	case 2://����
		if (n != 2)
		{
			people11(x, y);
			n = 2;
			break;
		}
		if (map[y - 1][x] == 0)//Ŀ�귽��Ϊ��
		{
			if (map[y][x] == 5)//����Ŀ����غ�
			{
				people1(x, y);
				people1(x, y - 1);
				people11(x, y - 1);
				point(x, y);
				peoplexy[0] = y - 1;
				map[y][x] = 4;
				map[y - 1][x] = 3;
			}
			else
			{
				people1(x, y);
				background(x, y);
				people1(x, y - 1);
				people11(x, y - 1);
				peoplexy[0] = y - 1;
				map[y][x] = 0;
				map[y - 1][x] = 3;
			}
		}
		else if (map[y - 1][x] == 4)//Ŀ�귽��ΪĿ���
		{
			if (map[y][x] == 5)//����Ŀ����غ�
			{
				people1(x, y);
				point(x, y);
				people1(x, y - 1);
				people11(x, y - 1);
				peoplexy[0] = y - 1;
				map[y][x] = 4;
				map[y - 1][x] = 5;
			}
			else
			{
				people1(x, y);
				background(x, y);
				people1(x, y - 1);
				people11(x, y - 1);
				peoplexy[0] = y - 1;
				map[y][x] = 0;
				map[y - 1][x] = 5;
			}
		}
		else if ((map[y - 1][x] == 2 || map[y - 1][x] == 6) && map[y - 2][x] != 1)//Ŀ�귽��Ϊ���ӣ������Ա߲�Ϊǽ��
		{
			if (map[y][x] == 5 && map[y - 1][x] == 2 && map[y - 2][x] == 0)//����Ŀ����غ�,���Ӳ���Ŀ����غϣ����ӷ���ΪĿ���
			{
				people1(x, y);
				point(x, y);
				people1(x, y - 1);
				people11(x, y - 1);
				peoplexy[0] = y - 1;
				box(x, y - 2);
				map[y][x] = 4;
				map[y - 1][x] = 3;
				map[y - 2][x] = 2;
			}
			else if (map[y][x] == 5 && map[y - 1][x] == 2 && map[y - 2][x] == 4)//����Ŀ���غϣ����Ӳ���Ŀ���غϣ����ӷ���ΪĿ���
			{
				people1(x, y);
				point(x, y);
				people1(x, y - 1);
				people11(x, y - 1);
				peoplexy[0] = y - 1;
				box2(x, y - 2);
				map[y][x] = 4;
				map[y - 1][x] = 3;
				map[y - 2][x] = 6;
			}
			else if (map[y][x] == 5 && map[y - 1][x] == 6 && map[y - 2][x] == 0)//����Ŀ���غϣ�������Ŀ���غϣ����ӷ���ΪĿ���
			{
				people1(x, y);
				point(x, y);
				people1(x, y - 1);
				people11(x, y - 1);
				peoplexy[0] = y - 1;
				box(x, y - 2);
				map[y][x] = 4;
				map[y - 1][x] = 5;
				map[y - 2][x] = 2;
			}
			else if (map[y][x] == 5 && map[y - 1][x] == 6 && map[y - 2][x] == 4)//����Ŀ���غϣ�������Ŀ���غϣ����ӷ���ΪĿ���
			{
				people1(x, y);
				point(x, y);
				people1(x, y - 1);
				people11(x, y - 1);
				peoplexy[0] = y - 1;
				box2(x, y - 2);
				map[y][x] = 4;
				map[y - 1][x] = 5;
				map[y - 2][x] = 6;
			}
			else if (map[y][x] == 3 && map[y - 1][x] == 2 && map[y - 2][x] == 0)//�˲���Ŀ���غϣ����Ӳ���Ŀ���غϣ����ӷ���ΪĿ���
			{
				people1(x, y);
				background(x, y);
				people1(x, y - 1);
				people11(x, y - 1);
				peoplexy[0] = y - 1;
				box(x, y - 2);
				map[y][x] = 0;
				map[y - 1][x] = 3;
				map[y - 2][x] = 2;
			}
			else if (map[y][x] == 3 && map[y - 1][x] == 2 && map[y - 2][x] == 4)//�˲���Ŀ���غϣ����Ӳ���Ŀ���غϣ����ӷ���ΪĿ���
			{
				people1(x, y);
				background(x, y);
				people1(x, y - 1);
				people11(x, y - 1);
				peoplexy[0] = y - 1;
				box2(x, y - 2);
				map[y][x] = 0;
				map[y - 1][x] = 3;
				map[y - 2][x] = 6;
			}
			else if (map[y][x] == 3 && map[y - 1][x] == 6 && map[y - 2][x] == 0)//�˲���Ŀ���غϣ�������Ŀ���غϣ����ӷ���ΪĿ���
			{
				people1(x, y);
				background(x, y);
				people1(x, y - 1);
				people11(x, y - 1);
				peoplexy[0] = y - 1;
				box(x, y - 2);
				map[y][x] = 0;
				map[y - 1][x] = 5;
				map[y - 2][x] = 2;
			}
			else if (map[y][x] == 3 && map[y - 1][x] == 6 && map[y - 2][x] == 4)//�˲���Ŀ���غϣ�������Ŀ���غϣ����ӷ���ΪĿ���
			{
				people1(x, y);
				background(x, y);
				people1(x, y - 1);
				people11(x, y - 1);
				peoplexy[0] = y - 1;
				box2(x, y - 2);
				map[y][x] = 0;
				map[y - 1][x] = 5;
				map[y - 2][x] = 6;
			}
		}
		break;
	case 3://����
		if (n != 3)
		{
			people33(x, y);
			n = 3;
			break;
		}
		if (map[y][x - 1] == 0)//Ŀ�귽��Ϊ��
		{
			if (map[y][x] == 5)//����Ŀ����غ�
			{
				people3(x, y);
				point(x, y);
				people3(x - 1, y);
				people33(x - 1, y);
				peoplexy[1] = x - 1;
				map[y][x] = 4;
				map[y][x - 1] = 3;
			}
			else
			{
				people3(x, y);
				background(x, y);
				people3(x - 1, y);
				people33(x - 1, y);
				peoplexy[1] = x - 1;
				map[y][x] = 0;
				map[y][x - 1] = 3;
			}
		}
		else if (map[y][x - 1] == 4)//Ŀ�귽��ΪĿ���
		{
			if (map[y][x] == 5)//����Ŀ����غ�
			{
				people3(x, y);
				point(x, y);
				people3(x - 1, y);
				people33(x - 1, y);
				peoplexy[1] = x - 1;
				map[y][x] = 4;
				map[y][x - 1] = 5;
			}
			else
			{
				people3(x, y);
				background(x, y);
				people3(x - 1, y);
				people33(x - 1, y);
				peoplexy[1] = x - 1;
				map[y][x] = 0;
				map[y][x - 1] = 5;
			}
		}
		else if ((map[y][x - 1] == 2 || map[y][x - 1] == 6) && map[y][x - 2] != 1)//Ŀ�귽��Ϊ���ӣ������Ա߲�Ϊǽ��
		{
			if (map[y][x] == 5 && map[y][x - 1] == 2 && map[y][x - 2] == 0)//����Ŀ����غ�,���Ӳ���Ŀ����غϣ����ӷ���ΪĿ���
			{
				people3(x, y);
				point(x, y);
				people3(x - 1, y);
				people33(x - 1, y);
				peoplexy[1] = x - 1;
				box(x - 2, y);
				map[y][x] = 4;
				map[y][x - 1] = 3;
				map[y][x - 2] = 2;
			}
			else if (map[y][x] == 5 && map[y][x - 1] == 2 && map[y][x - 2] == 4)//����Ŀ���غϣ����Ӳ���Ŀ���غϣ����ӷ���ΪĿ���
			{
				people3(x, y);
				point(x, y);
				people3(x - 1, y);
				people33(x - 1, y);
				peoplexy[1] = x - 1;
				box2(x - 2, y);
				map[y][x] = 4;
				map[y][x - 1] = 3;
				map[y][x - 2] = 6;
			}
			else if (map[y][x] == 5 && map[y][x - 1] == 6 && map[y][x - 2] == 0)//����Ŀ���غϣ�������Ŀ���غϣ����ӷ���ΪĿ���
			{
				people3(x, y);
				point(x, y);
				people3(x - 1, y);
				people33(x - 1, y);
				peoplexy[1] = x - 1;
				box(x - 2, y);
				map[y][x] = 4;
				map[y][x - 1] = 5;
				map[y][x - 2] = 2;
			}
			else if (map[y][x] == 5 && map[y][x - 1] == 6 && map[y][x - 2] == 4)//����Ŀ���غϣ�������Ŀ���غϣ����ӷ���ΪĿ���
			{
				people3(x, y);
				point(x, y);
				people3(x - 1, y);
				people33(x - 1, y);
				peoplexy[1] = x - 1;
				box2(x - 2, y);
				map[y][x] = 4;
				map[y][x - 1] = 5;
				map[y][x - 2] = 6;
			}
			else if (map[y][x] == 3 && map[y][x - 1] == 2 && map[y][x - 2] == 0)//�˲���Ŀ���غϣ����Ӳ���Ŀ���غϣ����ӷ���ΪĿ���
			{
				people3(x, y);
				background(x, y);
				people3(x - 1, y);
				people33(x - 1, y);
				peoplexy[1] = x - 1;
				box(x - 2, y);
				map[y][x] = 0;
				map[y][x - 1] = 3;
				map[y][x - 2] = 2;
			}
			else if (map[y][x] == 3 && map[y][x - 1] == 2 && map[y][x - 2] == 4)//�˲���Ŀ���غϣ����Ӳ���Ŀ���غϣ����ӷ���ΪĿ���
			{
				people3(x, y);
				background(x, y);
				people3(x - 1, y);
				people33(x - 1, y);
				peoplexy[1] = x - 1;
				box2(x - 2, y);
				map[y][x] = 0;
				map[y][x - 1] = 3;
				map[y][x - 2] = 6;
			}
			else if (map[y][x] == 3 && map[y][x - 1] == 6 && map[y][x - 2] == 0)//�˲���Ŀ���غϣ�������Ŀ���غϣ����ӷ���ΪĿ���
			{
				people3(x, y);
				background(x, y);
				people3(x - 1, y);
				people33(x - 1, y);
				peoplexy[1] = x - 1;
				box(x - 2, y);
				map[y][x] = 0;
				map[y][x - 1] = 5;
				map[y][x - 2] = 2;
			}
			else if (map[y][x] == 3 && map[y][x - 1] == 6 && map[y][x - 2] == 4)//�˲���Ŀ���غϣ�������Ŀ���غϣ����ӷ���ΪĿ���
			{
				people3(x, y);
				background(x, y);
				people3(x - 1, y);
				people33(x - 1, y);
				peoplexy[1] = x - 1;
				box2(x - 2, y);
				map[y][x] = 0;
				map[y][x - 1] = 5;
				map[y][x - 2] = 6;
			}
		}
		break;
	case 4://����
		if (n != 4)
		{
			people44(x, y);
			n = 4;
			break;
		}
		if (map[y][x + 1] == 0)//Ŀ�귽��Ϊ��
		{
			if (map[y][x] == 5)//����Ŀ����غ�
			{
				people4(x, y);
				point(x, y);
				people4(x + 1, y);
				people44(x + 1, y);
				peoplexy[1] = x + 1;
				map[y][x] = 4;
				map[y][x + 1] = 3;
			}
			else
			{
				people4(x, y);
				background(x, y);
				people4(x + 1, y);
				people44(x + 1, y);
				peoplexy[1] = x + 1;
				map[y][x] = 0;
				map[y][x + 1] = 3;
			}
		}
		else if (map[y][x + 1] == 4)//Ŀ�귽��ΪĿ���
		{
			if (map[y][x] == 5)//����Ŀ����غ�
			{
				people4(x, y);
				point(x, y);
				people4(x + 1, y);
				people44(x + 1, y);
				peoplexy[1] = x + 1;
				map[y][x] = 4;
				map[y][x + 1] = 5;
			}
			else
			{
				people4(x, y);
				background(x, y);
				people4(x + 1, y);
				people44(x + 1, y);
				peoplexy[1] = x + 1;
				map[y][x] = 0;
				map[y][x + 1] = 5;
			}
		}
		else if ((map[y][x + 1] == 2 || map[y][x + 1] == 6) && map[y][x + 2] != 1)//Ŀ�귽��Ϊ���ӣ������Ա߲�Ϊǽ��
		{
			if (map[y][x] == 5 && map[y][x + 1] == 2 && map[y][x + 2] == 0)//����Ŀ����غ�,���Ӳ���Ŀ����غϣ����ӷ���ΪĿ���
			{
				people4(x, y);
				point(x, y);
				people4(x + 1, y);
				people44(x + 1, y);
				peoplexy[1] = x + 1;
				box(x + 2, y);
				map[y][x] = 4;
				map[y][x + 1] = 3;
				map[y][x + 2] = 2;
			}
			else if (map[y][x] == 5 && map[y][x + 1] == 2 && map[y][x + 2] == 4)//����Ŀ���غϣ����Ӳ���Ŀ���غϣ����ӷ���ΪĿ���
			{
				people4(x, y);
				point(x, y);
				people4(x + 1, y);
				people44(x + 1, y);
				peoplexy[1] = x + 1;
				box2(x + 2, y);
				map[y][x] = 4;
				map[y][x + 1] = 3;
				map[y][x + 2] = 6;
			}
			else if (map[y][x] == 5 && map[y][x + 1] == 6 && map[y][x + 2] == 0)//����Ŀ���غϣ�������Ŀ���غϣ����ӷ���ΪĿ���
			{
				people4(x, y);
				point(x, y);
				people4(x + 1, y);
				people44(x + 1, y);
				peoplexy[1] = x + 1;
				box(x + 2, y);
				map[y][x] = 4;
				map[y][x + 1] = 5;
				map[y][x + 2] = 2;
			}
			else if (map[y][x] == 5 && map[y][x + 1] == 6 && map[y][x + 2] == 4)//����Ŀ���غϣ�������Ŀ���غϣ����ӷ���ΪĿ���
			{
				people4(x, y);
				point(x, y);
				people4(x + 1, y);
				people44(x + 1, y);
				peoplexy[1] = x + 1;
				box2(x + 2, y);
				map[y][x] = 4;
				map[y][x + 1] = 5;
				map[y][x + 2] = 6;
			}
			else if (map[y][x] == 3 && map[y][x + 1] == 2 && map[y][x + 2] == 0)//�˲���Ŀ���غϣ����Ӳ���Ŀ���غϣ����ӷ���ΪĿ���
			{
				people4(x, y);
				background(x, y);
				people4(x + 1, y);
				people44(x + 1, y);
				peoplexy[1] = x + 1;
				box(x + 2, y);
				map[y][x] = 0;
				map[y][x + 1] = 3;
				map[y][x + 2] = 2;
			}
			else if (map[y][x] == 3 && map[y][x + 1] == 2 && map[y][x + 2] == 4)//�˲���Ŀ���غϣ����Ӳ���Ŀ���غϣ����ӷ���ΪĿ���
			{
				people4(x, y);
				background(x, y);
				people4(x + 1, y);
				people44(x + 1, y);
				peoplexy[1] = x + 1;
				box2(x + 2, y);
				map[y][x] = 0;
				map[y][x + 1] = 3;
				map[y][x + 2] = 6;
			}
			else if (map[y][x] == 3 && map[y][x + 1] == 6 && map[y][x + 2] == 0)//�˲���Ŀ���غϣ�������Ŀ���غϣ����ӷ���ΪĿ���
			{
				people4(x, y);
				background(x, y);
				people4(x + 1, y);
				people44(x + 1, y);
				peoplexy[1] = x + 1;
				box(x + 2, y);
				map[y][x] = 0;
				map[y][x + 1] = 5;
				map[y][x + 2] = 2;
			}
			else if (map[y][x] == 3 && map[y][x + 1] == 6 && map[y][x + 2] == 4)//�˲���Ŀ���غϣ�������Ŀ���غϣ����ӷ���ΪĿ���
			{
				people4(x, y);
				background(x, y);
				people4(x + 1, y);
				people44(x + 1, y);
				peoplexy[1] = x + 1;
				box2(x + 2, y);
				map[y][x] = 0;
				map[y][x + 1] = 5;
				map[y][x + 2] = 6;
			}
		}
		break;
	case 5:
		break;
	case 6:
		break;
	}
}
int judge1(int map[10][10])
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

int main()
{
	initgraph(640, 500);
	int num = 1;                     //�ؿ�����
	int map[10][10] = { 0 };         //��ŵ�ͼ����
	getpeople_img();
	getbackgroundimg();
	getboximg();
	getbox2img();
	getwallimg();
	getpointimg();
	while (1)
	{
		int k = 1;
		change_map(num,map);		//������ͼ
		cleardevice();				//�����Ļ����ǰ�����������(0,0)��
		draw_map(map);				//���»�����ͼ
		while (k)					//��Ϸ����
		{
			int s = key();			//���ռ��̲���
			judge(s, map, peoplexy);	//�жϼ��̲�����ִ��ִ��
			Sleep(100);					
			k = judge1(map);						//�ж���Ϸ�Ƿ����
			
		}
		num++;						//�ؿ���ɺ�ؿ���+1
		
	}
	closegraph();

}