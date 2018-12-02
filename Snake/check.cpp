#include"stdafx.h"
#include"Snake.h"
#include<iostream>
#include<Windows.h>
#include<fstream>
#include<io.h>
#include<stdlib.h>
#include<string>

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

using namespace std;

//======================================================================================

void gotoxy(short x, short y);
void color_out(string st, short x);
void pogress_bar();
void warning_cover();
void warning(string title, string st1, string st2, string st3, string answer);
void wrong_cover();
void wrong(string title, string st1, string st2, string st3, string answer);
int _rand(int x);
void wrong_end();
void statistics_initialization();
void statistics_read();
void settings_initialization();
void settings_read();
void audio_initialization();
void audio_read();
void shade_out(string st, short x, short y, int s, bool z);
void shade_out_r(string st, short x, short y, int s, bool a, bool z);
void hide_mouse();
int *settings_synchronization();
int *statistics_synchronization();
void windowssize(short x, short y);

//======================================================================================

void check()
{
	hide_mouse();
	system("mode con cols=80 lines=31");
//	windowssize(80, 30);
	system("cls");

	Sleep(500);
	shade_out("即将进行游戏检查，请稍后", 28, 12, 100, true);
	Sleep(1000);
	shade_out_r("即将进行游戏检查，请稍后", 28, 12, 100, false, true);
	system("cls");

	Sleep(500);
	SetConsoleTitle(TEXT("贪吃蛇  正在进行检查"));
	gotoxy(26, 20);
	color_out("正在检查 “settings.ini”                  ", 1);
	for (int i = 0; i <= _rand(2) + 1; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}
	if ((_access("settings.ini", 0)) == -1)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
		warning("                文件丢失                ", "     无法在.\\下找到“settings.ini”     ", "              即将重新创建              ", "", "");
		gotoxy(26, 20);
		color_out("正在创建“settings.ini”                              ", 1);
		Sleep(_rand(50) + 50);
		pogress_bar();
		ofstream settings;
		settings.open("settings.ini");
		settings.close();
		gotoxy(26, 20);
		color_out("正在初始化“settings.ini”                              ", 1);
		Sleep(_rand(50) + 50);
		pogress_bar();
		settings_initialization();
		Sleep(_rand(50) + 50);
	}
	pogress_bar();
	Sleep(_rand(50) + 50);
	if ((_access("settings.ini", 2)) == -1)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
		warning("             文件无法读写               ", "   “.\\settings.ini”开启了读写写保护   ", "              正在尝试解决              ", "", "");
		gotoxy(26, 20);
		system("attrib -r settings.ini");
		color_out("正在检查 “settings.ini”                  ", 1);
		pogress_bar();
		gotoxy(1, 1);
		gotoxy(1, 1);
		cout << "                                   ";
		Sleep(_rand(50) + 50);
		pogress_bar();
		if ((_access("settings.ini", 2)) == -1)
		{
			pogress_bar();
			Sleep(200);
			wrong("              尝试解决无效              ", "    无法给予“.\\settings.ini”写权限    ", "           请查询帮助解决问题           ", "", "           Y:查看      N:取消           ");
			while (true)
			{
				if (KEY_DOWN('Y'))
				{
					ShellExecute(NULL, TEXT("open"), TEXT("http://f-studio.top/help/snake.html"), NULL, NULL, SW_SHOWNORMAL);
					break;
				}
				if (KEY_DOWN('N'))
				{
					break;
				}
			}
			Sleep(200);
			wrong_end();
		}
	}

	gotoxy(26, 20);
	color_out("正在检查 “statistics.ini”                              ", 1);
	for (int i = 0; i <= _rand(2); i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}

	gotoxy(26, 20);
	color_out("正在检查 “statistics.ini”                              ", 1);
	for (int i = 0; i <= _rand(2) + 1; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}
	if ((_access("statistics.ini", 0)) == -1)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
		warning("                文件丢失                ", "    无法在.\\下找到“statistics.ini”    ", "              即将重新创建              ", "", "");
		gotoxy(26, 20);
		color_out("正在创建“statistics.ini”                              ", 1);
		Sleep(_rand(50) + 50);
		pogress_bar();
		ofstream statistics;
		statistics.open("statistics.ini");
		statistics.close();
		gotoxy(26, 20);
		color_out("正在初始化“statistics.ini”                              ", 1);
		Sleep(_rand(50) + 50);
		pogress_bar();
		statistics_initialization();
		Sleep(_rand(50) + 50);
		pogress_bar();
		Sleep(_rand(50) + 50);
		pogress_bar();
		Sleep(_rand(50) + 50);
	}
	if ((_access("statistics.ini", 2)) == -1)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
		warning("             文件无法读写               ", "  “.\\statistics.ini”开启了读写写保护  ", "              正在尝试解决              ", "", "");
		gotoxy(26, 20);
		system("attrib -r statistics.ini");
		color_out("正在检查“statistics.ini”                              ", 1);
		pogress_bar();
		gotoxy(1, 1);
		gotoxy(1, 1);
		cout << "                                   ";
		Sleep(_rand(50) + 50);
		pogress_bar();
		if ((_access("statistics.ini", 2)) == -1)
		{
			pogress_bar();
			Sleep(200);
			wrong("              尝试解决无效              ", "   无法给予“.\\statistics.ini”写权限   ", "           请查询帮助解决问题           ", "", "           Y:查看      N:取消           ");
			while (true)
			{
				if (KEY_DOWN('Y'))
				{
					ShellExecute(NULL, TEXT("open"), TEXT("http://f-studio.top/help/snake.html"), NULL, NULL, SW_SHOWNORMAL);
					break;
				}
				if (KEY_DOWN('N'))
				{
					break;
				}
			}
			Sleep(200);
			wrong_end();
		}
	}

	gotoxy(26, 20);
	color_out("正在检查 “audio.ini”                              ", 1);
	for (int i = 0; i <= _rand(2); i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}
	gotoxy(26, 20);
	color_out("正在检查 “audio.ini”                              ", 1);
	for (int i = 0; i <= _rand(2) + 1; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}
	if ((_access("audio.ini", 0)) == -1)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
		warning("                文件丢失                ", "    无法在.\\下找到“audio.ini”       ", "              即将重新创建              ", "", "");
		gotoxy(26, 20);
		color_out("正在创建“audio.ini”                              ", 1);
		Sleep(_rand(50) + 50);
		pogress_bar();
		ofstream audio;
		audio.open("audio.ini");
		audio.close();
		gotoxy(26, 20);
		color_out("正在初始化“audio.ini”                              ", 1);
		Sleep(_rand(50) + 50);
		pogress_bar();
		audio_initialization();
		Sleep(_rand(50) + 50);
		pogress_bar();
		Sleep(_rand(50) + 50);
		pogress_bar();
		Sleep(_rand(50) + 50);
	}
	if ((_access("audio.ini", 2)) == -1)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
		warning("             文件无法读写               ", "  “.\\audio.ini”开启了读写写保护  ", "              正在尝试解决              ", "", "");
		gotoxy(26, 20);
		system("attrib -r audio.ini");
		color_out("正在检查“audio.ini”                              ", 1);
		pogress_bar();
		gotoxy(1, 1);
		gotoxy(1, 1);
		cout << "                                   ";
		Sleep(_rand(50) + 50);
		pogress_bar();
		if ((_access("audio.ini", 2)) == -1)
		{
			pogress_bar();
			Sleep(200);
			wrong("              尝试解决无效              ", "   无法给予“.\\audio.ini”写权限   ", "           请查询帮助解决问题           ", "", "           Y:查看      N:取消           ");
			while (true)
			{
				if (KEY_DOWN('Y'))
				{
					ShellExecute(NULL, TEXT("open"), TEXT("http://f-studio.top/help/snake.html"), NULL, NULL, SW_SHOWNORMAL);
					break;
				}
				if (KEY_DOWN('N'))
				{
					break;
				}
			}
			Sleep(200);
			wrong_end();
		}
	}

	gotoxy(20, 20);
	cout << "                                                      ";
	for (int i = 0; i <= _rand(15) + 5; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}

}

