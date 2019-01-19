#include"stdafx.h"
#include"Snake.h"
#include<iostream>
#include<Windows.h>
#include<string>

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

using namespace std;

//======================================================================================

void gotoxy(short x, short y);
void color_out(string st, short x);
void c_out(string st, short x);
void shade_out(string st, short x, short y, int s, bool z);
void shade_out_r(string st, short x, short y, int s, bool a, bool z);
int *settings_synchronization();
int *statistics_synchronization();
void main_menu_video();
void menu_frame();
void menu_print(short id);
void help_print(short id, short x);
void game_state();
void hide_mouse();
void menu_choose_print(short id, short to, int a);
void menu_back_print(short id);
void end();
void normal_settings_show(short id, short choose);
void normal_settings_set(short id, short choose);
void settings_write();
void main_menu_video();
void pogress_bar();
void settings_initialization();
void statistics_initialization();
void waitting(string title, string st1, string st2, string st3, string answer);
int _rand(int x);
void statistics_print(short Choose, bool Video);
void statistics_player_print(short Choose, bool Video);
void about_us();
void game();
void windowssize(short x, short y);
void statistics_read();
bool audio_open();
void audio_settings();
void audio_tidy();
void playsound(short id);
//void check_settings();

//======================================================================================

int *MenuSettingsData;
string MenuTextMenu[][10] =
{
	{},
	{
		"   主菜单   ",
		"              开始              ",
		"              设置              ",
		"              信息              ",
		"              退出              "
	},
	{
		"    开始    ",
		"              单人              ",
		"            敬请期待             "
	},
	{
		"    设置    ",
		"              难度              ",
		"              图像              ",
		"              声音              ",
		"              帮助              ",
		"            清除数据            "
	},
	{
		"    信息    ",
		"              统计              ",
		"             排行榜             ",
		"           日志与更新           ",
		"           关于贪吃蛇           "
	},
	{
		"    难度    ",
		"            难度值:    ",
		"          变速果实:    ",
		"          反转果实:    ",
		"          随机石柱:    "
	},
	{
		"    图像    ",
		"              颜色:     ",
		"              动画:     ",
		"           自定义色彩           ",
		"           自定义形状           "
	},
	{
		"    声音    ",
		"              开关:    ",
		"           自定义路径           "
	},
	{
		"    帮助    ",
		"              开关:    "
	},
	{
		"  清除数据  ",
		"            清除统计            ",
		"            清除设置            ",
		"            全部清除            "
	},
	{
		" 自定义色彩 ",
		"              蛇头:     ",
		"              蛇身:     ",
		"          普通果实:     ",
		"                墙:     ",
		"          变速果实:     ",
		"          随机石柱:     ",
		"          反转果实:     "
	},
	{
		" 自定义形状 ",
		"              蛇头:     ",
		"              蛇身:     ",
		"          普通果实:     ",
		"                墙:     ",
		"          变速果实:     ",
		"          随机石柱:     ",
		"          反转果实:     "
	},
	{
		"   已暂停   ",
		"            继续游戏            ",
		"              设置              ",
		"              信息              ",
		"            中断游戏            "
	},
	{
		"    设置    ",
		"              图像              ",
		"              声音              ",
		"              帮助              "
	}
};
//======================================================================================

void menu_settings_synchronization()
{
	MenuSettingsData = settings_synchronization();
}


