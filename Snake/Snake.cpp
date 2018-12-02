// Snake.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Snake.h"
#include<Windows.h>
#include<time.h>
#include <string.h>
#include <iostream>
#include<cstdlib>
using namespace std;

//======================================================================================

void prepare();
int _rand(int x);
void gotoxy(short x, short y);
void hide_mouse();
void check();
void op();
void files_read();
void main_menu();
void videos_settings_synchronization();
void menu_settings_synchronization();
void print_settings_synchronization();
void Game_settings_synchronization();
void audio_settings_synchronization();
void windowssize(short x, short y);
int *settings_synchronization();

//======================================================================================

int *SnakeSettingsData;

//======================================================================================

int main()
{
	prepare();
	main_menu();
	gotoxy(1, 26);
	return 0;
}

void prepare()
{
	SnakeSettingsData = settings_synchronization();
	SnakeSettingsData[3] = 1;
	audio_settings_synchronization();
	videos_settings_synchronization();
	menu_settings_synchronization();
	print_settings_synchronization();
	Game_settings_synchronization();
	hide_mouse();//准备
	SetConsoleTitle(TEXT("贪吃蛇"));
//	system("path=%path%c:\\Windows\\System32\\");
	system("mode con cols=80 lines=31");
//	windowssize(80, 30);

	check();
	SetConsoleTitle(TEXT("贪吃蛇"));
	op();
	files_read();
}

int _rand(int x)
{
	srand((int)time(0) + rand());//设置种子为时间+随机数
	int a;
	a = rand() % x;//取0~x的随机数
	return a;//返回取的数
}

void gotoxy(short x, short y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hide_mouse()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
}

bool AllisNum(string str)
{
	for (unsigned int i = 0; i < str.size(); i++)
	{
		int tmp = (int)str[i];
		if (tmp >= 48 && tmp <= 57)
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int wifi_check(int x, int i)
{
	int s = 0;
	x %= 10;
	int a = i % 5;
	switch (a)
	{
	case 1:
		s = (i + 9)*(x - 1) - x % 2;
		break;
	case 2:
		s = x % 3 + i;
		break;
	case 3:
		s = (x - 2)*(x + 1) - i;
		break;
	case 4:
		s = i*i + x + 3;
		break;
	case 5:
		s = x % 3 + (i + 2) * 2;
		break;
	}
	if (s<0)
	{
		s = -s;
	}
	return s % 10;
}

void wrong_end()
{
	system("cls");
	Sleep(500);
	exit(0);
}

void windowssize(short x, short y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//得到窗口句柄
	COORD size = { x,y };
	SMALL_RECT rc = { 1,1, x, y+1 }; //{Y位置,X位置,宽,高}
	SetConsoleWindowInfo(hOut, true, &rc);// 重置窗口位置和大小
}
