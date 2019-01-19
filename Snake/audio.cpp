#include"stdafx.h"
#include"Snake.h"
#include"INIReader.h"
#include<iostream>
#include<fstream>
#include<string>
#include<io.h>
#include<sstream>
#include<Windows.h>
#include<cmath>
#include <thread>
#pragma comment(lib, "winmm");

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

using namespace std;

//======================================================================================

void hide_mouse();
void warning(string title, string st1, string st2, string st3, string answer);
void wrong(string title, string st1, string st2, string st3, string answer);
void wrong_cover();
void gotoxy(short x, short y);
void color_out(string st, short x);
void pogress_bar();
int _rand(int x);
int *settings_synchronization();
void c_out(string st, short x);
void menu_back_print(short id);
void game_state();
void help_print(short id, short x);
void main_menu_video();
void shade_out(string st, short x, short y, int s, bool z);

//======================================================================================

struct audioInof {
	string name;
}AudioName[11];

short AudioData[10];
int *AudioSettingsData;
string AudioNames[] = {
	"",
	"start.wav",//1.开始
	"enter.wav",//2.进入
	"back.wav",//3.返回
	"exciting.wav",//4.兴奋
	"eating.wav",//5.进食
	"danger.wav",//6.危险
	"lose.wav",//7.失落
	"win.wav",//8.胜利
	"death.wav",//9.死亡
	"escape.wav"//10.逃跑
};
//======================================================================================

void audio_settings_synchronization()
{
	AudioSettingsData = settings_synchronization();
}

void _playsound(WCHAR *str) {
	PlaySound(str, NULL, SND_FILENAME | SND_SENTRY);
}
void playsound(short id) {
	if (AudioSettingsData[3] == 0)
		return;
	string sstr;
	sstr = ".\\Audio\\";
	sstr += AudioName[AudioData[2]].name;
	sstr += "\\";
	sstr += AudioNames[id];
	stringstream ss;
	char s[100];
	memset(s, ' ', sizeof(s));
	ss << sstr;
	ss >> s;
	WCHAR wszClassName[256];
	memset(wszClassName, 0, sizeof(wszClassName));
	MultiByteToWideChar(CP_ACP, 0, s, strlen(s) + 1, wszClassName,
		sizeof(wszClassName) / sizeof(wszClassName[0]));
	thread t(_playsound, wszClassName);
	t.detach();
}

void audio_initialization() {
	ofstream audio;
	audio.open("audio.ini", ios::trunc);
	audio << "//在这里添加音频库，具体方式请查阅帮助，上限10个！" << endl
		<< "[audio]" << endl
		<< "total=1" << endl
		<< "choice=1" << endl
		<< "1=default" << endl;
	audio.close();
}

bool Integrity_check(string st) {
	//用于通过测试
	//return true;
	string str;
	char c[100];
		for (int i = 1;i <= 10;i++) {
			memset(c, ' ', sizeof(c));
			str = ".\\Audio\\";
			str += st;
			str += "\\";
			str += AudioNames[i];
			stringstream ss;
			ss << str;
			ss >> c;
			if ((_access(c, 0)) == -1)
				return false;
		}
	return true;
}

void audio_tidy() {
	ofstream audio;
	audio.open("audio.ini", ios::trunc);
	audio << "//在这里添加音频库，具体方式请查阅帮助，上限10个！" << endl
		<< "[audio]" << endl
		<< "choice=" << to_string(AudioData[2]) << endl
		<< "total=" << to_string(AudioData[1]) << endl;
	for (int i = 1;i <= AudioData[1];i++) {
		audio << to_string(i) << "=" << AudioName[i].name << endl;
	}
	audio.close();
}

void audio_read_wrong()
{
	Sleep(200);
	warning("                文件错误                ", " .\\“audio.ini”已经被更改，无法读取 ", "               即将初始化               ", "", "");
	gotoxy(24, 20);
	color_out("      正在初始化“audio.ini”                     ", 1);
	Sleep(_rand(50) + 50);
	pogress_bar();
	audio_initialization();
	Sleep(_rand(50) + 50);
	pogress_bar();
	Sleep(_rand(50) + 50);
	pogress_bar();
	Sleep(_rand(50) + 50);
	gotoxy(24, 20);
	color_out("          正在读取音频库                         ", 1);
}

void audio_read_warning(short s)
{
	Sleep(200);
	warning("                文件错误                ", "     .\\“audio.ini”有错误部分   ", "             共有"+to_string(s)+"个失效内容     ", "", "");
	gotoxy(24, 20);
	color_out("       正在整理“audio.ini”                     ", 1);
	Sleep(_rand(50) + 50);
	pogress_bar();
	audio_tidy();
	Sleep(_rand(50) + 50);
	pogress_bar();
	Sleep(_rand(50) + 50);
	pogress_bar();
	Sleep(_rand(50) + 50);
	gotoxy(24, 20);
	color_out("          正在读取音频库                        ", 1);
}

void audio_no_warning(){
	Sleep(200);
	wrong("                文件丢失                ", "           没有可用的音频库   ", "     音频将关闭，您可以稍后自行开启     ", "", "");
	gotoxy(30, 17);
	system("pause");
	wrong_cover();
	return;
}