void DIY_color_menu()
{
	hide_mouse();
	SetConsoleTitle(TEXT("贪吃蛇    自定义色彩"));
	gotoxy(4, 26);
	c_out("  Tips:按下W/S切换选项/加减设置值,D选定设置项,A退出选定,C返回上一级   ", 2);
	short choose = 1;
	short id = 10;
	bool temp = true;
	int x = 23, y = 12;
	menu_print(id);

	normal_settings_show(5, 1);
	normal_settings_show(6, 2);
	normal_settings_show(7, 3);
	normal_settings_show(8, 4);
	normal_settings_show(16, 5);
	normal_settings_show(17, 6);
	normal_settings_show(18, 7);

	while (temp)
	{
		switch (choose)
		{
		case 1:
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 2:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 3:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 4:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 5:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 6:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 7:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			break;
		}
		help_print(0, 1);
		game_state();
		//		check_settings();
		Sleep(200);
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN('C') || KEY_DOWN(VK_BACK) || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if ((KEY_DOWN('W') || KEY_DOWN(VK_UP)) && choose != 1)
				{
					choose--;
					break;
				}
				if (( KEY_DOWN('S') || KEY_DOWN(VK_DOWN) ) && choose != 7)
				{
					choose++;
					break;
				}
				if (KEY_DOWN('C') || KEY_DOWN(VK_BACK))
				{
					playsound(3);
					temp = false;
					break;
				}
				if (KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN(VK_RIGHT) )
				{
					switch (choose)
					{
					case 1:
						normal_settings_set(5, 1);
						break;
					case 2:
						normal_settings_set(6, 2);
						break;
					case 3:
						normal_settings_set(7, 3);
						break;
					case 4:
						normal_settings_set(8, 4);
						break;
					case 5:
						normal_settings_set(16, 5);
						break;
					case 6:
						normal_settings_set(17, 6);
						break;
					case 7:
						normal_settings_set(18, 7);
						break;
					}
					SetConsoleTitle(TEXT("贪吃蛇    自定义色彩"));
					gotoxy(4, 26);
					c_out("  Tips:按下W/S切换选项/加减设置值,D选定设置项,A退出选定,C返回上一级   ", 2);
					help_print(id, choose);
					game_state();
				}
			}
		}
	}

	help_print(0, 0);
	menu_back_print(id);
	x = 23, y = 12;
	for (int i = 1; i <= 7; i++)
	{
		gotoxy(x, y + i);
		cout << "                                ";
	}
}

void DIY_graph_menu()
{
	hide_mouse();
	SetConsoleTitle(TEXT("贪吃蛇    自定义形状"));
	gotoxy(4, 26);
	c_out("  Tips:按下W/S切换选项/加减设置值,D选定设置项,A退出选定,C返回上一级   ", 2);
	short choose = 1;
	short id = 11;
	bool temp = true;
	int x = 23, y = 12;
	menu_print(id);

	normal_settings_show(9, 1);
	normal_settings_show(10, 2);
	normal_settings_show(11, 3);
	normal_settings_show(12, 4);
	normal_settings_show(19, 5);
	normal_settings_show(20, 6);
	normal_settings_show(21, 7);

	while (temp)
	{
		switch (choose)
		{
		case 1:
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 2:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 3:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 4:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 5:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 6:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 7:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			break;
		}
		help_print(0, 1);
		game_state();
		//		check_settings();
		Sleep(200);
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN('C') || KEY_DOWN(VK_BACK) || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if ((KEY_DOWN('W') || KEY_DOWN(VK_UP)) && choose != 1)
				{
					choose--;
					break;
				}
				if (( KEY_DOWN('S') || KEY_DOWN(VK_DOWN) ) && choose != 7)
				{
					choose++;
					break;
				}
				if (KEY_DOWN('C') || KEY_DOWN(VK_BACK))
				{
					playsound(3);
					temp = false;
					break;
				}
				if (KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN(VK_RIGHT) )
				{
					switch (choose)
					{
					case 1:
						normal_settings_set(9, 1);
						break;
					case 2:
						normal_settings_set(10, 2);
						break;
					case 3:
						normal_settings_set(11, 3);
						break;
					case 4:
						normal_settings_set(12, 4);
						break;
					case 5:
						normal_settings_set(19, 5);
						break;
					case 6:
						normal_settings_set(20, 6);
						break;
					case 7:
						normal_settings_set(21, 7);
						break;
					}
					SetConsoleTitle(TEXT("贪吃蛇    自定义形状"));
					gotoxy(4, 26);
					c_out("  Tips:按下W/S切换选项/加减设置值,D选定设置项,A退出选定,C返回上一级   ", 2);
					help_print(id, choose);
					game_state();
				}
			}
		}
	}

	help_print(0, 0);
	menu_back_print(id);
	x = 23, y = 12;
	for (int i = 1; i <= 7; i++)
	{
		gotoxy(x, y + i);
		cout << "                                ";
	}
}

