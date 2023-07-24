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

	if (x2 - x1 != 0)//k值存在
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
				putpixel(x1, int(y + 0.5), LIGHTBLUE);
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
				putpixel(int(x + 0.5), y1, LIGHTBLUE);
				x += factor;
			}
		}
	}
	else//k值不存在
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
		putpixel(x1, y1, LIGHTRED);
		while (x1 != x2)
		{
			x1 += addX;
			if (d >= 0)
			{
				y1 += addY;
				d = d - sub;
			}
			d = d + add;
			putpixel(x1, y1, LIGHTRED);
		}

	}
	else if (abs(k) > 1)
	{
		putpixel(x1, y1, LIGHTRED);
		while (y1 != y2)
		{
			y1 += addY;
			if (d >= 0)
			{
				x1 += addX;
				d = d - sub;
			}
			d = d + add;
			putpixel(x1, y1, LIGHTRED);
		}
	}
	cout << k << endl;
}

void CircleBresenham(int x,int y,int r)
{
	int d = 1 - r;
	int X = 0;
	int Y = r;
	for (; X <= Y; X++)
	{
		putpixel(X + x, Y + y, WHITE);
		putpixel(Y + y, X + x, WHITE);
		putpixel(Y + y, -X + x, WHITE);
		putpixel(-X + x, Y + y, WHITE);
		putpixel(-X + x, -Y + y, WHITE);
		putpixel(-Y + y, -X + x, WHITE);
		putpixel(-Y + y, X + x, WHITE);
		putpixel(X + x, -Y + y, WHITE);
		if (d > 0)
		{
			d = d - 2 * Y + 2;
			Y--;
		}
		d += 2 * X + 3;
	}

}

int main()
{
	srand((int)time(0));
	initgraph(WIDTH, HEIGHT, SHOWCONSOLE);
	//左下角为坐标原点，X轴向右为正，Y轴向上为正
	setaspectratio(1, -1);
	setorigin(0, HEIGHT);
	DDA(200, 300, 900, 500);
	Bresenham(200, 200, 800, 900);
	CircleBresenham(500, 500, 300);
	getchar();
	return 0;
}