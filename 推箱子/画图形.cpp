#include <graphics.h>
#include <conio.h>
IMAGE image_rc;
IMAGE people_img[5];
IMAGE backgroundimg;
IMAGE boximg;
IMAGE box2img;
IMAGE wallimg;
IMAGE pointimg;
void getpeople_img()
{
	loadimage(&image_rc, "image\\image.bmp");
	SetWorkingImage(&image_rc);
	getimage(&people_img[0], 50, 0, 50, 50);
	getimage(&people_img[1], 0, 200, 50, 50);
	getimage(&people_img[2], 100, 200, 50, 50);
	getimage(&people_img[3], 50, 200, 50, 50);
	getimage(&people_img[4], 150, 200, 50, 50);
	SetWorkingImage(NULL);
}
void getbackgroundimg()
{
	loadimage(&image_rc, "image\\image.bmp");
	SetWorkingImage(&image_rc);
	getimage(&backgroundimg, 0, 0, 50, 50);
	SetWorkingImage(NULL);
}
void getboximg()
{
	loadimage(&image_rc, "image\\image.bmp");
	SetWorkingImage(&image_rc);
	getimage(&boximg, 100, 0, 50, 50);
	SetWorkingImage(NULL);
}
void getbox2img()
{
	loadimage(&image_rc, "image\\image.bmp");
	SetWorkingImage(&image_rc);
	getimage(&box2img, 150, 0, 50, 50);
	SetWorkingImage(NULL);
}
void getwallimg()
{
	loadimage(&image_rc, "image\\image.bmp");
	SetWorkingImage(&image_rc);
	getimage(&wallimg, 0, 100, 50, 50);
	SetWorkingImage(NULL);
}
void getpointimg()
{
	loadimage(&image_rc, "image\\image.bmp");
	SetWorkingImage(&image_rc);
	getimage(&pointimg, 0, 50, 50, 50);
	SetWorkingImage(NULL);
}
void wall(int x,int y)//��һ��ǽ������Ϊǽ���Ͻ�xy����
{
	x = 50 * x;
	y = 50 * y;
	putimage(x, y, &wallimg, SRCINVERT);
}
void box(int x,int y)//��һ�����ӣ�����Ϊ�������ĵ�xy����
{
	x = 50 * x;
	y = 50 * y;
	putimage(x, y, &boximg, SRCINVERT);
}
void box2(int x, int y)//��һ������Ŀ�������ӣ�����Ϊ�������ĵ�xy����
{
	x = 50 * x;
	y = 50 * y;
	putimage(x, y, &box2img, SRCINVERT);
}
void background(int x, int y)
{
	x = 50 * x;
	y = 50 * y;
	putimage(x, y, &backgroundimg, SRCINVERT);
}
void point(int x, int y)//��һ��Ŀ��㣬����ΪĿ������ĵ�xy����
{
	x = 50 * x;
	y = 50 * y;
	putimage(x, y, &pointimg, SRCINVERT);
}
void people(int x, int y)//��һ��������ˣ�����Ϊ�����Ͻ�xy����
{
	x = 50 * x;
	y = 50 * y;
	putimage(x, y,&people_img[0],SRCINVERT);
}
void people1(int x, int y)//��һ�������ߵ��ˣ�����Ϊ�����Ͻ�xy����
{
	x = 50 * x;
	y = 50 * y;
	putimage(x, y, &people_img[1], SRCINVERT);
}
void people2(int x, int y)//��һ�������ߵ��ˣ�����Ϊ�����Ͻ�xy����
{
	x = 50 * x;
	y = 50 * y;
	putimage(x, y, &people_img[2], SRCINVERT);
}
void people3(int x, int y)//��һ����ת���ˣ�����Ϊ�����Ͻ�xy����
{
	x = 50 * x;
	y = 50 * y;
	putimage(x, y, &people_img[3], SRCINVERT);
}
void people4(int x, int y)//��һ����ת���ˣ�����Ϊ�����Ͻ�xy����
{
	x = 50 * x;
	y = 50 * y;
	putimage(x, y, &people_img[4], SRCINVERT);
}
void clean(int x, int y)//���һƬ����
{
	x = 25 + 50 * x;
	y = 25 + 50 * y;
	clearrectangle(x - 25, y - 25, x + 25, y + 25);
}