void difficulty_menu()
{
	hide_mouse();
	SetConsoleTitle(TEXT("贪吃蛇    难度"));
	gotoxy(4, 26);
	c_out(" Tips:按下W/S切换选项/加减设置值,D选定(设置项),A退出选定,C返回上一级  ", 2);
	short choose = 1;
	short id = 5;
	bool temp = true;
	int x = 23, y = 12;
	menu_print(id);

	normal_settings_show(22, 1);
	normal_settings_show(13, 2);
	normal_settings_show(15, 3);
	normal_settings_show(14, 4);

	while (temp)
	{
		switch (choose)
		{
		case 1:
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 2:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 3:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 4:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			break;
		}
		help_print(id, choose);
		//		check_settings();
		game_state();
		Sleep(200);
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN('C') || KEY_DOWN(VK_BACK) || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if ((KEY_DOWN('W') || KEY_DOWN(VK_UP)) && choose != 1)
				{
					choose--;
					break;
				}
				if (( KEY_DOWN('S') || KEY_DOWN(VK_DOWN) ) && choose != 4)
				{
					choose++;
					break;
				}
				if (KEY_DOWN('C') || KEY_DOWN(VK_BACK))
				{
					playsound(3);
					temp = false;
					break;
				}
				if (KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN(VK_RIGHT) )
				{
					switch (choose)
					{
					case 1:
						normal_settings_set(22, 1);
						break;
					case 2:
						normal_settings_set(13, 2);
						break;
					case 3:
						normal_settings_set(15, 3);
						break;
					case 4:
						normal_settings_set(14, 4);
						break;
					}
					SetConsoleTitle(TEXT("贪吃蛇    难度"));
					gotoxy(4, 26);
					c_out(" Tips:按下W/S切换选项/加减设置值,D选定(设置项),A退出选定,C返回上一级  ", 2);
					help_print(id, choose);
					game_state();
				}
			}
		}
	}

	help_print(0, 0);
	menu_back_print(id);
}

void image_menu()
{
	hide_mouse();
	SetConsoleTitle(TEXT("贪吃蛇    图像"));
	gotoxy(4, 26);
	c_out(" Tips:按下W/S切换选项/加减设置值,D选定(设置项),A退出选定,C返回上一级  ", 2);
	short choose = 1;
	short id = 6;
	bool temp = true;
	int x = 23, y = 12;
	menu_print(id);

	normal_settings_show(1, 1);
	normal_settings_show(2, 2);

	while (temp)
	{
		switch (choose)
		{
		case 1:
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 2:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 3:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 4:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			break;
		}
		help_print(id, choose);
		game_state();
		//		check_settings();
		Sleep(200);
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN('C') || KEY_DOWN(VK_BACK) || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if ((KEY_DOWN('W') || KEY_DOWN(VK_UP)) && choose != 1)
				{
					choose--;
					break;
				}
				if (( KEY_DOWN('S') || KEY_DOWN(VK_DOWN) ) && choose != 4)
				{
					choose++;
					break;
				}
				if (KEY_DOWN('C') || KEY_DOWN(VK_BACK))
				{
					playsound(3);
					temp = false;
					break;
				}
				if (KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN(VK_RIGHT))
				{
					help_print(0, 0);
					switch (choose)
					{
					case 1:
						normal_settings_set(1, 1);
						break;
					case 2:
						normal_settings_set(2, 2);
						break;
					case 3:
						playsound(2);
						menu_choose_print(6, 10, 3);
						DIY_color_menu();
						menu_print(id);
						break;
					case 4:
						playsound(2);
						menu_choose_print(6, 11, 4);
						DIY_graph_menu();
						menu_print(id);
						break;
					}
					normal_settings_show(1, 1);
					normal_settings_show(2, 2);
					SetConsoleTitle(TEXT("贪吃蛇    图像"));
					gotoxy(x, y + choose);
					c_out(MenuTextMenu[id][choose], 1);
					gotoxy(x + 6, y + choose);
					c_out("->", 1);
					gotoxy(4, 26);
					c_out(" Tips:按下W/S切换选项/加减设置值,D选定(设置项),A退出选定,C返回上一级  ", 2);
					help_print(id, choose);
					game_state();
				}
			}
		}
	}

	help_print(0, 0);
	menu_back_print(id);
}

