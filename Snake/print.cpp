//wall 1|snakeb 2|snakeh 3|food 4

#include "stdafx.h"
#include<iostream>
#include<Windows.h>
#include"Snake.h"
#include<string>
using namespace std;

//======================================================================================

void gotoxy(short x, short y);
int *settings_synchronization();
int *statistics_synchronization();
void hide_mouse();
int _rand(int x);
void windowssize(short x, short y);

//======================================================================================

int *PrintSettingsData;

string Graph[200] = { "",
"◆","●","◎","■","█","△","▲","▽","▼","○",
"□","☆","★","×","√","‥","…","※","§","¤",
"‖","卍","〓","＠","№","◤","◥","◢","◣","↑",
"↗","→","↘","↓","↙","←","↖","＜","≮","≤",
"＞","≯","≥","＝","≈","≒","≡","±","㏒","㏑",
"·","∶","∵","∴","∷","∑","∏","∝","∞","∽",
"≌","∈","∩","∪","∧","∨","⊙","⊕","⌒","⊿",
"∥","⊥","∟","∠","∣","∫","％","‰","℅","∮",
"°","℃","℉","Γ","Θ","Λ","Ξ","π","Υ","Φ",
"Ψ","Ω","α","β","γ","δ","ε","ζ","η","θ",
"ι","λ","μ","ξ","σ","τ","ω","ρ",
};
//======================================================================================

void print_settings_synchronization()//数据同步
{
	PrintSettingsData = settings_synchronization();
}

void color_out(string st, short id)
{
	if (id == 15)//如果id为15就取随机值
	{
		id = _rand(15) + 1;
	}
	switch (id)
	{
	case 0://WHITE白（默认）
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	case 1://L_WHITE亮白
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	case 2://GREY灰
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
		break;
	case 3://RED红
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		break;
	case 4://PINK粉
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		break;
	case 5://BULE蓝
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
		break;
	case 6://L_BLUE淡蓝
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		break;
	case 7://GREEN绿
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		break;
	case 8://L_GREEN淡绿
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		break;
	case 9://GOLDEN金
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	case 10://YELLOW黄
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	case 11://PURLPE紫
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
		break;
	case 12://INDIGO靛
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		break;
	case 13://CYAN青
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	case 14://CYANINE菁
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	}
	cout << st;//输出内容
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//色彩改回白色
}

void c_out(string st, short x)
{
	if (PrintSettingsData[1] == 1)//如果颜色开就使用彩色输出,否则输出白色
	{
		color_out(st, x);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << st;
	}
}

void graph_out(short id, short color, bool x)//字符输出-如果x为真:彩色输出字符，假:使用普通色彩输出(是否输出色彩根据色彩开关)
{
	if (true == x)
	{
		color_out(Graph[id], color);
	}
	else
	{
		c_out(Graph[id], color);
	}
}

void g_out(short id, bool x)//普通字符输出(根据id匹配设置的字符)
{
	switch (id)
	{
	case 1:
		graph_out(PrintSettingsData[12], PrintSettingsData[8], x);
		break;
	case 2:
		graph_out(PrintSettingsData[10], PrintSettingsData[6], x);
		break;
	case 3:
		graph_out(PrintSettingsData[9], PrintSettingsData[5], x);
		break;
	case 4:
		graph_out(PrintSettingsData[11], PrintSettingsData[7], x);
		break;
	case 5:
		graph_out(PrintSettingsData[19], PrintSettingsData[16], x);
		break;
	case 6:
		graph_out(PrintSettingsData[20], PrintSettingsData[17], x);
		break;
	case 7:
		graph_out(PrintSettingsData[21], PrintSettingsData[18], x);
		break;
	}
}

void shade_out(string st, short x, short y, int s, bool z)//渐变输出
{
	if (z == false && (PrintSettingsData[1] == 0 || PrintSettingsData[2] == 0))//使用条件：色彩+动画都开
	{
		gotoxy(x, y);
		color_out(st, 0);
		Sleep(s);
	}
	else
	{
		gotoxy(x, y);
		color_out(st, 2);
		Sleep(s);
		gotoxy(x, y);
		color_out(st, 0);
		Sleep(s);
		gotoxy(x, y);
		color_out(st, 1);
		Sleep(s);
	}
}

void shade_out_r(string st, short x, short y, int s, bool a, bool z)//渐变消失
{
	if (z == false && (PrintSettingsData[1] == 0 || PrintSettingsData[2] == 0))//使用条件：色彩+动画都开
	{
		int b = st.size();
		gotoxy(x, y);
		while (b--)
		{
			cout << " ";
		}
		Sleep(s);
	}
	else
	{
		if (a == true)
		{
			gotoxy(x, y);
			color_out(st, 1);
			Sleep(s);
		}
		gotoxy(x, y);
		color_out(st, 0);
		Sleep(s);
		gotoxy(x, y);
		color_out(st, 2);
		Sleep(s);
		int b = st.size();
		gotoxy(x, y);
		while (b--)
		{
			cout << " ";
		}
		Sleep(s);
	}
}