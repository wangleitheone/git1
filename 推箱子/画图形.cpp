#include <graphics.h>
#include <conio.h>
IMAGE image_rc1;
IMAGE image_rc2;
IMAGE people_img[8];
IMAGE backgroundimg;
IMAGE boximg;
IMAGE box2img;
IMAGE wallimg;
IMAGE pointimg;
void getpeople_img()
{
	loadimage(&image_rc1, "image\\image.bmp");
	SetWorkingImage(&image_rc1);
	getimage(&people_img[0], 50, 0, 50, 50);//����վ��
	getimage(&people_img[1], 0, 200, 50, 50);//������
	getimage(&people_img[2], 100, 200, 50, 50);//������
	getimage(&people_img[3], 50, 200, 50, 50);//������
	getimage(&people_img[4], 150, 200, 50, 50);//������
	SetWorkingImage(NULL);
	loadimage(&image_rc2, "image\\image2.bmp");
	SetWorkingImage(&image_rc2);
	getimage(&people_img[5], 0, 200, 50, 50);//���վ��
	getimage(&people_img[6], 50, 200, 50, 50);//����վ��
	getimage(&people_img[7], 150, 200, 50, 50);//����վ��
	SetWorkingImage(NULL);
}
void getbackgroundimg()
{
	loadimage(&image_rc1, "image\\image.bmp");
	SetWorkingImage(&image_rc1);
	getimage(&backgroundimg, 0, 0, 50, 50);
	SetWorkingImage(NULL);
}
void getboximg()
{
	loadimage(&image_rc1, "image\\image.bmp");
	SetWorkingImage(&image_rc1);
	getimage(&boximg, 100, 0, 50, 50);
	SetWorkingImage(NULL);
}
void getbox2img()
{
	loadimage(&image_rc1, "image\\image.bmp");
	SetWorkingImage(&image_rc1);
	getimage(&box2img, 150, 0, 50, 50);
	SetWorkingImage(NULL);
}
void getwallimg()
{
	loadimage(&image_rc1, "image\\image.bmp");
	SetWorkingImage(&image_rc1);
	getimage(&wallimg, 0, 100, 50, 50);
	SetWorkingImage(NULL);
}
void getpointimg()
{
	loadimage(&image_rc1, "image\\image.bmp");
	SetWorkingImage(&image_rc1);
	getimage(&pointimg, 0, 50, 50, 50);
	SetWorkingImage(NULL);
}
void clean(int x, int y)//���һƬ����
{
	clearrectangle(x, y, x + 49, y + 49);
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
	clean(x, y);
	putimage(x, y, &boximg, SRCINVERT);
}
void box2(int x, int y)//��һ������Ŀ�������ӣ�����Ϊ�������ĵ�xy����
{
	x = 50 * x;
	y = 50 * y;
	clean(x, y);
	putimage(x, y, &box2img, SRCINVERT);
}
void background(int x, int y)
{
	x = 50 * x;
	y = 50 * y;
	clean(x, y);
	putimage(x, y, &backgroundimg, SRCINVERT);
}
void point(int x, int y)//��һ��Ŀ��㣬����ΪĿ������ĵ�xy����
{
	x = 50 * x;
	y = 50 * y;
	clean(x, y);
	putimage(x, y, &pointimg, SRCINVERT);
}
void people(int x, int y)//��һ������վ�����ˣ�����Ϊ�����Ͻ�xy����
{
	x = 50 * x;
	y = 50 * y;
	clean(x, y);
	putimage(x, y,&people_img[0],SRCINVERT);
}
void people11(int x, int y)//��һ������վ�����ˣ�����Ϊ�����Ͻ�xy����
{
	x = 50 * x;
	y = 50 * y;
	clean(x, y);
	putimage(x, y, &people_img[5], SRCINVERT);
}
void people1(int x, int y)//��һ�������ߵ��ˣ�����Ϊ�����Ͻ�xy����
{
	x = 50 * x;
	y = 50 * y;
	clean(x, y);
	putimage(x, y, &people_img[1], SRCINVERT);
	Sleep(100);
}
void people2(int x, int y)//��һ�������ߵ��ˣ�����Ϊ�����Ͻ�xy����
{
	x = 50 * x;
	y = 50 * y;
	clean(x, y);
	putimage(x, y, &people_img[2], SRCINVERT);
	Sleep(100);
}
void people33(int x, int y)//��һ������վ�����ˣ�����Ϊ�����Ͻ�xy����
{
	x = 50 * x;
	y = 50 * y;
	clean(x, y);
	putimage(x, y, &people_img[6], SRCINVERT);
}
void people3(int x, int y)//��һ����ת���ˣ�����Ϊ�����Ͻ�xy����
{
	x = 50 * x;
	y = 50 * y;
	clean(x, y);
	putimage(x, y, &people_img[3], SRCINVERT);
	Sleep(100);
}
void people44(int x, int y)//��һ������վ�����ˣ�����Ϊ�����Ͻ�xy����
{
	x = 50 * x;
	y = 50 * y;
	clean(x, y);
	putimage(x, y, &people_img[7], SRCINVERT);
}
void people4(int x, int y)//��һ����ת���ˣ�����Ϊ�����Ͻ�xy����
{
	x = 50 * x;
	y = 50 * y;
	clean(x, y);
	putimage(x, y, &people_img[4], SRCINVERT);
	Sleep(100);
}