void audio_menu()
{
	hide_mouse();
	SetConsoleTitle(TEXT("贪吃蛇    声音"));
	gotoxy(4, 26);
	c_out(" Tips:按下W/S切换选项/加减设置值,D选定(设置项),A退出选定,C返回上一级  ", 2);
	short choose = 1;
	short id = 7;
	bool temp = true;
	int x = 23, y = 12;
	menu_print(id);

	normal_settings_show(3, 1);

	while (temp)
	{
		switch (choose)
		{
		case 1:
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 2:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			break;
		}
		help_print(id, choose);
		game_state();
		//		check_settings();
		Sleep(200);
		bool redraw = false;
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN('C') || KEY_DOWN(VK_BACK) || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if ((KEY_DOWN('W') || KEY_DOWN(VK_UP)) && choose != 1)
				{
					choose--;
					break;
				}
				if (( KEY_DOWN('S') || KEY_DOWN(VK_DOWN) ) && choose != 2)
				{
					choose++;
					break;
				}
				if (KEY_DOWN('C') || KEY_DOWN(VK_BACK))
				{
					playsound(3);
					temp = false;
					break;
				}
				if (KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN(VK_RIGHT) )
				{
					short a = MenuSettingsData[3];
					switch (choose)
					{
					case 1:
						normal_settings_set(3, 1);
						if (a == 0 && MenuSettingsData[3] == 1) {
							audio_open();
							redraw = true;
						}
						break;
					case 2:
						playsound(2);
						audio_settings();
						redraw = true;
						break;
					}
					SetConsoleTitle(TEXT("贪吃蛇    声音"));
					gotoxy(4, 26);
					c_out(" Tips:按下W/S切换选项/加减设置值,D选定(设置项),A退出选定,C返回上一级  ", 2);
					help_print(id, choose);
					game_state();
					if (redraw == true) {
						main_menu_video();
						menu_print(id);
						gotoxy(x, y + choose);
						c_out(MenuTextMenu[id][choose], 1);
						gotoxy(x + 6, y + choose);
						c_out("->", 1);
						gotoxy(4, 26);
						c_out(" Tips:按下W/S切换选项/加减设置值,D选定(设置项),A退出选定,C返回上一级  ", 2);
						help_print(id, choose);
						game_state();
						normal_settings_show(3, 1);
					}
				}
			}
		}
	}

	help_print(0, 0);
	menu_back_print(id);
}

void help_menu()
{
	hide_mouse();
	SetConsoleTitle(TEXT("贪吃蛇    帮助"));
	gotoxy(4, 26);
	c_out(" Tips:按下W/S切换选项/加减设置值,D选定(设置项),A退出选定,C返回上一级  ", 2);
	short choose = 1;
	short id = 8;
	bool temp = true;
	int x = 23, y = 12;
	menu_print(id);

	normal_settings_show(4, 1);

	while (temp)
	{
		switch (choose)
		{
		case 1:
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		}
		help_print(id, choose);
		game_state();
		//		check_settings();
		Sleep(200);
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN('C') || KEY_DOWN(VK_BACK) || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if (KEY_DOWN('C') || KEY_DOWN(VK_BACK))
				{
					playsound(3);
					temp = false;
					break;
				}
				if (KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN(VK_RIGHT) )
				{
					switch (choose)
					{
					case 1:
						normal_settings_set(4, 1);
						break;
					}
					gotoxy(4, 26);
					c_out(" Tips:按下W/S切换选项/加减设置值,D选定(设置项),A退出选定,C返回上一级  ", 2);
					help_print(id, choose);
					game_state();
				}
			}
		}
	}

	help_print(0, 0);
	menu_back_print(id);
}