void audio_read()
{
start:
	hide_mouse();
	short total,truetotal=0;
	bool rewrite = false;
	string st;
	INIReader reader("audio.ini");
	if (reader.ParseError() < 0) {
		audio_read_wrong();
		goto start;
	}

	total= (short)reader.GetInteger("audio", "total" , -1);
	if (total == -1) {
		audio_read_wrong();
		goto start;
	}
	AudioData[2] = (short)reader.GetInteger("audio", "choice", -1);
	if (AudioData[2] == -1) {
		audio_read_wrong();
		goto start;
	}

	if (total > 10){
		total = 10;
	rewrite = true;
	}

	if (AudioData[2] < 1) {
		AudioData[2] = 1;
		rewrite = true;
	}

	short i = 0;
	while (true) {
		if (i+1 > total)
			break;
		else
			i++;
		st = reader.Get("audio", to_string(i), "UNKNOWN");
		if (st == "UNKNOWN") {
			rewrite = true;
		}
		else if (Integrity_check(st) == false) {
			rewrite = true;
		}
		else {
			truetotal++;
			AudioName[truetotal].name = st;
		}
	}
	if (truetotal < 1)
	{
		audio_no_warning();
		AudioSettingsData[3] = 0;
		return;
	}
	AudioData[1] = truetotal;
	if (rewrite == true) {
		audio_read_warning(total-truetotal);
		goto start;
	}
	AudioData[1] = truetotal;
}

bool audio_open() {
	system("cls");
	gotoxy(24, 20);
	color_out("       正在读取音频库                         ", 1);
	Sleep(_rand(50) + 50);
	pogress_bar();
	Sleep(_rand(50) + 50);
	pogress_bar();
	Sleep(_rand(50) + 50);
start:
	hide_mouse();
	short total, truetotal = 0;
	bool rewrite = false;
	string st;
	INIReader reader("audio.ini");
	if (reader.ParseError() < 0) {
		audio_read_wrong();
		goto start;
	}

	total = (short)reader.GetInteger("audio", "total", -1);
	if (total == -1) {
		audio_read_wrong();
		goto start;
	}
	AudioData[2] = (short)reader.GetInteger("audio", "choice", -1);
	if (AudioData[2] == -1) {
		audio_read_wrong();
		goto start;
	}

	if (total > 10) {
		total = 10;
		rewrite = true;
	}

	if (AudioData[2] < 1) {
		AudioData[2] = 1;
		rewrite = true;
	}

	short i = 0;
	while (true) {
		if (i + 1 > total)
			break;
		else
			i++;
		st = reader.Get("audio", to_string(i), "UNKNOWN");
		if (st == "UNKNOWN") {
			rewrite = true;
		}
		else if (Integrity_check(st) == false) {
			rewrite = true;
		}
		else {
			truetotal++;
			AudioName[truetotal].name = st;
		}
	}
	if (truetotal < 1)
	{
		audio_no_warning();
		AudioSettingsData[3] = 0;
		return false;
	}
	AudioData[1] = truetotal;
	if (rewrite == true) {
		audio_read_warning(total - truetotal);
		goto start;
	}
	AudioData[1] = truetotal;
	return true;
}

void audio_DIY_menu() {
	main_menu_video();
	hide_mouse();
	SetConsoleTitle(TEXT("贪吃蛇    自定义路径"));
	gotoxy(4, 26);
	c_out(" Tips:按下W/S切换选项,C保存并返回上一级                                   ", 2);
	short choose = AudioData[2];
	short id = 14;
	bool temp = true;
	int x = 23, y = 12;
	int y1 = 10;
	int x1 = 33;
	help_print(0, 1);

	shade_out(" 自定义路径 ", x1, y1, 50, false);
	shade_out("当前选定:", x, y + 1, 50,false);
	short k = 1;
	for (short i = choose;i <= (short)min(7, AudioData[1]);i++) {
		shade_out(AudioName[i].name, x + 10, y + k, 50, false);
		k++;
	}
	for (int i = min(7, AudioData[1])+1;i <= 7;i++) {
		gotoxy(x + 10, y + i);
		cout << "                    ";
	}
	while (temp)
	{
		gotoxy(x1, y1 + 1);
		cout << "    ("<<AudioData[2] << "/" << AudioData[1] << ")";
		game_state();
		Sleep(200);
		bool redraw = false;
		short z = 1;
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN('C') || KEY_DOWN(VK_BACK) || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if ((KEY_DOWN('W') || KEY_DOWN(VK_UP)) && choose !=1 )
				{
					choose--;
					AudioData[2]--;
					redraw = true;
					break;
				}
				if ((KEY_DOWN('S') || KEY_DOWN(VK_DOWN)) && choose != AudioData[1])
				{
					choose++;
					AudioData[2]++;
					redraw = true;
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
		if (redraw == true) {
			z = 1;
			int i = AudioData[2];
			while (true) {
				gotoxy(x + 10, y + z);
				c_out(AudioName[i].name, 1);
				for (int j = 1;j <= 20 - AudioName[i].name.size();j++)
					cout << " ";
				i++, z++;
				if (z > 7 || i > AudioData[1])
					break;
			}
			for ( i = z;i <= 7;i++) {
				gotoxy(x + 10, y + i);
				cout << "                    ";
			}
		}
	}

	help_print(0, 0);
}

void audio_settings() {
	if (AudioSettingsData[3] == 0) {
		wrong("                未开启声音              ", "           进入自定义需开启声音         ", "                                        ", "", "           Y:开启      N:取消           ");
		while (true)
		{
			if (KEY_DOWN('Y'))
			{
				playsound(2);
				if (audio_open() == true) {
					audio_DIY_menu();
					AudioSettingsData[3] = 1;
				}
				break;
			}
			if (KEY_DOWN('N'))
			{
				playsound(3);
				break;
			}
		}
	}
	else {
		audio_DIY_menu();
	}
	return;
}