void files_read()
{
	hide_mouse();
	system("mode con cols=80 lines=31");
//	windowssize(80, 30);
	Sleep(500);
	system("cls");
	for (int i = 0; i <= _rand(5) + 3; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}
	gotoxy(26, 20);
	color_out("正在准备读取文件，请稍后...                              ", 1);
	for (int i = 0; i <= _rand(5) + 2; i++)
	{
		pogress_bar();
		Sleep(_rand(100) + 50);
	}

	for (int i = 0; i <= _rand(10) + 5; i++)
	{
		pogress_bar();
		Sleep(_rand(100) + 50);
	}
	gotoxy(26, 20);
	color_out("        正在读取设置                      ", 1);
	pogress_bar();
	Sleep(_rand(70) + 50);
	pogress_bar();
	Sleep(_rand(70) + 50);
	settings_read();
	for (int i = 0; i <= _rand(10) + 5; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}

	gotoxy(26, 20);
	color_out("        正在读取统计                      ", 1);
	pogress_bar();
	Sleep(_rand(60) + 50);
	pogress_bar();
	Sleep(_rand(60) + 50);
	statistics_read();
	for (int i = 0; i <= _rand(10) + 5; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}

	gotoxy(24, 20);
	color_out("        正在读取音频库                    ", 1);
	pogress_bar();
	Sleep(_rand(60) + 50);
	pogress_bar();
	Sleep(_rand(60) + 50);
	audio_read();
	for (int i = 0; i <= _rand(10) + 5; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}

	gotoxy(24, 20);
	color_out("            正在加载                ", 1);
	statistics_read();
	for (int i = 0; i <= _rand(10) + 2; i++)
	{
		pogress_bar();
		Sleep(_rand(90) + 50);
	}
	pogress_bar();
	Sleep(_rand(50) + 50);
	gotoxy(24, 20);
	color_out("            正在加载                ", 0);
	pogress_bar();
	Sleep(_rand(50) + 50);
	gotoxy(24, 20);
	color_out("            正在加载                ", 2);
	pogress_bar();
	Sleep(_rand(50) + 50);
	gotoxy(24, 20);
	cout << "                                    ";
	for (int i = 0; i <= _rand(5) + 2; i++)
	{
		pogress_bar();
		Sleep(_rand(60) + 50);
	}
	system("cls");
}