void clear_menu()
{
	hide_mouse();
	SetConsoleTitle(TEXT("贪吃蛇    清除数据"));
	gotoxy(4, 26);
	c_out("                Tips:按下W/S切换选项,D选定,C返回上一级                ", 2);
	short choose = 1;
	short id = 9;
	bool temp = true;
	int x = 23, y = 12;
	menu_print(id);

	while (temp)
	{
		switch (choose)
		{
		case 1:
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 2:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 3:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			break;
		}
		help_print(id, choose);
		game_state();
		//		check_settings();
		Sleep(200);
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN('C') || KEY_DOWN(VK_BACK) || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if ((KEY_DOWN('W') || KEY_DOWN(VK_UP)) && choose != 1)
				{
					choose--;
					break;
				}
				if (( KEY_DOWN('S') || KEY_DOWN(VK_DOWN) ) && choose != 3)
				{
					choose++;
					break;
				}
				if (KEY_DOWN('C') || KEY_DOWN(VK_BACK))
				{
					playsound(3);
					temp = false;
					break;
				}
				if (KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN(VK_RIGHT) )
				{
					playsound(2);
					switch (choose)
					{
					case 1:
						waitting("    即将清除统计里的所有数据并初始化    ", "    您将丢失所有数据,游戏也需重新启动   ", "                  确定?                 ", "", "           Y:确定      N:取消           ");
						break;
					case 2:
						waitting("    即将清除设置里的所有数据并初始化    ", "    您将丢失所有数据,游戏也需重新启动   ", "                  确定?                 ", "", "           Y:确定      N:取消           ");
						break;
					case 3:
						waitting("        即将清除所有数据并初始化        ", "    您将丢失所有数据,游戏也需重新启动   ", "                  确定?                 ", "", "           Y:确定      N:取消           ");
						break;
					}
					while (true)
					{
						if (KEY_DOWN('Y'))
						{
							playsound(2);
							system("cls");
							for (int i = 0; i <= _rand(2) + 1; i++)
							{
								pogress_bar();
								Sleep(_rand(70) + 50);
							}
							switch (choose)
							{
							case 1:
								gotoxy(26, 20);
								c_out("      正在初始化统计                            ", 1);
								statistics_initialization();
								break;
							case 2:
								gotoxy(26, 20);
								c_out("      正在初始化设置                            ", 1);
								settings_initialization();
								break;
							case 3:
								gotoxy(26, 20);
								c_out("    正在初始化全部内容                          ", 1);
								settings_initialization();
								statistics_initialization();
								break;
							}
							for (int i = 0; i <= _rand(15) + 5; i++)
							{
								pogress_bar();
								Sleep(_rand(80) + 50);
							}
							gotoxy(26, 20);
							c_out("          完成                                  ", 1);
							for (int i = 0; i <= _rand(5) + 2; i++)
							{
								pogress_bar();
								Sleep(_rand(70) + 50);
							}
							exit(0);
						}
						if (KEY_DOWN('N'))
						{
							playsound(3);
							break;
						}
					}
					system("cls");
					main_menu_video();
					menu_print(id);
					gotoxy(4, 26);
					c_out("                Tips:按下W/S切换选项,D选定,C返回上一级                ", 2);
					help_print(id, choose);
					game_state();
					break;
				}

			}
		}
	}
	help_print(0, 0);
	menu_back_print(id);
}

void statistics_menu()
{
	statistics_read();
	hide_mouse();
	SetConsoleTitle(TEXT("贪吃蛇    统计"));
	gotoxy(4, 26);
	c_out("                     Tips:按下W/S浏览,C返回上一级                     ", 2);
	short choose = 1;
	bool temp = true;
	int x = 23, y = 12;
	statistics_print(choose, true);
	help_print(0, 1);
	while (temp)
	{
		statistics_print(choose, false);
		game_state();
		//		check_settings();
		Sleep(200);
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN('C') || KEY_DOWN(VK_BACK) || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if ((KEY_DOWN('W') || KEY_DOWN(VK_UP)) && choose != 1)
				{
					choose--;
					break;
				}
				if (( KEY_DOWN('S') || KEY_DOWN(VK_DOWN) ) && choose != 3)
				{
					choose++;
					break;
				}
				if (KEY_DOWN('C') || KEY_DOWN(VK_BACK))
				{
					playsound(3);
					temp = false;
					break;
				}
			}
		}
	}
	help_print(0, 0);
	x = 23, y = 12;
	for (int i = 1; i <= 8; i++)
	{
		gotoxy(x, y + i);
		cout << "                                ";
	}
}

void statistics_player_menu()
{
	hide_mouse();
	SetConsoleTitle(TEXT("贪吃蛇    排行榜"));
	gotoxy(4, 26);
	c_out("                     Tips:按下W/S浏览,C返回上一级                     ", 2);
	short choose = 1;
	bool temp = true;
	int x = 23, y = 12;
	statistics_player_print(choose, true);
	help_print(0, 1);
	while (temp)
	{
		statistics_player_print(choose, false);
		game_state();
		//		check_settings();
		Sleep(200);
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN('C') || KEY_DOWN(VK_BACK) || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if ((KEY_DOWN('W') || KEY_DOWN(VK_UP)) && choose != 1)
				{
					choose--;
					break;
				}
				if (( KEY_DOWN('S') || KEY_DOWN(VK_DOWN) ) && choose != 3)
				{
					choose++;
					break;
				}
				if (KEY_DOWN('C') || KEY_DOWN(VK_BACK))
				{
					playsound(3);
					temp = false;
					break;
				}
			}
		}
	}
	help_print(0, 0);
	x = 23, y = 12;
	for (int i = 1; i <= 8; i++)
	{
		gotoxy(x, y + i);
		cout << "                                ";
	}
}

