#include <graphics.h>
#include <conio.h>
void wall(int x,int y)//��һ��ǽ������Ϊǽ���ĵ�xy����
{
	setlinecolor(RGB(225, 0, 0));
	setfillcolor(RGB(225,0,0));
	fillrectangle(x - 20, y - 20, x + 20, y + 20);
}
void box(int x,int y)//��һ�����ӣ�����Ϊ�������ĵ�xy����
{
	setlinecolor(RGB(0, 225, 0));
	setfillcolor(RGB(0, 225, 0));
	fillrectangle(x - 20, y - 20, x + 20, y + 20);
}
void ball(int x, int y)//��һ��Ŀ��㣬����ΪĿ������ĵ�xy����
{
	setlinecolor(RGB(225, 0, 0));
	setfillcolor(RGB(225, 0, 0));
	fillcircle(x,y,10);
}
void people(int x, int y)//��һ���ˣ�����Ϊ�����ĵ�xy����
{
	setlinecolor(RGB(0, 0, 225));
	setfillcolor(RGB(0, 0, 225));
	fillrectangle(x - 15, y - 15, x + 15, y + 15);
}
