#include <graphics.h>
#include <conio.h>
void wall(int x,int y)//��һ��ǽ������Ϊǽ���ĵ�xy����
{
	x = 20 + 40 * x;
	y = 20 + 40 * y;
	setlinecolor(RGB(225, 0, 0));
	setfillcolor(RGB(225,0,0));
	solidrectangle(x - 20, y - 20, x + 20, y + 20);
}
void box(int x,int y)//��һ�����ӣ�����Ϊ�������ĵ�xy����
{
	x = 20 + 40 * x;
	y = 20 + 40 * y;
	setlinecolor(RGB(0, 225, 0));
	setfillcolor(RGB(0, 225, 0));
	solidrectangle(x - 20, y - 20, x + 20, y + 20);
}
void point(int x, int y)//��һ��Ŀ��㣬����ΪĿ������ĵ�xy����
{
	x = 20 + 40 * x;
	y = 20 + 40 * y;
	setlinecolor(RGB(225, 0, 0));
	setfillcolor(RGB(225, 0, 0));
	solidcircle(x,y,10);
}
void people(int x, int y)//��һ���ˣ�����Ϊ�����ĵ�xy����
{
	x = 20 + 40 * x;
	y = 20 + 40 * y;
	setlinecolor(RGB(0, 0, 225));
	setfillcolor(RGB(0, 0, 225));
	solidrectangle(x - 15, y - 15, x + 15, y + 15);
}
void clean(int x, int y)//���һƬ����
{
	x = 20 + 40 * x;
	y = 20 + 40 * y;
	clearrectangle(x - 20, y - 20, x + 20, y + 20);
}