bool begin_menu()
{
	bool played = false;
	hide_mouse();
	SetConsoleTitle(TEXT("贪吃蛇    开始"));
	gotoxy(4, 26);
	c_out("                Tips:按下W/S切换选项,D选定,C返回上一级               ", 2);
	short choose = 1;
	short id = 2;
	bool temp = true;
	int x = 23, y = 12;
	menu_print(id);
	while (temp)
	{
		switch (choose)
		{
		case 1:
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 2:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			break;
		}
		help_print(id, choose);
		game_state();
		//		check_settings();
		Sleep(200);
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN('C') || KEY_DOWN(VK_BACK) || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if ((KEY_DOWN('W') || KEY_DOWN(VK_UP)) && choose != 1)
				{
					choose--;
					break;
				}
				if (( KEY_DOWN('S') || KEY_DOWN(VK_DOWN) ) && choose != 1)
				{
					choose++;
					break;
				}
				if (KEY_DOWN('C') || KEY_DOWN(VK_BACK))
				{
					playsound(3);
					temp = false;
					break;
				}
				if (KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN(VK_RIGHT) )
				{
					playsound(2);
					played = true;
					help_print(0, 0);
					switch (choose)
					{
					case 1:
						game();
						break;
					}
					system("cls");
					temp = false;
					return played;
				}
			}
		}
	}
	help_print(0, 0);
	menu_back_print(id);
	return played;
}

void settings_menu()
{
	hide_mouse();
	SetConsoleTitle(TEXT("贪吃蛇    设置"));
	gotoxy(4, 26);
	c_out("                Tips:按下W/S切换选项,D选定,C返回上一级                ", 2);
	short choose = 1;
	short id = 3;
	bool temp = true;
	int x = 23, y = 12;
	menu_print(id);
	while (temp)
	{
		switch (choose)
		{
		case 1:
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 2:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 3:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 4:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
		case 5:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			break;
		}
		help_print(id, choose);
		game_state();
		//		check_settings();
		Sleep(200);
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN('C') || KEY_DOWN(VK_BACK) || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if ((KEY_DOWN('W') || KEY_DOWN(VK_UP)) && choose != 1)
				{
					choose--;
					break;
				}
				if (( KEY_DOWN('S') || KEY_DOWN(VK_DOWN) ) && choose != 5)
				{
					choose++;
					break;
				}
				if (KEY_DOWN('C') || KEY_DOWN(VK_BACK))
				{
					playsound(3);
					temp = false;
					break;
				}
				if (KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN(VK_RIGHT) )
				{
					playsound(2);
					help_print(0, 0);
					switch (choose)
					{
					case 1:
						menu_choose_print(3, 5, 1);
						difficulty_menu();
						break;
					case 2:
						menu_choose_print(3, 6, 2);
						image_menu();
						break;
					case 3:
						menu_choose_print(3, 7, 3);
						audio_menu();
						break;
					case 4:
						menu_choose_print(3, 8, 4);
						help_menu();
						break;
					case 5:
						menu_choose_print(3, 9, 5);
						clear_menu();
						break;
					}
					SetConsoleTitle(TEXT("贪吃蛇    设置"));
					help_print(id, choose);
					menu_print(id);
					gotoxy(x, y + choose);
					c_out(MenuTextMenu[id][choose], 1);
					gotoxy(x + 6, y + choose);
					c_out("->", 1);
					gotoxy(4, 26);
					c_out("                Tips:按下W/S切换选项,D选定,C返回上一级                ", 2);
					help_print(id, choose);
					game_state();
				}
			}
		}
	}
	shade_out("▼", 76, 13, 50, false);
	shade_out("■", 76, 14, 50, false);
	shade_out("保存中", 74, 15, 50, false);
	help_print(0, 0);
	menu_back_print(id);
	settings_write();
	audio_tidy();
	main_menu_video();
}

