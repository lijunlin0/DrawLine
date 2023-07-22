#include <graphics.h>
#include <conio.h>
#include<iostream>
#include<math.h>
using namespace std;

const int WIDTH = 1000;
const int HEIGHT = 1000;

void DDA(int x1, int y1, int x2, int y2)
{
	float k = (float)(y2 - y1) / (float)(x2 - x1);

	if (x2 - x1 != 0)//kֵ����
	{
		if (abs(k) <= 1)//|k|<=1
		{
			if (x1 > x2)
			{
				int num = x1;
				x1 = x2;
				x2 = num;
				num = y1;
				y1 = y2;
				y2 = num;
			}
			float y = y1;
			for (; x1 <= x2; x1++)
			{
				putpixel(x1, int(y + 0.5), WHITE);
				y += k;
			}
		}
		else if (abs(k) > 1)//|k|>1
		{
			if (y1 > y2)
			{
				int num = x1;
				x1 = x2;
				x2 = num;
				num = y1;
				y1 = y2;
				y2 = num;
			}
			float x = x1;
			float factor = 1 / k;
			for (; y1 <= y2; y1++)
			{
				putpixel(int(x + 0.5), y1, WHITE);
				x += factor;
			}
		}
	}
	else//kֵ������
	{
		int y = (y1 > y2) ? y2 : y1;
		int Y = (y1 > y2) ? y1 : y2;
		for (; y <= Y; y++)
		{
			putpixel(x1, y, WHITE);
		}
	}
}

void Bresenham(int x1, int y1, int x2, int y2)
{
	int dy = abs(y2 - y1);
	int dx = abs(x2 - x1);
	int d = 2 * dy - dx;
	float k = (float)(y2 - y1) / (float)(x2 - x1);
	int addX = x1 < x2 ? 1 : -1;
	int addY = y1 < y2 ? 1 : -1;
	int sub = abs(k) > 1 ? 2 * dy : 2 * dx;
	int add = abs(k) > 1 ? 2 * dx : 2 * dy;
	if (abs(k) <= 1)
	{
		putpixel(x1, y1, RED);
		while (x1 != x2)
		{
			x1 += addX;
			if (d >= 0)
			{
				y1 += addY;
				d = d - sub;
			}
			d = d + add;
			putpixel(x1, y1, RED);
		}

	}
	else if (abs(k) > 1)
	{
		putpixel(x1, y1, RED);
		while (y1 != y2)
		{
			y1 += addY;
			if (d >= 0)
			{
				x1 += addX;
				d = d - sub;
			}
			d = d + add;
			putpixel(x1, y1, RED);
		}
	}
	cout << k << endl;
}

int main()
{
	srand((int)time(0));
	initgraph(WIDTH, HEIGHT, SHOWCONSOLE);
	//���½�Ϊ����ԭ�㣬X������Ϊ����Y������Ϊ��
	setaspectratio(1, -1);
	setorigin(0, HEIGHT);
	/*
	Bresenham(320, 240, 0, 0);
	Bresenham(320, 240, 160, 0);
	Bresenham(320, 240, 320, 0);
	Bresenham(320, 240, 480, 0);
	Bresenham(320, 240, 640, 0);
	Bresenham(320, 240, 640, 120);
	Bresenham(320, 240, 640, 240);
	Bresenham(320, 240, 640, 360);
	Bresenham(320, 240, 640, 480);
	Bresenham(320, 240, 480, 480);
	Bresenham(320, 240, 320, 480);
	Bresenham(320, 240, 160, 480);
	Bresenham(320, 240, 0, 480);
	Bresenham(320, 240, 0, 360);
	Bresenham(320, 240, 0, 240);
	Bresenham(320, 240, 0, 120);
	*/
	getchar();
	return 0;
}