void informational_menu()
{
	bool tempb = false;
	hide_mouse();
	SetConsoleTitle(TEXT("贪吃蛇    信息"));
	gotoxy(4, 26);
	c_out("                Tips:按下W/S切换选项,D选定,C返回上一级                ", 2);
	short choose = 1;
	short id = 4;
	bool temp = true;
	int x = 23, y = 12;
	menu_print(id);
	while (temp)
	{
		switch (choose)
		{
		case 1:
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 2:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 3:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 4:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			break;
		}
		help_print(id, choose);
		game_state();
		//		check_settings();
		Sleep(200);
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN('C') || KEY_DOWN(VK_BACK) || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if ((KEY_DOWN('W') || KEY_DOWN(VK_UP)) && choose != 1)
				{
					choose--;
					break;
				}
				if (( KEY_DOWN('S') || KEY_DOWN(VK_DOWN) ) && choose != 4)
				{
					choose++;
					break;
				}
				if (KEY_DOWN('C') || KEY_DOWN(VK_BACK))
				{
					playsound(3);
					temp = false;
					break;
				}
				if (KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN(VK_RIGHT) )
				{
					playsound(2);
					help_print(0, 0);
					switch (choose)
					{
					case 1:
						statistics_menu();
						break;
					case 2:
						statistics_player_menu();
						break;
					case 3:
						ShellExecute(NULL, TEXT("open"), TEXT("http://f-studio.top/dl/snake.html"), NULL, NULL, SW_SHOWNORMAL);
						tempb = true;
						break;
					case 4:
						tempb = true;
						about_us();
						main_menu_video();
						menu_print(id);
						break;
					}
					SetConsoleTitle(TEXT("贪吃蛇    信息"));
					if (tempb != true) {
						menu_print(id);
					}
						tempb = false;
						help_print(id, choose);
						gotoxy(x, y + choose);
						c_out(MenuTextMenu[id][choose], 1);
						gotoxy(x + 6, y + choose);
						c_out("->", 1);
						gotoxy(4, 26);
						c_out("                Tips:按下W/S切换选项,D选定,C返回上一级                ", 2);
						game_state();

				}
			}
		}
	}
	help_print(0, 0);
	menu_back_print(id);
}

void pause_settings_menu()
{
	hide_mouse();
	SetConsoleTitle(TEXT("贪吃蛇    设置"));
	gotoxy(4, 26);
	c_out("                Tips:按下W/S切换选项,D选定,C返回上一级                ", 2);
	short choose = 1;
	short id = 13;
	bool temp = true;
	int x = 23, y = 12;
	menu_print(id);
	while (temp)
	{
		switch (choose)
		{
		case 1:
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 2:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 3:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			break;
		}
		help_print(id, choose);
		game_state();
		//		check_settings();
		Sleep(200);
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN('C') || KEY_DOWN(VK_BACK) || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if ((KEY_DOWN('W') || KEY_DOWN(VK_UP)) && choose != 1)
				{
					choose--;
					break;
				}
				if ((KEY_DOWN('S') || KEY_DOWN(VK_DOWN)) && choose != 3)
				{
					choose++;
					break;
				}
				if (KEY_DOWN('C') || KEY_DOWN(VK_BACK))
				{
					playsound(3);
					temp = false;
					break;
				}
				if (KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN(VK_RIGHT))
				{
					playsound(2);
					help_print(0, 0);
					switch (choose)
					{
					case 1:
						menu_choose_print(13, 6, 1);
						image_menu();
						break;
					case 2:
						menu_choose_print(13, 7, 2);
						audio_menu();
						break;
					case 3:
						menu_choose_print(13, 8, 3);
						help_menu();
						break;
					}
					SetConsoleTitle(TEXT("贪吃蛇    设置"));
					help_print(id, choose);
					menu_print(id);
					gotoxy(x, y + choose);
					c_out(MenuTextMenu[id][choose], 1);
					gotoxy(x + 6, y + choose);
					c_out("->", 1);
					gotoxy(4, 26);
					c_out("                Tips:按下W/S切换选项,D选定,C返回上一级                ", 2);
					help_print(id, choose);
					game_state();
				}
			}
		}
	}
	shade_out("▼", 76, 13, 50, false);
	shade_out("■", 76, 14, 50, false);
	shade_out("保存中", 74, 15, 50, false);
	help_print(0, 0);
	menu_back_print(id);
	settings_write();
	main_menu_video();
}

bool pause_menu()
{
	hide_mouse();
	system("cls");
	system("mode con cols=80 lines=31");
	//	windowssize(80, 30);
	SetConsoleTitle(TEXT("贪吃蛇    已暂停"));
	main_menu_video();
	gotoxy(4, 26);
	c_out("                      Tips:按下W/S切换选项,D选定                      ", 2);
	help_print(0, 0);
	short choose = 1;
	short id = 12;
	bool temp = true;
	int x = 23, y = 12;
	menu_print(id);
	while (temp)
	{
		switch (choose)
		{
		case 1:
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 2:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 3:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 4:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			break;
		}
		help_print(id, choose);
		game_state();
		//		check_settings();
		Sleep(200);
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if ((KEY_DOWN('W') || KEY_DOWN(VK_UP)) && choose != 1)
				{
					choose--;
					break;
				}
				if ((KEY_DOWN('S') || KEY_DOWN(VK_DOWN)) && choose != 4)
				{
					choose++;
					break;
				}
				if (KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN(VK_RIGHT))
				{
					playsound(2);
					help_print(0, 0);
					switch (choose)
					{
					case 1:
						return false;
						break;
					case 2:
						menu_choose_print(12, 13, 2);
						pause_settings_menu();
						Sleep(200);
						shade_out_r("▼", 76, 13, 50, false, false);
						shade_out_r("■", 76, 14, 50, false, false);
						shade_out_r("保存中", 74, 15, 50, false, false);
						break;
					case 3:
						menu_choose_print(12, 4, 3);
						informational_menu();
						break;
					case 4:
						return true;
						break;
					}
					SetConsoleTitle(TEXT("贪吃蛇    已暂停"));
					help_print(id, choose);
					menu_print(id);
					gotoxy(x, y + choose);
					c_out(MenuTextMenu[id][choose], 1);
					gotoxy(x + 6, y + choose);
					c_out("->", 1);
					gotoxy(4, 26);
					c_out("                      Tips:按下W/S切换选项,D选定                      ", 2);
					help_print(id, choose);
					game_state();
				}
			}
		}
	}
	return false;
}

void main_menu()
{
	playsound(1);
	bool played;
GameStart:
	played = false;
	hide_mouse();
	system("cls");
	system("mode con cols=80 lines=31");
//	windowssize(80, 30);
	SetConsoleTitle(TEXT("贪吃蛇    主菜单"));
	main_menu_video();
	gotoxy(4, 26);
	c_out("                      Tips:按下W/S切换选项,D选定                      ", 2);
	help_print(0, 0);
	short choose = 1;
	short id = 1;
	bool temp = true;
	int x = 23, y = 12;
	menu_print(id);
	while (temp)
	{
		switch (choose)
		{
		case 1:
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 2:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 3:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			gotoxy(x, y + 1 + choose);
			cout << MenuTextMenu[id][choose + 1];
			break;
		case 4:
			gotoxy(x, y - 1 + choose);
			cout << MenuTextMenu[id][choose - 1];
			gotoxy(x, y + choose);
			c_out(MenuTextMenu[id][choose], 1);
			gotoxy(x + 6, y + choose);
			c_out("->", 1);
			break;
		}
		help_print(id, choose);
		game_state();
		//		check_settings();
		Sleep(200);
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if ((KEY_DOWN('W') || KEY_DOWN(VK_UP)) && choose != 1)
				{
					choose--;
					break;
				}
				if (( KEY_DOWN('S') || KEY_DOWN(VK_DOWN) ) && choose != 4)
				{
					choose++;
					break;
				}
				if (KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN(VK_RIGHT) )
				{
					playsound(2);
					help_print(0, 0);
					switch (choose)
					{
					case 1:
						menu_choose_print(1, 2, 1);
						played=begin_menu();
						if(played==true)
							goto GameStart;
						break;
					case 2:
						menu_choose_print(1, 3, 2);
						settings_menu();
						Sleep(200);
						shade_out_r("▼", 76, 13, 50, false, false);
						shade_out_r("■", 76, 14, 50, false, false);
						shade_out_r("保存中", 74, 15, 50, false, false);
						break;
					case 3:
						menu_choose_print(1, 4, 3);
						informational_menu();
						break;
					case 4:
						end();
						break;
					}
					SetConsoleTitle(TEXT("贪吃蛇    主菜单"));
					help_print(id, choose);
					menu_print(id);
					gotoxy(x, y + choose);
					c_out(MenuTextMenu[id][choose], 1);
					gotoxy(x + 6, y + choose);
					c_out("->", 1);
					gotoxy(4, 26);
					c_out("                      Tips:按下W/S切换选项,D选定                      ", 2);
					help_print(id, choose);
					game_state();
				}
			}
		}
	}
}